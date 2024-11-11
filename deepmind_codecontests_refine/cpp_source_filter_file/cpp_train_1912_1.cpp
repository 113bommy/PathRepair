#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const string LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)2e9 + 7;
const long long LINF = (long long)9e18 + 7;
bool insert(int k, int x1, int x2) { return (k >= x1 && k <= x2); }
const int MAXN = 60007;
const int P1 = 239017;
const int P2 = 353251;
const long long MOD = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const int l = 20;
int n, m, ans = INF;
char c[107][10007];
vector<int> q[107];
int get(int a, int b) { return min(abs(a - b), abs(m - abs(a - b))); }
const bool is_testing = 0;
int main() {
  srand(time(NULL));
  if (is_testing) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  }
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> c[i][j];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      if (c[i][j] == '1') q[i].push_back(j);
    if (q[i].size() == 0) cout << -1, exit(0);
  }
  for (int i = 0; i < m; i++) {
    int res = 0;
    for (int j = 0; j < n; j++) {
      int now = INF;
      now = min(now, get(i, q[j][0]));
      now = min(now, get(i, q[j].back()));
      int l = 0, r = q[j].size();
      while (l + 1 < r) {
        int m = (l + r) / 2;
        if (q[j][m] < i)
          l = m;
        else
          r = m;
      }
      now = min(now, get(i, q[j][l]));
      if (l < (int)q[j].size() - 1) now = min(now, get(i, q[j][l + 1]));
      res += n;
    }
    ans = min(ans, res);
  }
  cout << ans;
}
