#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
const int INF = 0x3f3f3f3f;
const long long MOD = 1e9 + 7;
int n, m, k, f;
char s[MAXN][MAXN];
bool check(int x, int y, int f, char w) {
  int res = 1;
  if (f) {
    res &= s[x][y - 1] != w;
    res &= s[x - 1][y] != w;
    res &= s[x - 1][y + 1] != w;
  } else {
    res &= s[x][y - 1] != w;
    res &= s[x + 1][y - 1] != w;
    res &= s[x - 1][y] != w;
  }
  return res;
}
void work(int x, int y, int f) {
  for (char w = 'a'; w <= 'z'; w++) {
    if (check(x, y, f, w)) {
      s[x][y] = w;
      if (f)
        s[x][y + 1] = w;
      else
        s[x + 1][y] = w;
      return;
    }
  }
}
bool ok(int n, int m, int k) {
  k -= m >> 1;
  if (!(k >= 0 && k % 2 == 0)) return false;
  for (int j = 1; j <= m; j += 2) work(1, j, 1);
  for (int i = 2; i <= n; i += 2) {
    for (int j = 1; j <= m; j += 2) {
      if (k >= 2) {
        k -= 2;
        work(i, j, 1), work(i + 1, j, 1);
      } else {
        work(i, 1, 0), work(i, j + 1, 0);
      }
    }
  }
  return true;
}
inline void run() {
  cin >> n >> m >> k;
  for (int i = (int)(0); i <= (int)(105); i++)
    for (int j = (int)(0); j <= (int)(105); j++) s[i][j] = '?';
  int c = 0, d = 0;
  if (m & 1) swap(n, m), k = n * m / 2 - k, c = 1;
  if (n & 1)
    f = ok(n, m, k), d = 1;
  else
    f = k % 2 == 0;
  if (!f) return cout << ("NO") << '\n', void();
  cout << ("YES") << '\n';
  if (d) {
    if (c) {
      for (int j = (int)(1); j <= (int)(m); j++) {
        for (int i = (int)(1); i <= (int)(n); i++) cout << s[i][j];
        cout << '\n';
      }
    } else {
      for (int i = (int)(1); i <= (int)(n); i++) {
        for (int j = (int)(1); j <= (int)(m); j++) cout << s[i][j];
        cout << '\n';
      }
    }
  } else {
    for (int i = 1; i <= n; i += 2) {
      for (int j = 1; j <= m; j += 2) {
        if (k >= 2) {
          k -= 2;
          work(i, j, 1), work(i + 1, j, 1);
        } else {
          work(i, j, 0), work(i, j + 1, 0);
        }
      }
    }
    for (int i = (int)(1); i <= (int)(n); i++) {
      for (int j = (int)(1); j <= (int)(m); j++) cout << s[i][j];
      cout << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int T;
  for (cin >> T; T--;) run();
  return 0;
}
