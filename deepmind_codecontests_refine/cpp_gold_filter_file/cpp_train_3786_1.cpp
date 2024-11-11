#include <bits/stdc++.h>
using namespace std;
template <typename T>
T abs(T a) {
  return a < 0 ? -a : a;
}
template <typename T>
T sqr(T a) {
  return a * a;
}
const int INF = (int)1e9;
const long double EPS = 1e-9;
const long double PI = 3.1415926535897932384626433832795;
const int N = 200;
inline void makeLine(const pair<long double, long double>& a,
                     const pair<long double, long double>& b, long double& A,
                     long double& B, long double& C) {
  A = b.second - a.second;
  B = a.first - b.first;
  C = -A * a.first - B * a.second;
}
inline long double det(const long double& a, const long double& b,
                       const long double& c, const long double& d) {
  return a * d - b * c;
}
inline long double mid(const pair<long double, long double>& a,
                       const pair<long double, long double>& b,
                       const pair<long double, long double>& c) {
  return min(a.first, b.first) <= c.first + EPS &&
         c.first <= max(a.first, b.first) + EPS &&
         min(a.second, b.second) <= c.second + EPS &&
         c.second <= max(a.second, b.second) + EPS;
}
pair<long double, long double> operator-(
    const pair<long double, long double>& a,
    const pair<long double, long double>& b) {
  return pair<long double, long double>(a.first - b.first, a.second - b.second);
}
inline int vmulS(const pair<long double, long double>& a,
                 const pair<long double, long double>& b) {
  long double res = a.first * b.second - a.second * b.first;
  if (abs(res) < EPS) return 0;
  return (res < 0) ? -1 : 1;
}
inline bool intersect(const pair<long double, long double>& a1,
                      const pair<long double, long double>& b1,
                      const pair<long double, long double>& a2,
                      const pair<long double, long double>& b2) {
  if (max(a1.first, b1.first) + EPS < min(a2.first, b2.first) ||
      max(a1.second, b1.second) + EPS < min(a2.second, b2.second) ||
      max(a2.first, b2.first) + EPS < min(a1.first, b1.first) ||
      max(a2.second, b2.second) + EPS < min(a1.second, b1.second))
    return false;
  return vmulS(b2 - a1, b1 - a1) * vmulS(a2 - a1, b1 - a1) <= 0 &&
         vmulS(b1 - a2, b2 - a2) * vmulS(a1 - a2, b2 - a2) <= 0;
}
int n, hlf, hrg;
int t[N], lf[N], rg[N], v[N];
bool used[N];
vector<pair<pair<long double, long double>, int> > fns;
int main() {
  cin >> hlf >> hrg >> n;
  for (int i = 0; i < int(n); ++i) {
    cin >> v[i];
    char tp;
    scanf(" %c", &tp);
    if (tp == 'T') t[i] = 1;
    cin >> lf[i] >> rg[i];
  }
  {
    pair<long double, long double> cnf(100000, hrg);
    int cnt = 0;
    for (int lvl = 0; lvl >= -100; --lvl) {
      int ln = lvl * 100;
      cnf.second += 2 * (ln - cnf.second);
      cnt++;
      fns.push_back(make_pair(cnf, cnt));
    }
  }
  {
    pair<long double, long double> cnf(100000, hrg);
    int cnt = 0;
    for (int lvl = 1; lvl <= 100; ++lvl) {
      int ln = lvl * 100;
      cnf.second += 2 * (ln - cnf.second);
      cnt++;
      fns.push_back(make_pair(cnf, cnt));
    }
  }
  int ans = 0;
  for (int j = 0; j < int(int((fns).size())); ++j) {
    pair<long double, long double> st(0, hlf);
    pair<long double, long double> fn = fns[j].first;
    int cnt = 0;
    int cur = 0;
    bool good = true;
    memset(used, 0, sizeof(used));
    for (int lvl = -101; lvl <= 101; ++lvl) {
      for (int i = 0; i < int(n); ++i) {
        if ((lvl & 1) == t[i]) {
          pair<long double, long double> a(lf[i], 100 * lvl);
          pair<long double, long double> b(rg[i], 100 * lvl);
          if (intersect(a, b, st, fn)) {
            cnt++;
            cur += v[i];
            if (used[i]) {
              good = false;
              break;
            }
            used[i] = true;
          }
        }
      }
      if (!good) break;
    }
    if (cnt != fns[j].second || !good) continue;
    ans = max(ans, cur);
  }
  cout << ans << endl;
  return 0;
}
