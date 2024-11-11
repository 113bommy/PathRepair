#include <bits/stdc++.h>
using namespace std;
int n, k, a, b, q, t1, t2, t3, fix[400010], nfix[400010];
void update(int node) {
  for (int i = (node + n) >> 1; i; i >>= 1) {
    fix[i] = fix[i * 2] + fix[i * 2 + 1];
    nfix[i] = nfix[i * 2] + nfix[i * 2 + 1];
  }
}
int fquery(int l, int r) {
  if (r < 1) return 0;
  int re = fix[r + n];
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) re += fix[l++];
    if (r & 1) re += fix[--r];
  }
  return re;
}
int nfquery(int l, int r) {
  if (r < 1) return 0;
  int re = nfix[r + n];
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) re += nfix[l++];
    if (r & 1) re += nfix[--r];
  }
  return re;
}
int main() {
  cin >> n >> k >> a >> b >> q;
  for (int i = 0; i < q; i++) {
    cin >> t1;
    if (t1 == 1) {
      cin >> t2 >> t3;
      fix[t2 + n] = min(a, fix[t2 + n] + t3);
      nfix[t2 + n] = min(b, nfix[t2 + n] + t3);
      update(t2);
    } else {
      cin >> t2;
      cout << nfquery(1, t2 - 1) + fquery(t2 + k, n) << endl;
    }
  }
}
