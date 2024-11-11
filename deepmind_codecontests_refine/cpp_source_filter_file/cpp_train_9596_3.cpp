#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) {
    os << v[i];
    if (i != v.size() - 1) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T>
ostream& operator<<(ostream& os, const set<T>& v) {
  os << "[";
  for (auto it : v) {
    os << it;
    if (it != *v.rbegin()) os << ", ";
  }
  os << "]\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const map<T, S>& v) {
  for (auto it : v) os << it.first << " : " << it.second << "\n";
  return os;
}
template <typename T, typename S>
ostream& operator<<(ostream& os, const pair<T, S>& v) {
  os << "(";
  os << v.first << ", " << v.second << ")";
  return os;
}
void go() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const long long N = 3e5 + 5;
const long long mod = 998244353;
long long f[N];
void pre() {
  f[0] = 1;
  for (long long i = 1; i < N; i++) {
    f[i] = (f[i - 1] * i) % mod;
  }
}
void solve() {
  pre();
  long long n;
  cin >> n;
  vector<pair<long long, long long>> p;
  vector<long long> a(n), b(n), fa(n + 5), fb(n + 5);
  for (long long i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    fa[a[i]]++;
    fb[b[i]]++;
    p.push_back({a[i], b[i]});
  }
  sort(p.begin(), p.end());
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  long long ff = 1, ss = 1;
  for (long long i = 0; i <= n; i++) {
    ff = (ff * f[fa[i]]) % mod;
    ss = (ss * f[fb[i]]) % mod;
  }
  long long tt = 0;
  for (long long i = 0; i < n; i++) {
    b[i] = p[i].second;
  }
  if (is_sorted(b.begin(), b.end())) {
    tt = 1;
    long long c = 1;
    for (long long i = 1; i < n; i++) {
      if (p[i].first == p[i - 1].first and p[i].second == p[i - 1].second) {
        c++;
      } else {
        tt = (tt * c) % mod;
        c = 1;
      }
    }
    tt = (tt * c) % mod;
  }
  cout << ((f[n] - ff - ss + tt + mod) % mod + mod) % mod;
}
int main() {
  go();
  solve();
}
