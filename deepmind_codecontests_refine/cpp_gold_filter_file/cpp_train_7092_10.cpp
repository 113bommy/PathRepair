#include <bits/stdc++.h>
using namespace std;
using namespace std;
const double pi = acos(-1.0);
const int maxn = (int)1e5 + 1;
struct dsu {
  int pa[maxn];
  int cnt[maxn];
  int totalcnt;
  int findpa(int id) {
    if (pa[id] != id) pa[id] = findpa(pa[id]);
    return pa[id];
  }
  void merge(int x, int y) {
    int xpa = findpa(x), ypa = findpa(y);
    if (xpa != ypa) {
      pa[xpa] = ypa;
      --totalcnt;
      cnt[ypa] += cnt[xpa];
      cnt[xpa] = 0;
    }
  }
  void init(int n) {
    totalcnt = n;
    for (int(i) = (1); (i) <= (n); ++(i)) {
      pa[i] = i;
      cnt[i] = 1;
    }
  }
};
dsu solver;
inline bool lucky(const string& str) {
  for (int(i) = (0); (i) < (str.length()); ++(i))
    if (str[i] != '4' && str[i] != '7') return false;
  return true;
}
int main() {
  int n;
  cin >> n;
  solver.init(n);
  for (int(i) = (0); (i) < (n - 1); ++(i)) {
    int u, v;
    string len;
    cin >> u >> v >> len;
    if (!lucky(len)) solver.merge(u, v);
  }
  long long ans = (long long)n * (n - 1) * (n - 2);
  for (int(i) = (1); (i) <= (n); ++(i)) {
    if (solver.cnt[i] > 1) {
      long long m = solver.cnt[i];
      ans -= (long long)m * (m - 1) * 2 * (n - m) + m * (m - 1) * (m - 2);
    }
  }
  cout << ans << '\n';
}
