#include <bits/stdc++.h>
using namespace std;
const int N_ = 200500;
int MOD, N;
int A[N_];
class modint {
  int v;

 public:
  modint() : v(0) {}
  modint(long long v) : v((v + MOD) % MOD) {}
  modint inv() {
    modint ret = 1, p = v;
    int q = MOD - 2;
    while (q > 0) {
      if (q & 1) ret = ret * p;
      p = p * p;
      q >>= 1;
    }
    return ret;
  }
  bool operator==(modint x) { return v == x.v; }
  bool operator!=(modint x) { return v != x.v; }
  modint operator+(modint x) { return v + x.v; }
  modint operator-(modint x) { return v - x.v; }
  modint operator*(modint x) { return (long long)v * x.v; }
  modint operator/(modint x) { return x.inv() * v; }
  modint& operator+=(const modint x) { return *this = (*this + x); }
  modint& operator-=(const modint x) { return *this = (*this - x); }
  modint& operator*=(const modint x) { return *this = (*this * x); }
  modint& operator/=(const modint x) { return *this = (*this / x); }
  int& operator*() { return v; }
  bool operator<(const modint x) const { return v < x.v; }
};
pair<modint, modint> get(vector<modint> a) {
  if (a.empty()) {
    return pair<modint, modint>(0, 1);
  }
  if (a.size() == 1) {
    return pair<modint, modint>(a[0], 1);
  }
  if (a.size() > MOD / 2) {
    vector<modint> b;
    for (int i = 0, j = 0; i < MOD; i++) {
      if (a[j] == i) {
        j++;
      } else {
        b.push_back(i);
      }
    }
    pair<modint, modint> r = get(b);
    return pair<modint, modint>(r.first - r.second, modint(0) - r.second);
  }
  modint rs;
  vector<modint> d;
  set<modint> sd;
  set<modint> sa;
  for (auto x : a) {
    modint y = x - a[0];
    d.push_back(y);
    sa.insert(x);
    sd.insert(y);
  }
  int r = 0;
  for (auto y : d) {
    modint z = y + d[1];
    if (sd.find(z) == sd.end()) r += 1;
  }
  rs = d[1] / r;
  vector<modint> cand;
  for (auto x : a) {
    modint p = x - rs;
    if (sa.find(p) == sa.end()) cand.push_back(x);
  }
  if (cand.size() == 1)
    return pair<modint, modint>(cand[0], rs);
  else {
    puts("-1");
    exit(0);
  }
}
int main() {
  scanf("%d%d", &MOD, &N);
  vector<modint> a(N);
  for (auto& x : a) {
    int v;
    scanf("%d", &v);
    x = v;
  }
  sort(a.begin(), a.end());
  pair<modint, modint> ret = get(a);
  printf("%d %d\n", *ret.first, *ret.second);
  return 0;
}
