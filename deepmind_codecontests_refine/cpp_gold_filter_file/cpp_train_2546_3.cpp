#include <bits/stdc++.h>
using namespace std;
const long double PI = acos(-1);
long long power(long long b, long long e, long long m) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b % m, e / 2, m) % m;
  return power(b * b % m, e / 2, m);
}
long long power(long long b, long long e) {
  if (e == 0) return 1;
  if (e & 1) return b * power(b * b, e / 2);
  return power(b * b, e / 2);
}
template <typename T, typename U>
static inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
static inline void amax(T &x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  return os << '(' << p.first << "," << p.second << ')';
}
const int N = 10005, NN = 100005;
pair<long double, long double> wall[NN];
long double angle[N], lb[NN], ub[NN];
long long n, V;
long double cons;
long double findIt(long double x, long double y) {
  auto eval = [&](long double x, long double p) {
    return p * tan(x) * (1 - p / (cons * sin(2 * x)));
  };
  long long op = 50;
  long double lo = 0, hi = PI / 4;
  while (lo <= hi) {
    long double mid = (lo + hi) / 2.0;
    if (eval(mid, x) >= y)
      hi = mid - 0.00000001;
    else
      lo = mid + 0.00000001;
  }
  return lo;
}
map<long double, pair<long double, long double>> ans;
set<long double> pro;
int _runtimeTerror_() {
  cin >> n >> V;
  cons = (V * V) / 9.8;
  for (int i = 0; i < n; ++i) {
    cin >> angle[i];
    pro.insert(angle[i]);
  }
  long long m;
  cin >> m;
  for (int i = 0; i < m; ++i) cin >> wall[i].first >> wall[i].second;
  sort(wall, wall + m);
  auto eval = [&](long double an, long double x) {
    return x * tan(an) * (1 - x / cons / sin(2 * an));
  };
  for (int i = 0; i < m; ++i) {
    vector<long double> v;
    if (wall[i].first >= cons) break;
    lb[i] = findIt(wall[i].first, 0);
    ub[i] = findIt(wall[i].first, wall[i].second);
    auto it = pro.lower_bound(lb[i]);
    auto it2 = pro.upper_bound(ub[i]);
    for (auto j = it; j != it2; ++j)
      ans[*j].second = eval(*j, wall[i].first), v.push_back(*j),
      ans[*j].first = wall[i].first;
    for (auto j : v) pro.erase(j);
  }
  for (auto j : pro) ans[j].second = 0, ans[j].first = cons * sin(j * 2.0);
  cout << fixed << setprecision(20);
  for (int i = 0; i < n; ++i) {
    cout << ans[angle[i]].first << " " << ans[angle[i]].second << "\n";
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) _runtimeTerror_();
  cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC;
  return 0;
}
