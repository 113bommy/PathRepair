#include <bits/stdc++.h>
using namespace std;
int T;
int n, m;
int a[2000010], b[2000010];
int pos[2000010];
long long ans;
void find_ans(int L, int R, int l, int r) {
  if (l > r) return;
  int mid = (l + r) >> 1;
  int x = b[mid], cnt = 0;
  for (int i = L; i <= R; i++)
    if (a[i] < x) cnt++;
  int mn = cnt;
  pos[mid] = L - 1;
  for (int i = L; i <= R; i++) {
    if (a[i] > x) cnt++;
    if (a[i] < x) cnt--;
    if (cnt < mn) {
      mn = cnt;
      pos[mid] = i;
    }
  }
  find_ans(L, pos[mid], l, mid - 1);
  find_ans(pos[mid], R, mid + 1, r);
}
struct Node {
  int pos, val, tp;
} node[2000010 << 1];
int tot;
int tmp[2000010 << 1];
int N;
void lisan() {
  tmp[0] = 0;
  for (int i = 1; i <= n; i++) tmp[++tmp[0]] = a[i];
  for (int i = 1; i <= m; i++) tmp[++tmp[0]] = b[i];
  sort(tmp + 1, tmp + tmp[0] + 1);
  N = unique(tmp + 1, tmp + tmp[0] + 1) - tmp - 1;
  for (int i = 1; i <= n; i++)
    a[i] = lower_bound(tmp + 1, tmp + N + 1, a[i]) - tmp;
  for (int i = 1; i <= m; i++)
    b[i] = lower_bound(tmp + 1, tmp + N + 1, b[i]) - tmp;
}
int sum[2000010 << 1];
int lowbit(int x) { return x & -x; }
void Upd(int x) {
  for (int i = x; i <= N; i += lowbit(i)) sum[i]++;
}
long long query(int x) {
  long long ret = 0;
  for (int i = x; i; i -= lowbit(i)) ret += sum[i];
  return ret;
}
bool cmp1(Node a, Node b) {
  if (a.pos != b.pos) return a.pos < b.pos;
  if (a.val != b.val) return a.val < b.val;
  return a.tp < b.tp;
}
void work() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  lisan();
  sort(b + 1, b + m + 1);
  find_ans(1, n, 1, m);
  tot = 0;
  for (int i = 1; i <= n; i++) {
    node[++tot] = (Node){i, a[i], 0};
  }
  for (int i = 1; i <= m; i++) {
    node[++tot] = (Node){pos[i], b[i], 1};
  }
  sort(node + 1, node + tot + 1, cmp1);
  for (int i = 0; i <= N; i++) sum[i] = 0;
  long long ans = 0;
  for (int i = tot; i >= 1; i--) {
    Upd(node[i].val);
    int now = query(node[i].val - 1);
    ans += now;
  }
  printf("%lld\n", ans);
}
int main() {
  scanf("%d", &T);
  while (T--) work();
}
