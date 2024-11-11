#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:210000000")
using namespace std;
const int INF = 2e9 + 9;
const long long INF1 = 8e18 + 9;
const long long MAXN = 1e6 + 7;
const long long MAXN1 = 1 << 11;
const long long MAXN2 = 1e7 + 9;
const long long MOD = 998244353;
const long long MOD1 = 1e9 + 9;
const long long ALPH = 50;
const long long PW1 = 239;
const long long PW2 = 199;
const long long PW3 = 193;
const long long PW4 = 117;
const long double EPS = 1e-9;
const long long BLOCK = 3684;
const long long BLOCK1 = 1 << 9;
void solve();
signed main() {
  srand('a' + 'l' + 'e' + 'x' + 'X' + '5' + '1' + '2');
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q = 1;
  if (0) cin >> q;
  while (q--) solve();
}
int ans[MAXN1][MAXN1];
void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<pair<pair<int, int>, pair<int, int>>> v;
  for (int i = 0; i < q; ++i) {
    int t, a, b, c;
    cin >> t;
    if (t == 1 || t == 2) {
      cin >> a;
      v.emplace_back(make_pair(t, a), make_pair(INF, INF));
    } else {
      cin >> a >> b >> c;
      v.emplace_back(make_pair(t, a), make_pair(b, c));
    }
  }
  reverse(v.begin(), v.end());
  for (auto &i : v) {
    if (i.first.first == 1) {
      for (int j = n; j > 1; --j) {
        swap(ans[i.first.second][j], ans[i.first.second][j - 1]);
      }
    } else if (i.first.first == 2) {
      for (int j = m; j > 1; --j) {
        swap(ans[j][i.first.second], ans[j - 1][i.first.second]);
      }
    } else {
      ans[i.first.second][i.second.first] = i.second.second;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }
}
