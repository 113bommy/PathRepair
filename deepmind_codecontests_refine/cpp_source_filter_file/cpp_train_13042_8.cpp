#include <bits/stdc++.h>
template <class T>
inline void read(T &x) {
  x = 0;
  register char c = getchar();
  register bool f = 0;
  while (!isdigit(c)) f ^= c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  if (f) x = -x;
}
using namespace std;
int t, n, m;
struct node {
  int p[7];
} e[100005];
string s[1000];
int cnt;
void solve(int x, int y) {
  if (x + 1 == n) {
    s[x][y] ^= 1;
    s[x + 1][y] ^= 1;
    s[x + 1][y - 1] ^= 1;
    e[++cnt].p[1] = x;
    e[cnt].p[2] = y;
    e[cnt].p[3] = x + 1;
    e[cnt].p[4] = y;
    e[cnt].p[5] = x + 1;
    e[cnt].p[6] = y - 1;
    return;
  } else {
    s[x][y] ^= 1;
    s[x][y + 1] ^= 1;
    s[x + 1][y] ^= 1;
    e[++cnt].p[1] = x;
    e[cnt].p[2] = y;
    e[cnt].p[3] = x;
    e[cnt].p[4] = y + 1;
    e[cnt].p[5] = x + 1;
    e[cnt].p[6] = y;
    return;
  }
}
void solve2(int x, int y) {
  if (s[x][y] == '0' && s[x + 1][y] == '0') {
    return;
  }
  if (s[x][y] == '0' && s[x + 1][y] == '1') {
    s[x + 1][y] ^= 1;
    s[x][y + 1] ^= 1;
    s[x + 1][y + 1] ^= 1;
    e[++cnt].p[1] = x + 1;
    e[cnt].p[2] = y;
    e[cnt].p[3] = x;
    e[cnt].p[4] = y + 1;
    e[cnt].p[5] = x + 1;
    e[cnt].p[6] = y + 1;
    return;
  }
  if (s[x][y] == '1' && s[x + 1][y] == '0') {
    s[x][y] ^= 1;
    s[x][y + 1] ^= 1;
    s[x + 1][y + 1] ^= 1;
    e[++cnt].p[1] = x;
    e[cnt].p[2] = y;
    e[cnt].p[3] = x;
    e[cnt].p[4] = y + 1;
    e[cnt].p[5] = x + 1;
    e[cnt].p[6] = y + 1;
    return;
  }
  if (s[x][y] == '1' && s[x + 1][y] == '1') {
    s[x][y] ^= 1;
    s[x + 1][y] ^= 1;
    s[x][y + 1] ^= 1;
    e[++cnt].p[1] = x;
    e[cnt].p[2] = y;
    e[cnt].p[3] = x;
    e[cnt].p[4] = y + 1;
    e[cnt].p[5] = x + 1;
    e[cnt].p[6] = y;
  }
}
void solve3(int x, int y) {
  int num, flag;
  while (1) {
    num = 0;
    flag = 0;
    for (int i = x; i <= x + 1; i++) {
      for (int j = y; j <= y + 1; j++) {
        if (s[i][j] == '1') {
          num++;
        }
      }
    }
    if (num == 0) {
      break;
    }
    if (num == 1 || num == 2 || num == 4) {
      for (int i = x; i <= x + 1; i++) {
        for (int j = y; j <= y + 1; j++) {
          if (s[i][j] == '1') {
            if (i == x && j == y) {
              s[i][j] ^= 1;
              s[i][j + 1] ^= 1;
              s[i + 1][j] ^= 1;
              e[++cnt].p[1] = i;
              e[cnt].p[2] = j;
              e[cnt].p[3] = i;
              e[cnt].p[4] = j + 1;
              e[cnt].p[5] = i + 1;
              e[cnt].p[6] = j;
            }
            if (i == x && j == y + 1) {
              s[i][j] ^= 1;
              s[i][j - 1] ^= 1;
              s[i + 1][j] ^= 1;
              e[++cnt].p[1] = i;
              e[cnt].p[2] = j - 1;
              e[cnt].p[3] = i;
              e[cnt].p[4] = j;
              e[cnt].p[5] = i + 1;
              e[cnt].p[6] = j;
            }
            if (i == x + 1 && j == y) {
              s[i][j] ^= 1;
              s[i - 1][j] ^= 1;
              s[i][j + 1] ^= 1;
              e[++cnt].p[1] = i - 1;
              e[cnt].p[2] = j;
              e[cnt].p[3] = i;
              e[cnt].p[4] = j;
              e[cnt].p[5] = i;
              e[cnt].p[6] = j + 1;
            }
            if (i == x + 1 && j == y + 1) {
              s[i - 1][j] ^= 1;
              s[i][j - 1] ^= 1;
              s[i][j] ^= 1;
              e[++cnt].p[1] = i - 1;
              e[cnt].p[2] = j;
              e[cnt].p[3] = i;
              e[cnt].p[4] = j - 1;
              e[cnt].p[5] = i;
              e[cnt].p[6] = j;
            }
            flag = 1;
            break;
          }
        }
        if (flag == 1) {
          break;
        }
      }
    }
    if (num == 3) {
      for (int i = x; i <= x + 1; i++) {
        for (int j = y; j <= y + 1; j++) {
          if (s[i][j] == '0') {
            if (i == x && j == y) {
              s[i + 1][j] ^= 1;
              s[i][j + 1] ^= 1;
              s[i + 1][j + 1] ^= 1;
              e[++cnt].p[1] = i;
              e[cnt].p[2] = j + 1;
              e[cnt].p[3] = i + 1;
              e[cnt].p[4] = j;
              e[cnt].p[5] = i + 1;
              e[cnt].p[6] = j + 1;
            }
            if (i == x && j == y + 1) {
              s[i][j - 1] ^= 1;
              s[i + 1][j] ^= 1;
              s[i + 1][j - 1] ^= 1;
              e[++cnt].p[1] = i;
              e[cnt].p[2] = j - 1;
              e[cnt].p[3] = i + 1;
              e[cnt].p[4] = j;
              e[cnt].p[5] = i + 1;
              e[cnt].p[6] = j - 1;
            }
            if (i == x + 1 && j == y) {
              s[i - 1][j] ^= 1;
              s[i][j + 1] ^= 1;
              s[i - 1][j + 1] ^= 1;
              e[++cnt].p[1] = i - 1;
              e[cnt].p[2] = j;
              e[cnt].p[3] = i;
              e[cnt].p[4] = j + 1;
              e[cnt].p[5] = i - 1;
              e[cnt].p[6] = j + 1;
            }
            if (i == x + 1 && j == y + 1) {
              s[i - 1][j] ^= 1;
              s[i][j - 1] ^= 1;
              s[i - 1][j - 1] ^= 1;
              e[++cnt].p[1] = i - 1;
              e[cnt].p[2] = j;
              e[cnt].p[3] = i;
              e[cnt].p[4] = j - 1;
              e[cnt].p[5] = i - 1;
              e[cnt].p[6] = j - 1;
            }
            flag = 1;
            break;
          }
        }
        if (flag == 1) {
          break;
        }
      }
    }
  }
}
int main() {
  cin >> t;
  while (t--) {
    cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }
    for (int i = 0; i < n - 2; i++) {
      for (int j = 0; j < m; j++) {
        if (s[i][j] == '1') {
          solve(i, j);
        }
      }
    }
    for (int j = 0; j < m - 2; j++) {
      solve2(n - 2, j);
    }
    solve3(n - 2, m - 2);
    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++) {
      for (int j = 1; j <= 6; j++) {
        cout << e[i].p[j] + 1 << " ";
      }
      cout << endl;
    }
  }
  return 0;
}
