#include <bits/stdc++.h>
using namespace std;
long long vol[100005];
long long seg[4 * 100005];
void update(int s, int e, int p, int idx, long long v) {
  if (e < idx || s > idx) return;
  if (s == e) {
    seg[p] = v;
    return;
  }
  int mid = (s + e) >> 1;
  int l = p << 1;
  int r = l | 1;
  update(s, mid, l, idx, v);
  update(mid + 1, e, r, idx, v);
  seg[p] = max(seg[l], seg[r]);
}
long long query(int s, int e, int p, int qe) {
  if (s > qe) return 0;
  if (e <= qe) return seg[p];
  int mid = (s + e) >> 1;
  int l = p << 1;
  int r = l | 1;
  return max(query(s, mid, l, qe), query(mid + 1, e, r, qe));
}
int main() {
  int n;
  cin >> n;
  map<long long, int> rnk;
  map<int, long long> revrnk;
  for (int i = 0; i < n; i++) {
    long long r, h;
    cin >> r >> h;
    vol[i] = r * r * h;
    rnk[vol[i]];
  }
  int lst = 0;
  for (map<long long, int>::iterator it = rnk.begin(); it != rnk.end(); it++)
    it->second = ++lst, revrnk[lst] = it->first;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    long long mx = 0;
    if (rnk[vol[i]] - 1 >= 1) mx = query(1, lst, 1, rnk[vol[i]] - 1);
    mx += vol[i];
    update(1, lst, 1, rnk[vol[i]], mx);
    ans = max(ans, mx);
  }
  cout << fixed << setprecision(10) << ans * acosl(-1) << "\n";
  return 0;
}
