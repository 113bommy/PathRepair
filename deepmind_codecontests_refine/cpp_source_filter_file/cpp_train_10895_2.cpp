#include <bits/stdc++.h>
using namespace std;
struct Node {
  int no, l;
  long long x;
  bool friend operator<(Node x1, Node x2) { return x1.l < x2.l; }
} q[100005];
long long init[100005];
long long num[100005];
long long ans[100005];
long long temp[25];
bool ok(long long x) {
  for (int i = 19; i >= 0; i--) {
    if (x & init[i]) x ^= temp[i];
  }
  return x == 0;
}
int main() {
  init[0] = 1;
  for (int i = 1; i < 20; i++) init[i] = (init[i - 1] * 2) % 1000000007;
  int n, m, now = 0, cnt = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%lld", &num[i]);
  for (int i = 1; i <= m; i++) {
    q[i].no = i;
    scanf("%d%lld", &q[i].l, &q[i].x);
  }
  sort(q + 1, q + 1 + m);
  for (int i = 1; i <= m; i++) {
    while (now < q[i].l) {
      now++;
      for (int j = 19; j >= 0; j--) {
        if (num[now] & init[j]) {
          if (temp[j] == 0) {
            temp[j] = num[now];
            cnt++;
            break;
          } else
            num[now] ^= temp[j];
        }
      }
    }
    if (ok(q[i].x)) ans[q[i].no] = init[now - cnt];
  }
  for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
  return 0;
}
