#include <bits/stdc++.h>
const char dl = '\n';
const long double eps = 0.00000001;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const double PI = 3.141592653589793238463;
const long double pi = 4 * atan(1.0);
using namespace std;
void debug() { cout << endl; }
template <typename H, typename... T>
void debug(H p, T... t) {
  std::cout << p << " ";
  debug(t...);
}
string second, t;
long long ans;
int n, m, k, q;
int cnta[3], cntb[3];
vector<int> row[600], col[600];
int a[600][600], b[600][600], c[600][600];
int main() {
  fflush(stdin);
  cout << fixed, cout.precision(18);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, j;
  cin >> n >> m;
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) cin >> a[i][j], cnta[a[i][j]]++;
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j) cin >> b[i][j], cnta[b[i][j]]++;
  for (i = 0; i < n; ++i)
    for (j = 0; j < m; ++j)
      if (a[i][j] != b[i][j])
        col[j].push_back(i), row[i].push_back(j), c[i][j] = 1;
  for (i = 0; i < n; ++i) {
    int sz = (int)col[i].size();
    if (sz % 2 != 0) return cout << "No", 0;
  }
  for (i = 0; i < m; ++i) {
    int sz = (int)row[i].size();
    if (sz % 2 != 0) return cout << "No", 0;
  }
  cout << "Yes";
}
