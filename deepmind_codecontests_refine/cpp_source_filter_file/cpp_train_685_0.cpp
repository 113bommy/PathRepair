#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, SZ = 320;
int n, q, a[N];
set<int> st[N];
pair<int, int> b[N], c[N];
long long pt[N];
void arrenge(int l) {
  int r = min(n, l + SZ);
  for (int i = l; i < r; i++) c[i] = b[i];
  sort(c + l, c + r);
  for (int i = r - 1; i >= l; i--) {
    pt[i] = c[i].second;
    if (i + 1 > r) pt[i] += pt[i + 1];
  }
}
void refresh(int p) {
  auto it = st[a[p]].upper_bound(p);
  pair<int, int> x;
  if (it != st[a[p]].end())
    x = make_pair(*it, *it - p);
  else
    x = make_pair(-1, 0);
  b[p] = x;
  arrenge(p / SZ * SZ);
}
long long get(int l, int r) {
  long long res = 0;
  for (l; l < r && l % SZ != 0; l++)
    if (b[l].first < r) res += b[l].second;
  for (l; l / SZ != r / SZ; l += SZ) {
    int t = lower_bound(c + l, c + l + SZ, make_pair(r, -1)) - c;
    res += pt[l];
    if (t < l + SZ) res -= pt[t];
  }
  for (l; l < r; l++)
    if (b[l].first < r) res += b[l].second;
  return res;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n - 1; ~i; i--) {
    if (st[a[i]].size())
      b[i] = make_pair(*st[a[i]].begin(), *st[a[i]].begin() - i);
    else
      b[i] = make_pair(-1, 0);
    st[a[i]].insert(i);
  }
  for (int i = 0; i < n; i += SZ) arrenge(i);
  while (q--) {
    int tp;
    cin >> tp;
    if (tp == 2) {
      int l, r;
      cin >> l >> r;
      l--;
      cout << get(l, r) << endl;
    } else {
      int p, x;
      cin >> p >> x;
      p--;
      if (a[p] - x) {
        st[a[p]].erase(p);
        auto it = st[a[p]].lower_bound(p);
        if (it != st[a[p]].begin()) {
          it--;
          refresh(*it);
        }
        a[p] = x;
        st[x].insert(p);
        refresh(p);
        it = st[x].lower_bound(p);
        if (it != st[x].begin()) {
          it--;
          refresh(*it);
        }
      }
    }
  }
}
