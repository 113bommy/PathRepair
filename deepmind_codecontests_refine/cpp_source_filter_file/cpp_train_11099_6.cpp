#include <bits/stdc++.h>
using namespace std;
const unsigned long long oo = 1ll << 50;
const unsigned long long MX = 2000000;
struct data {
  int t, l, c;
  bool operator<(const data &in) const { return t < in.t; }
};
vector<data> v, b;
unsigned long long now[MX];
unsigned long long prefix[MX];
unsigned long long suffix[MX];
int main() {
  unsigned long long n, m, k;
  cin >> n >> m >> k;
  while (m--) {
    int t, s, d, c;
    cin >> t >> s >> d >> c;
    if (d == 0) v.push_back({t, s, c});
    if (s == 0) b.push_back({-t, d, c});
  }
  sort(v.begin(), v.end());
  sort(b.begin(), b.end());
  unsigned long long p = 0, f = 0;
  for (int i = 1; i < n + 1; i++) p += (now[i] = oo);
  for (int i = 0; i < MX; i++) {
    while (f < v.size() && v[f].t == i) {
      if (v[f].c < now[v[f].l]) {
        p -= now[v[f].l] - v[f].c;
        now[v[f].l] = v[f].c;
      }
      f++;
    }
    prefix[i] = p;
  }
  p = 0, f = 0;
  for (int i = 1; i < n + 1; i++) p += (now[i] = oo);
  for (int i = 0; i < b.size(); i++) b[i].t = -b[i].t;
  for (int i = MX - 1; i >= 0; i--) {
    while (f < b.size() && b[f].t == i) {
      if (b[f].c < now[b[f].l]) {
        p -= now[b[f].l] - b[f].c;
        now[b[f].l] = b[f].c;
      }
      f++;
    }
    suffix[i] = p;
  }
  unsigned long long ans = oo;
  for (int i = 0; i < MX - k - 2; i++) {
    ans = min(ans, prefix[i] + suffix[i + k + 1]);
  }
  if (ans >= oo)
    cout << -1;
  else
    cout << ans << endl;
}
