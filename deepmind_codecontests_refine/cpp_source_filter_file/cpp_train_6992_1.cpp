#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
pair<int, int> p[200002];
set<int> nrx;
set<int> cx;
int sz, val[200002];
int aib[200002];
void add(int poz) {
  for (; poz <= sz; poz += (poz & (-poz))) aib[poz]++;
}
int compute(int poz) {
  int ans = 0;
  for (; poz; poz -= (poz & (-poz))) ans += aib[poz];
  return ans;
}
int cb(int z) {
  int st = 1;
  int dr = sz;
  int ans = 0;
  while (st <= dr) {
    int mid = (st + dr) / 2;
    if (val[mid] <= z)
      ans = mid, st = mid + 1;
    else
      dr = mid - 1;
  }
  return ans;
}
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) return a.first < b.first;
  return a.second > b.second;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> p[i].first >> p[i].second, swap(p[i].first, p[i].second),
        cx.insert(p[i].second);
  while (!cx.empty()) {
    val[++sz] = *cx.begin();
    cx.erase(cx.begin());
  }
  sort(p + 1, p + n + 1, cmp);
  long long ans = 0;
  long long prv = 0;
  for (int i = n; i >= 1;) {
    int pp = p[i].first;
    while (i > 0 && p[i].first == pp) {
      if (nrx.find(p[i].second) == nrx.end()) {
        add(cb(p[i].second));
        nrx.insert(p[i].second);
      }
      int zz = p[i].second;
      --i;
      int nxt;
      if (p[i].first != pp)
        nxt = sz;
      else
        nxt = cb(p[i].second) - 1;
      ans += compute(cb(zz)) * (compute(nxt) - compute(cb(zz) - 1));
    }
  }
  cout << ans;
  return 0;
}
