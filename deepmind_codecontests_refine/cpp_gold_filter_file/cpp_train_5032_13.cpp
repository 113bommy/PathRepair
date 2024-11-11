#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 7;
const long long llinf = 1e18 + 7;
const double eps = 1e-12;
struct item {
  int a, b, c;
  bool operator<(const item& o) const { return b < o.a - o.b; }
} f[200][200];
int n, m, k;
int main() {
  int ans = 0;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < int(n); ++i) {
    char whocares[100];
    scanf("%s", whocares);
    for (int j = 0; j < int(m); ++j)
      scanf("%d %d %d", &f[i][j].a, &f[i][j].b, &f[i][j].c);
  }
  for (int i = 0; i < int(n); ++i)
    for (int j = 0; j < int(n); ++j) {
      map<int, int, greater<int> > s;
      for (int l = 0; l < int(m); ++l) s[f[j][l].b - f[i][l].a] += f[i][l].c;
      int cnt = 0;
      int res = 0;
      while (cnt < k) {
        if (s.empty()) break;
        auto p = *s.begin();
        s.erase(s.begin());
        int q = min(k - cnt, p.second);
        cnt += q;
        if (p.first > 0) res += q * p.first;
      }
      ans = max(ans, res);
    }
  cout << ans << endl;
}
