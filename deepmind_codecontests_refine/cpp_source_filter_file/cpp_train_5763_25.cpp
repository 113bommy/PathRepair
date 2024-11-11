#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
using ll = long long int;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
using mii = map<int, int>;
using pii = pair<int, int>;
const int inf = 1e9;
const ll infL = (ll)1e18;
const int N = 100005;
const ll mod = (ll)1e9 + 7;
const ll mod2 = 998244353LL;
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vvi arr(n, vi(m, 0));
  vector<ll> row(n, 0), col(m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      row[i] += arr[i][j];
      col[j] += arr[i][j];
    }
  }
  vector<ll> ansRow(n + 1, 0), ansCol(m + 1, 0);
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < n; j++) {
      ll add = 0;
      if (j >= i)
        add = (j - i) * 4 + 2;
      else
        add = (i - j - 1) * 4 + 2;
      ansRow[i] += add * add * row[j];
    }
  }
  for (int j = 0; j <= m; j++) {
    for (int i = 0; i < m; i++) {
      ll add = 0;
      if (i >= j)
        add = (i - j) * 4 + 2;
      else
        add = (j - i - 1) * 4 + 2;
      ansCol[j] += add * add * col[i];
    }
  }
  ll maxRow = 1e18, maxCol = 1e18;
  for (int i = 0; i <= n; i++) maxRow = min(maxRow, ansRow[i]);
  for (int j = 0; j <= m; j++) maxCol = min(maxCol, ansCol[j]);
  cout << maxRow + maxCol << '\n';
  for (int i = 0; i <= n; i++) {
    if (maxRow == ansRow[i]) {
      cout << i << ' ';
      break;
    }
  }
  for (int j = 0; j <= m; j++) {
    if (maxCol == ansCol[j]) {
      cout << j << ' ';
      break;
    }
  }
  return 0;
}
