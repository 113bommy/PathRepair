#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
using vi = vector<int>;
const int N = 1e6 + 100;
int n, q, tr[N];
void add(int x, int v) {
  for (; x <= n; x += x & -x) tr[x] += v;
}
int qry(int x) {
  int ret = 0;
  for (; x; x -= x & -x) ret += tr[x];
  return ret;
}
int ind(int kth) {
  if (qry(n) == 0) return 0;
  int l = 1, r = n, mid;
  while (l < r) qry(mid = l + r >> 1) >= kth ? r = mid : l = mid + 1;
  return l;
}
signed main() {
  scanf("%d %d", &n, &q);
  for (int i = 1, a; i <= n; i++) scanf("%d", &a), add(a, 1);
  for (int i = 1, k; i <= q; i++) {
    scanf("%d", &k);
    if (k > 0) {
      add(k, 1);
    } else {
      k = -k;
      add(ind(k), -1);
    }
  }
  printf("%d\n", ind(1));
  fprintf(stderr, "time=%.4f\n", (db)clock() / CLOCKS_PER_SEC);
  return 0;
}
