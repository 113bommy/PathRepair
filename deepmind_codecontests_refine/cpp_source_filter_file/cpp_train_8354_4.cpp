#include <bits/stdc++.h>
const int MAX = 200010;
const long long MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const long double EPS = 1e-6;
const long double PI = acos(-1.0);
using namespace std;
struct seg {
  int xl, xr, y;
  bool operator<(const seg &o) const { return y < o.y; }
};
vector<seg> vet;
long double get_diff(long double ang) {
  long double m = LLINF, M = -LLINF;
  for (auto v : vet) {
    m = min(m, v.xl + ang * v.y);
    M = max(M, v.xr + ang * v.y);
  }
  return M - m;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, xl, xr, y;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> xl >> xr >> y;
    seg a = {xl, xr, y};
    vet.push_back(a);
  }
  vector<pair<long double, int> > angs;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (vet[i].y <= vet[j].y) continue;
      angs.emplace_back(
          (vet[j].xl - vet[i].xr) / (long double)(vet[i].y - vet[j].y), 1);
      angs.emplace_back(
          (vet[j].xr - vet[i].xl) / (long double)(vet[i].y - vet[j].y), 0);
    }
  }
  vector<long double> escolhas;
  if (angs.empty()) {
    cout << get_diff(0) << '\n';
    return 0;
  } else {
    int k = 0;
    sort(angs.begin(), angs.end());
    for (auto a : angs) {
      if ((a.second == 1 and k == 0) or (a.second == 0 and k == 1))
        escolhas.push_back(a.first);
      k += (a.second ? 1 : -1);
    }
  }
  int len = escolhas.size();
  int l = 0, r = len - 2;
  long double ans = min(get_diff(escolhas[0]), get_diff(escolhas.back()));
  while (l <= r) {
    int m = (l + r) / 2;
    if (get_diff(escolhas[m]) >= get_diff(escolhas[m + 1])) {
      l = m + 1;
      for (int i = m; i >= 0 and i > m - 200; i--)
        ans = min(ans, get_diff(escolhas[i]));
      for (int i = m; i < len and i < m + 200; i++)
        ans = min(ans, get_diff(escolhas[i]));
    } else {
      for (int i = m; i >= 0 and i > m - 200; i--)
        ans = min(ans, get_diff(escolhas[i]));
      for (int i = m; i < len and i < m + 200; i++)
        ans = min(ans, get_diff(escolhas[i]));
      r = m - 1;
    }
  }
  cout << fixed << setprecision(10) << ans << '\n';
  return 0;
}
