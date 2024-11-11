#include <bits/stdc++.h>
using namespace std;
typedef double ld;
struct info {
  complex<ld> p;
  int id;
  bool operator<(const info &o) const {
    if (p.real() != o.p.real()) return p.real() < o.p.real();
    return p.imag() < o.p.imag();
  }
  bool operator==(const info &o) const { return p == o.p; }
};
ld cross(complex<ld> a, complex<ld> b) { return imag(conj(a) * b); }
ld cross(info a, info b, info c) { return cross(b.p - a.p, c.p - a.p); }
const ld eps = 1e-22;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  vector<info> a(n);
  for (auto &i : a) {
    int x, y;
    cin >> x >> y;
    i.p = {(ld)1.0 / x, (ld)1.0 / y};
    i.id = &i - &a[0];
  }
  map<info, vector<int>> mp;
  for (auto i : a) mp[i].push_back(i.id);
  vector<info> ans;
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());
  for (auto i : a) {
    while (ans.size() >= 2 && cross(ans.end()[-2], ans.end()[-1], i) < -eps)
      ans.pop_back();
    ans.push_back(i);
  }
  while (ans.size() >= 2 && (ans.end()[-1].p - ans.end()[-2].p).imag() > -eps)
    ans.pop_back();
  vector<int> pos;
  for (auto i : ans)
    for (auto j : mp[i]) pos.push_back(j);
  sort(pos.begin(), pos.end());
  for (auto i : pos) cout << i + 1 << " ";
  return 0;
}
