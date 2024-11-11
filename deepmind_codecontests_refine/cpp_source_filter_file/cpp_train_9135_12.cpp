#include <bits/stdc++.h>
using namespace std;
int n, q, x, y;
int a[100005];
long long lazy[100005 * 4], S[100005 * 4];
void push(int node, int bas, int son) {
  S[node * 2] += lazy[node];
  S[node * 2 + 1] += lazy[node];
  lazy[node * 2] += lazy[node];
  lazy[node * 2 + 1] += lazy[node];
  lazy[node] = 0;
}
int get(int node, int bas, int son) {
  if (bas == son) return (S[node] == 0 ? bas : -1);
  if (S[node] < 0) return -1;
  push(node, bas, son);
  return max(get(node * 2, bas, ((bas + son) / 2)),
             get(node * 2 + 1, ((bas + son) / 2) + 1, son));
}
void up(int node, int bas, int son, int x, int y, long long val) {
  if (bas > y || son < x) return;
  if (bas >= x && son <= y) {
    S[node] += val;
    lazy[node] += val;
    return;
  }
  push(node, bas, son);
  up(node * 2, bas, ((bas + son) / 2), x, y, val);
  up(node * 2 + 1, ((bas + son) / 2) + 1, son, x, y, val);
  S[node] = max(S[node * 2], S[node * 2 + 1]);
}
int main() {
  long long sum = 0;
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    up(1, 1, n, i, i, a[i] - sum);
    sum += a[i];
  }
  while (q--) {
    scanf("%d %d", &x, &y);
    up(1, 1, n, x, x, y - a[x]);
    up(1, 1, n, x + 1, n, a[x] - y);
    a[x] = y;
    printf("%d\n", get(1, 1, n));
  }
}
