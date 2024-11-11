#include <bits/stdc++.h>
using namespace std;
inline int add(int a, int b) {
  int c = (a % 1000000007) + (b % 1000000007);
  if (c >= 1000000007) c -= 1000000007;
  return c;
}
inline int mul(int a, int b) {
  return ((a % 1000000007) * 1ll * (b % 1000000007)) % 1000000007;
}
inline int sub(int a, int b) {
  int c = (a % 1000000007) - (b % 1000000007);
  if (c < 0) c += 1000000007;
  return c;
}
const int nax = 1000 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void test_case();
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    test_case();
  }
  return 0;
}
int n, m, k;
int a[nax][nax];
vector<string> s;
int col = 1;
vector<int> ans;
int cnt = 0LL;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
void dfs(int i, int j) {
  a[i][j] = col;
  for (int x = 0; x < 4; ++x) {
    int ni = i + dx[x];
    int nj = j + dy[x];
    if (ni >= 0 && ni < n && nj >= 0 && nj < m && s[ni][nj] == '.' &&
        a[ni][nj] == 0) {
      dfs(ni, nj);
    }
    if (ni >= 0 && ni < n && nj >= 0 && nj < m && s[ni][nj] == '*' &&
        a[ni][nj] == 0) {
      ++cnt;
    }
  }
}
void test_case() {
  cin >> n >> m >> k;
  s = vector<string>(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 0 && s[i][j] == '*') {
        cnt = 0LL;
        dfs(i, j);
        ans.push_back(cnt);
        ++col;
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    cout << ans[a[x][y] - 1] << '\n';
  }
}
