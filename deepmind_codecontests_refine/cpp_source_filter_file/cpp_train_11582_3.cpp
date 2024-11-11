#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e3 + 7;
const int inf = INT_MAX / 2;
const long long INF = LLONG_MAX / 3;
const int MOD = 998244353;
const long double eps = 1e-6;
const string cars[] = {"🚗", "🚕", "🚙"};
int n, m;
char a[N][N];
int r[N], c[N], b[N][N], pr[N][N], pc[N][N];
char used[N][N];
void dfs(int x, int y) {
  used[x][y] = 1;
  if (!used[x + 1][y] && a[x + 1][y] == '#') {
    dfs(x + 1, y);
  }
  if (!used[x - 1][y] && a[x - 1][y] == '#') {
    dfs(x - 1, y);
  }
  if (!used[x][y + 1] && a[x][y + 1] == '#') {
    dfs(x, y + 1);
  }
  if (!used[x][y - 1] && a[x][y - 1] == '#') {
    dfs(x, y - 1);
  }
}
signed main() {
  cout << fixed << setprecision(9);
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    vector<char> s;
    s.push_back(a[i][1]);
    for (int j = 2; j <= m; j++) {
      if (a[i][j] != s.back()) {
        s.push_back(a[i][j]);
      }
    }
    if (int((s).size()) == 1 && s.back() == '.') {
      r[i] = 0;
    } else if (count(s.begin(), s.end(), '#') == 1) {
      r[i] = 1;
    } else {
      r[i] = 2;
    }
  }
  for (int j = 1; j <= m; j++) {
    vector<char> s;
    s.push_back(a[1][j]);
    for (int i = 2; i <= n; i++) {
      if (a[i][j] != s.back()) {
        s.push_back(a[i][j]);
      }
    }
    if (int((s).size()) == 1 && s.back() == '.') {
      c[j] = 0;
    } else if (count(s.begin(), s.end(), '#') == 1) {
      c[j] = 1;
    } else {
      c[j] = 2;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (r[i] == 0) {
      for (int j = 1; j <= m; j++) {
        if (c[j] == 0) {
          b[i][j] = 1;
        }
      }
    } else if (r[i] == 1) {
      for (int j = 1; j <= m; j++) {
        if (a[i][j] == '#') {
          b[i][j] = 1;
          break;
        }
      }
      for (int j = m; j >= 1; j--) {
        if (a[i][j] == '#') {
          b[i][j] = 1;
          break;
        }
      }
    }
  }
  for (int j = 1; j <= m; j++) {
    if (c[j] == 0) {
      for (int i = 1; i <= n; i++) {
        if (r[i] == 0) {
          b[i][j] = 1;
        }
      }
    } else if (c[j] == 1) {
      for (int i = 1; i <= n; i++) {
        if (a[i][j] == '#') {
          b[i][j] = 1;
          break;
        }
      }
      for (int i = n; i >= 1; i--) {
        if (a[i][j] == '#') {
          b[i][j] = 1;
          break;
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pr[i][j] = pr[i][j - 1] + b[i][j];
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      pc[i][j] = pc[i - 1][j] + b[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (pr[i][m] == 0) {
      return cout << "-1\n", 0;
    }
  }
  for (int j = 1; j <= m; j++) {
    if (pc[n][j] == 0) {
      return cout << "-1\n", 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '.') {
        if (a[i][j + 1] == '#' && pr[i][j] > 0) {
          return cout << "-1\n", 0;
        }
        if (a[i][j - 1] == '#' && pr[i][m] - pr[i][j - 1] > 0) {
          return cout << "-1\n", 0;
        }
        if (a[i + 1][j] == '#' && pc[i][j] > 0) {
          return cout << "-1\n", 0;
        }
        if (a[i - 1][j] == '#' && pc[n][j] - pr[i - 1][j] > 0) {
          return cout << "-1\n", 0;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!used[i][j] && a[i][j] == '#') {
        dfs(i, j);
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
