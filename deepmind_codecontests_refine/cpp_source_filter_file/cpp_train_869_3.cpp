#include <bits/stdc++.h>
using namespace std;
const int maxn = 5007;
int SG[4 * maxn];
int ar[maxn];
int res[maxn];
int n, m, foo, mx = -1;
double d;
void update(int pt, int st, int en, int pos, int val) {
  if (st > pos or en < pos) return;
  if (st == en) {
    SG[pt] = val;
    return;
  }
  int mid = (st + en) >> 1;
  update(2 * pt + 1, st, mid, pos, val);
  update(2 * pt + 2, mid + 1, en, pos, val);
  SG[pt] = max(SG[2 * pt + 1], SG[2 * pt + 2]);
}
int query(int pt, int st, int en, int qs, int qe) {
  if (st > qe or en < qs) return -1;
  if (st >= qs and en <= qe) return SG[pt];
  int mid = (st + en) >> 1;
  return max(query(2 * pt + 1, st, mid, qs, qe),
             query(2 * pt + 2, mid + 1, en, qs, qe));
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> ar[i] >> d, ar[i]--;
  for (int i = 0; i < n; i++) {
    res[i] = 1 + query(0, 0, m - 1, 0, ar[i]);
    update(0, 0, m - 1, ar[i], res[i]);
  }
  for (int i = 1; i <= n; i++) mx = max(mx, res[i]);
  printf("%d\n", n - mx);
  return 0;
}
