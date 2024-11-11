#include <bits/stdc++.h>
using namespace std;
set<int> v[100001];
vector<int> t[400001];
int a[100001];
int b[100001];
int n;
void build(int v = 1, int tl = 1, int tr = n) {
  if (tl == tr) {
    t[v].push_back(b[tl]);
    return;
  }
  int tm = (tl + tr) / 2;
  build(v + v, tl, tm);
  build(v + v + 1, tm + 1, tr);
  int l = 0;
  int r = 0;
  while (l < t[v + v].size() || r < t[v + v + 1].size()) {
    if (l == t[v + v].size()) {
      t[v].push_back(t[v + v + 1][r]);
      r++;
    } else if (r == t[v + v + 1].size()) {
      t[v].push_back(t[v + v][l]);
      l++;
    } else {
      if (t[v + v][l] <= t[v + v + 1][r]) {
        t[v].push_back(t[v + v][l]);
        l++;
      } else {
        t[v].push_back(t[v + v + 1][r]);
        r++;
      }
    }
  }
}
int get(int l, int r, int v = 1, int tl = 1, int tr = n) {
  if (tl > r || tr < l) return 0;
  if (tl >= l && tr <= r) {
    int ll = 0;
    int rr = t[v].size() - 1;
    int sum = 0;
    while (ll <= rr) {
      int mm = (ll + rr) / 2;
      if (t[v][mm] < l) {
        ll = mm + 1;
        sum = max(mm, sum);
      } else {
        rr = mm - 1;
      }
    }
    return sum + 1;
  }
  int tm = (tl + tr) / 2;
  return get(l, r, v + v, tl, tm) + get(l, r, v + v + 1, tm + 1, tr);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = -1;
    if (v[a[i]].size() >= k) {
      b[i] = *v[a[i]].begin();
      v[a[i]].erase(*v[a[i]].begin());
    }
    v[a[i]].insert(i);
  }
  int q;
  cin >> q;
  int last = 0;
  build();
  int left = 0;
  int right = 0;
  while (q--) {
    int x, y;
    cin >> x >> y;
    left = ((x + last) % n) + 1;
    right = ((y + last) % n) + 1;
    bool ok = 0;
    if (left > right) {
      swap(left, right);
      ok = 1;
    }
    last = get(left, right);
    cout << last << endl;
    if (ok) swap(left, right);
  }
  return 0;
}
