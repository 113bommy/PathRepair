#include <bits/stdc++.h>
using namespace std;
const long long N = (long long)1e5 + 77;
const long long inf = (long long)1e18 + 7;
const long long mod = (long long)1e9 + 7;
const long double pi = acos(-1);
class ASkyscrapers {
 public:
  void solve(std::istream& cin, std::ostream& cout) {
    int n, m, x, y, a[1001][1001], ans[1001][1001];
    cin >> n >> m;
    vector<int> c[2002];
    for (int i = 0; i < (int)n; i++) {
      for (int j = 0; j < (int)m; j++) {
        cin >> a[i][j];
        c[i].emplace_back(a[i][j]);
        c[n + j].emplace_back(a[i][j]);
      }
    }
    for (int i = 0; i < (int)n + m - 1; i++) {
      (sort(c[i].begin(), c[i].end()),
       c[i].resize(distance(c[i].begin(), unique(c[i].begin(), c[i].end()))));
    }
    for (int i = 0; i < (int)n; i++) {
      for (int j = 0; j < (int)m; j++) {
        x = a[i][j];
        int p = lower_bound((c[i]).begin(), (c[i]).end(), x) - c[i].begin();
        int q = lower_bound((c[n + j]).begin(), (c[n + j]).end(), x) -
                c[n + j].begin();
        y = max(p + 1, q + 1);
        ans[i][j] =
            max((int)c[i].size() - p + y, (int)c[n + j].size() - q + y) - 1;
      }
    }
    for (int i = 0; i < (int)n; i++) {
      for (int j = 0; j < (int)m; j++) {
        cout << ans[i][j] << " ";
      }
      cout << '\n';
    }
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  ASkyscrapers solver;
  std::istream& in(std::cin);
  std::ostream& out(std::cout);
  solver.solve(in, out);
  return 0;
}
