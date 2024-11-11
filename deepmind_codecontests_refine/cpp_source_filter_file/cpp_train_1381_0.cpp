#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, cnt, a[maxn], b[maxn], tot[maxn], cnt1, cnt2, ans, num, cost, sum, top;
int head[maxn << 1], nxt[maxn << 2], to[maxn << 2], c[maxn << 2];
int op[maxn], v[maxn << 1], q[maxn];
void build(int x, int y, int k) {
  nxt[++cnt] = head[x];
  head[x] = cnt;
  to[cnt] = y;
  c[cnt] = k;
}
void dfs(int x, int fl) {
  int y;
  v[x] = 1;
  for (int i = head[x]; i; i = nxt[i]) {
    y = to[i];
    if (v[y]) continue;
    if (fl) op[x - n] = y, num++, cost += c[i], q[++top] = x;
    dfs(y, fl ^ 1);
    break;
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    ans = 0;
    cnt = 0;
    cnt1 = 0;
    cnt2 = 0;
    sum = 0;
    for (int i = 1; i <= n; i++)
      head[i] = head[i + n] = 0, tot[i] = 0, v[i] = v[i + n] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), tot[a[i]]++;
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]), tot[b[i]]++;
    int fl = 0;
    for (int i = 1; i <= n && fl; i++)
      if (tot[i] != 2) {
        printf("-1\n");
        fl = 1;
      }
    if (fl) continue;
    for (int i = 1; i <= n; i++) {
      build(i + n, a[i], 0);
      build(a[i], i + n, 0);
      build(i + n, b[i], 1);
      build(b[i], i + n, 1);
    }
    for (int i = 1; i <= n; i++) {
      if (!v[i + n]) {
        top = 0;
        num = 0, cost = 0, dfs(i + n, 1), sum += num;
        if (num - cost < cost) {
          for (int j = 1; j <= top; j++) {
            int x = q[j];
            for (int z = head[x]; z; z = nxt[z]) {
              if (to[z] != op[x - n]) {
                op[x - n] = to[z];
                break;
              }
            }
          }
        }
        ans += min(num - cost, cost);
      }
    }
    if (sum < n) {
      printf("-1\n");
      continue;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
      if (a[i] == b[i]) continue;
      if (op[i] == b[i]) printf("%d ", i);
    }
    printf("\n");
  }
  return 0;
}
