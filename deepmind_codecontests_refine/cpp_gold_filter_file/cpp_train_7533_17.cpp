#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const int N = (1 << 24);
int n, m, a, b, c;
char mp[107][107];
bool check(int x, int y, char c) {
  if (x == 0 || y == 0) return 0;
  return mp[x][y] == c;
}
int main() {
  cin >> n >> m >> a >> b >> c;
  int n1 = n / 2, m1 = m / 2;
  if ((n & 1) && (m & 1)) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  } else if (!(n & 1) && !(m & 1)) {
    for (int i = int(1); i <= int(n1); ++i)
      for (int j = int(1); j <= int(m1); ++j) {
        if (c) {
          c--;
          for (int k = int(0); k <= int(25); ++k) {
            char cc = (char)(k + 'a');
            if (check(2 * i, 2 * j - 2, cc) ||
                check(2 * i - 1, 2 * j - 2, cc) ||
                check(2 * i - 2, 2 * j - 1, cc) || check(2 * i - 2, 2 * j, cc))
              continue;
            mp[2 * i][2 * j] = mp[2 * i - 1][2 * j] = mp[2 * i][2 * j - 1] =
                mp[2 * i - 1][2 * j - 1] = cc;
            break;
          }
        } else if (a >= 2) {
          a -= 2;
          for (int k = int(0); k <= int(25); ++k) {
            char cc = (char)(k + 'a');
            if (check(2 * i - 2, 2 * j - 1, cc) ||
                check(2 * i - 2, 2 * j, cc) || check(2 * i - 1, 2 * j - 2, cc))
              continue;
            mp[2 * i - 1][2 * j - 1] = mp[2 * i - 1][2 * j] = cc;
            break;
          }
          for (int k = int(0); k <= int(25); ++k) {
            char cc = (char)(k + 'a');
            if (check(2 * i - 1, 2 * j - 1, cc) ||
                check(2 * i - 1, 2 * j, cc) || check(2 * i, 2 * j - 2, cc))
              continue;
            mp[2 * i][2 * j - 1] = mp[2 * i][2 * j] = cc;
            break;
          }
        } else if (b >= 2) {
          b -= 2;
          for (int k = int(0); k <= int(25); ++k) {
            char cc = (char)(k + 'a');
            if (check(2 * i - 2, 2 * j - 1, cc) ||
                check(2 * i - 1, 2 * j - 2, cc) || check(2 * i, 2 * j - 2, cc))
              continue;
            mp[2 * i - 1][2 * j - 1] = mp[2 * i][2 * j - 1] = cc;
            break;
          }
          for (int k = int(0); k <= int(25); ++k) {
            char cc = (char)(k + 'a');
            if (check(2 * i - 2, 2 * j, cc) ||
                check(2 * i - 1, 2 * j - 1, cc) || check(2 * i, 2 * j - 1, cc))
              continue;
            mp[2 * i - 1][2 * j] = mp[2 * i][2 * j] = cc;
            break;
          }
        } else {
          puts("IMPOSSIBLE");
          return 0;
        }
      }
  } else if ((n & 1) && !(m & 1)) {
    for (int i = int(1); i <= int(n1); ++i)
      for (int j = int(1); j <= int(m1); ++j) {
        if (c) {
          c--;
          for (int k = int(0); k <= int(25); ++k) {
            char cc = (char)(k + 'a');
            if (check(2 * i, 2 * j - 2, cc) ||
                check(2 * i - 1, 2 * j - 2, cc) ||
                check(2 * i - 2, 2 * j - 1, cc) || check(2 * i - 2, 2 * j, cc))
              continue;
            mp[2 * i][2 * j] = mp[2 * i - 1][2 * j] = mp[2 * i][2 * j - 1] =
                mp[2 * i - 1][2 * j - 1] = cc;
            break;
          }
        } else if (b >= 2) {
          b -= 2;
          for (int k = int(0); k <= int(25); ++k) {
            char cc = (char)(k + 'a');
            if (check(2 * i - 2, 2 * j - 1, cc) ||
                check(2 * i - 1, 2 * j - 2, cc) || check(2 * i, 2 * j - 2, cc))
              continue;
            mp[2 * i - 1][2 * j - 1] = mp[2 * i][2 * j - 1] = cc;
            break;
          }
          for (int k = int(0); k <= int(25); ++k) {
            char cc = (char)(k + 'a');
            if (check(2 * i - 2, 2 * j, cc) ||
                check(2 * i - 1, 2 * j - 1, cc) || check(2 * i, 2 * j - 1, cc))
              continue;
            mp[2 * i - 1][2 * j] = mp[2 * i][2 * j] = cc;
            break;
          }
        } else if (a >= 2) {
          a -= 2;
          for (int k = int(0); k <= int(25); ++k) {
            char cc = (char)(k + 'a');
            if (check(2 * i - 2, 2 * j - 1, cc) ||
                check(2 * i - 2, 2 * j, cc) || check(2 * i - 1, 2 * j - 2, cc))
              continue;
            mp[2 * i - 1][2 * j - 1] = mp[2 * i - 1][2 * j] = cc;
            break;
          }
          for (int k = int(0); k <= int(25); ++k) {
            char cc = (char)(k + 'a');
            if (check(2 * i - 1, 2 * j - 1, cc) ||
                check(2 * i - 1, 2 * j, cc) || check(2 * i, 2 * j - 2, cc))
              continue;
            mp[2 * i][2 * j - 1] = mp[2 * i][2 * j] = cc;
            break;
          }
        } else {
          puts("IMPOSSIBLE");
          return 0;
        }
      }
    for (int j = int(1); j <= int(m1); ++j) {
      if (a >= 1) {
        a--;
        for (int k = int(0); k <= int(25); ++k) {
          char cc = (char)(k + 'a');
          if (check(n, 2 * j - 2, cc) || check(n - 1, 2 * j - 1, cc) ||
              check(n - 1, 2 * j, cc))
            continue;
          mp[n][2 * j - 1] = mp[n][2 * j] = cc;
          break;
        }
      } else {
        puts("IMPOSSIBLE");
        return 0;
      }
    }
  } else {
    for (int i = int(1); i <= int(n1); ++i)
      for (int j = int(1); j <= int(m1); ++j) {
        if (c) {
          c--;
          for (int k = int(0); k <= int(25); ++k) {
            char cc = (char)(k + 'a');
            if (check(2 * i, 2 * j - 2, cc) ||
                check(2 * i - 1, 2 * j - 2, cc) ||
                check(2 * i - 2, 2 * j - 1, cc) || check(2 * i - 2, 2 * j, cc))
              continue;
            mp[2 * i][2 * j] = mp[2 * i - 1][2 * j] = mp[2 * i][2 * j - 1] =
                mp[2 * i - 1][2 * j - 1] = cc;
            break;
          }
        } else if (a >= 2) {
          a -= 2;
          for (int k = int(0); k <= int(25); ++k) {
            char cc = (char)(k + 'a');
            if (check(2 * i - 2, 2 * j - 1, cc) ||
                check(2 * i - 2, 2 * j, cc) || check(2 * i - 1, 2 * j - 2, cc))
              continue;
            mp[2 * i - 1][2 * j - 1] = mp[2 * i - 1][2 * j] = cc;
            break;
          }
          for (int k = int(0); k <= int(25); ++k) {
            char cc = (char)(k + 'a');
            if (check(2 * i - 1, 2 * j - 1, cc) ||
                check(2 * i - 1, 2 * j, cc) || check(2 * i, 2 * j - 2, cc))
              continue;
            mp[2 * i][2 * j - 1] = mp[2 * i][2 * j] = cc;
            break;
          }
        } else if (b >= 2) {
          b -= 2;
          for (int k = int(0); k <= int(25); ++k) {
            char cc = (char)(k + 'a');
            if (check(2 * i - 2, 2 * j - 1, cc) ||
                check(2 * i - 1, 2 * j - 2, cc) || check(2 * i, 2 * j - 2, cc))
              continue;
            mp[2 * i - 1][2 * j - 1] = mp[2 * i][2 * j - 1] = cc;
            break;
          }
          for (int k = int(0); k <= int(25); ++k) {
            char cc = (char)(k + 'a');
            if (check(2 * i - 2, 2 * j, cc) ||
                check(2 * i - 1, 2 * j - 1, cc) || check(2 * i, 2 * j - 1, cc))
              continue;
            mp[2 * i - 1][2 * j] = mp[2 * i][2 * j] = cc;
            break;
          }
        } else {
          puts("IMPOSSIBLE");
          return 0;
        }
      }
    for (int i = int(1); i <= int(n1); ++i) {
      if (b >= 1) {
        b--;
        for (int k = int(0); k <= int(25); ++k) {
          char cc = (char)(k + 'a');
          if (check(2 * i - 2, m, cc) || check(2 * i - 1, m - 1, cc) ||
              check(2 * i, m - 1, cc))
            continue;
          mp[2 * i - 1][m] = mp[2 * i][m] = cc;
          break;
        }
      } else {
        puts("IMPOSSIBLE");
        return 0;
      }
    }
  }
  for (int i = int(1); i <= int(n); ++i) {
    for (int j = int(1); j <= int(m); ++j) printf("%c", mp[i][j]);
    puts("");
  }
}
