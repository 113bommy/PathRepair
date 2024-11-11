#include <bits/stdc++.h>
const int M = 500050;
const int inf = 1e9 + 1;
using namespace std;
struct node {
  int value, place;
  friend bool operator<(node x, node y) { return x.value > y.value; }
};
priority_queue<node> q;
int n, m, Ans, chose, nxt[M], pre[M], w[M], l, r, a[M];
bool vis[M];
void change(int x) {
  vis[x] = 1;
  nxt[pre[x]] = nxt[x];
  pre[nxt[x]] = pre[x];
  nxt[x] = 0;
  pre[x] = 0;
}
int main() {
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) w[i] = a[i + 1] - a[i];
  n--;
  for (int i = 1; i < n; i++) nxt[i] = i + 1;
  nxt[n] = n;
  for (int i = 2; i <= n; i++) pre[i] = i - 1;
  pre[1] = 1;
  for (int i = 1; i <= n; i++) q.push((node){w[i], i});
  for (int i = 1; i <= m; i++) {
    while (vis[q.top().place]) q.pop();
    node temp = q.top();
    q.pop();
    Ans += temp.value;
    l = pre[temp.place];
    r = nxt[temp.place];
    w[temp.place] = w[l] + w[r] - w[temp.place];
    w[l] = inf;
    w[r] = inf;
    change(l);
    change(r);
    q.push((node){w[temp.place], temp.place});
  }
  printf("%d\n", Ans);
  return 0;
}
