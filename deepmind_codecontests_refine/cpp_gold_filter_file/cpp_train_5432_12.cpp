#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 51;
long long a[MAXN][MAXN];
long long b[MAXN][MAXN];
bool dpa[MAXN][MAXN][MAXN][MAXN];
bool dpb[MAXN][MAXN][MAXN][MAXN];
void ask(long long x1, long long y1, long long x2, long long y2) {
  cout << "?";
  cout << " " << x1;
  cout << " " << y1;
  cout << " " << x2;
  cout << " " << y2;
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long n;
  long long ans;
  cin >> n;
  for (long long i = 0; i < MAXN; i++)
    for (long long j = 0; j < MAXN; j++) a[i][j] = 0;
  a[1][1] = 1;
  ask(1, 2, 3, 2);
  cin >> ans;
  a[3][2] = (a[1][2] + 1 + ans) % 2;
  ask(2, 1, 3, 2);
  cin >> ans;
  a[2][1] = (a[3][2] + 1 + ans) % 2;
  ask(1, 1, 2, 2);
  cin >> ans;
  a[2][2] = (a[1][1] + 1 + ans) % 2;
  ask(1, 1, 3, 1);
  cin >> ans;
  a[3][1] = (a[1][1] + 1 + ans) % 2;
  for (long long i = 4; i <= n; i++) {
    for (long long j = 1; j <= 2; j++) {
      ask(i - 2, j, i, j);
      cin >> ans;
      a[i][j] = (a[i - 2][j] + 1 + ans) % 2;
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 3; j <= n; j++) {
      if (i == n && j == n) break;
      ask(i, j - 2, i, j);
      cin >> ans;
      a[i][j] = (a[i][j - 2] + 1 + ans) % 2;
    }
  }
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      b[i][j] = (a[i][j] + (i + j) % 2) % 2;
    }
  }
  bool a_correct = true;
  long long x1, y1, x2, y2;
  x1 = 1;
  x2 = n;
  y1 = 1;
  y2 = n;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= n; j++) {
      dpa[i][j][i][j] = true;
      dpb[i][j][i][j] = true;
      if (j + 1 <= n) {
        dpa[i][j][i][j + 1] = (a[i][j] == a[i][j + 1]);
        dpb[i][j][i][j + 1] = (b[i][j] == b[i][j + 1]);
      }
      if (i + 1 <= n) {
        dpa[i][j][i + 1][j] = (a[i][j] == a[i + 1][j]);
        dpb[i][j][i + 1][j] = (b[i][j] == b[i + 1][j]);
      }
    }
  }
  for (long long len = 2; len <= (2 * n - 2); len++) {
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= n; j++) {
        for (long long down = 0; down <= len; down++) {
          long long right = (len - down);
          if (i + down > n || j + right > n) continue;
          dpa[i][j][i + down][j + right] = false;
          dpb[i][j][i + down][j + right] = false;
          vector<pair<long long, long long> > steps1 = {{i, j + 1}, {i + 1, j}};
          vector<pair<long long, long long> > steps2 = {
              {i + down, j + right - 1}, {i + down - 1, j + right}};
          for (auto s1 : steps1) {
            for (auto s2 : steps2) {
              if (s1.first > s2.first || s1.second > s2.second) continue;
              if (dpa[s1.first][s1.second][s2.first][s2.second])
                if (a[i][j] == a[i + down][j + right])
                  dpa[i][j][i + down][j + right] = true;
              if (dpb[s1.first][s1.second][s2.first][s2.second])
                if (b[i][j] == b[i + down][j + right])
                  dpb[i][j][i + down][j + right] = true;
            }
          }
          if (dpa[i][j][i + down][j + right] !=
              dpb[i][j][i + down][j + right]) {
            x1 = i;
            y1 = j;
            x2 = i + down;
            y2 = j + right;
          }
        }
      }
    }
  }
  ask(x1, y1, x2, y2);
  cin >> ans;
  if ((ans == 1) && !dpa[x1][y1][x2][y2]) a_correct = false;
  if ((ans == 0) && dpa[x1][y1][x2][y2]) a_correct = false;
  cout << "!" << endl;
  if (a_correct) {
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= n; j++) cout << a[i][j];
      cout << endl;
    }
  } else {
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= n; j++) cout << b[i][j];
      cout << endl;
    }
  }
}
