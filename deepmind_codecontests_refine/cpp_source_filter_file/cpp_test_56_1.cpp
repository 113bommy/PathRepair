#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007, inf = 2e18;
const int N = 200001;
const double ep = 1e-10;
template <typename A, typename B>
ostream& operator<<(ostream& cout, pair<A, B> const& p) {
  return cout << "(" << p.first << ", " << p.second << ")";
}
template <typename A>
ostream& operator<<(ostream& cout, vector<A> const& v) {
  cout << "[";
  for (int i = 0; i < v.size(); i++) {
    if (i) cout << ", ";
    cout << v[i];
  }
  return cout << "]";
}
template <typename A, typename B>
istream& operator>>(istream& cin, pair<A, B>& p) {
  cin >> p.first;
  return cin >> p.second;
}
template <typename A>
istream& operator>>(istream& cin, vector<A>& x) {
  for (int i = 0; i < x.size() - 1; i++) cin >> x[i];
  return cin >> x[x.size() - 1];
}
long long f(int n) {
  if (n == 0) return 1;
  if (n == 1) return 6;
  if (n == 2) return 16;
  long long u = f(n - 1);
  u *= u;
  u %= mod;
  u *= 16, u %= mod;
  return u;
}
void darling(int kase) {
  int n;
  cin >> n;
  int m;
  cin >> m;
  set<long long> g;
  map<long long, int> cl;
  map<string, int> nam;
  nam["white"] = 6, nam["yellow"] = 1, nam["green"] = 2, nam["blue"] = 3,
  nam["red"] = 4, nam["orange"] = 5;
  map<int, int> opp;
  opp[6] = 1, opp[1] = 6, opp[2] = 3, opp[3] = 2, opp[4] = 5, opp[5] = 4;
  for (int j = 0; (1 < 0 && j > m) || (1 > 0 && j < m); j += 1) {
    long long t;
    string clr;
    cin >> t >> clr;
    cl[t] = nam[clr];
    while (t) {
      g.insert(t);
      t /= 2;
    }
  }
  auto lev = [](long long x) {
    int i = 0;
    while (x) i++, x /= 2;
    return i;
  };
  function<array<long long, 6>(long long)> dfs = [&](long long u) {
    array<long long, 6> r = {0, 0, 0, 0, 0, 0};
    if (lev(u) == n) {
      for (int i = 0; (1 < 0 && i > 6) || (1 > 0 && i < 6); i += 1) r[i] = 1;
      if (cl[u])
        for (int i = 0; (1 < 0 && i > 6) || (1 > 0 && i < 6); i += 1)
          if (cl[u] - 1 != i) r[i] = 0;
      return r;
    }
    if (g.find(u) == g.end()) {
      if (cl[u]) {
        r[cl[u] - 1] = f(n - lev(u) + 1);
      } else {
        for (int i = 0; (1 < 0 && i > 6) || (1 > 0 && i < 6); i += 1)
          r[i] = f(n - lev(u) + 1);
      }
      return r;
    } else {
      auto x = dfs(u + u), y = dfs(u + u + 1);
      for (int i = 0; (1 < 0 && i > 6) || (1 > 0 && i < 6); i += 1) {
        r[i] = 0;
        for (int xi = 0; (1 < 0 && xi > 6) || (1 > 0 && xi < 6); xi += 1)
          for (int yi = 0; (1 < 0 && yi > 6) || (1 > 0 && yi < 6); yi += 1)
            if (xi != i and yi != i and xi != opp[i + 1] - 1 and
                yi != opp[i + 1] - i)
              r[i] += x[xi] * y[yi], r[i] %= mod;
      }
      if (cl[u]) {
        for (int i = 0; (1 < 0 && i > 6) || (1 > 0 && i < 6); i += 1)
          if (i + 1 != cl[u]) r[i] = 0;
      }
      return r;
    }
  };
  auto v = dfs(1);
  long long z = 0;
  for (int i = 0; (1 < 0 && i > 6) || (1 > 0 && i < 6); i += 1)
    z += v[i], z %= mod;
  cout << z;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int T = 1;
  for (int K = 0; (1 < 0 && K > T) || (1 > 0 && K < T); K += 1) darling(K + 1);
}
