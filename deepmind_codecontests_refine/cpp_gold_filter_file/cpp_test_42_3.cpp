#include <bits/stdc++.h>
using namespace std;
int n, m;
int b[4010001], a[4010001];
int mx = -1, S, tsk;
priority_queue<pair<int, int> > que;
bool esit[4010001];
int tim[4010001];
int lat[4010001], mod = 1e9 + 7;
int query(int k, int l, int r, int al, int ar) {
  if (l > ar || r < al) return 0;
  if (l >= al && r <= ar) {
    return tim[k];
  }
  return (query((k << 1), l, (l + r) / 2, al, ar) +
          query((k << 1) + 1, (l + r) / 2 + 1, r, al, ar)) %
         mod;
}
void add(int k, int l, int r, int pos, int val) {
  if (l > pos || r < pos) return;
  if (l == r) {
    tim[k] = (val + tim[k]) % mod;
    return;
  }
  add((k << 1), l, (l + r) / 2, pos, val);
  add((k << 1) + 1, (l + r) / 2 + 1, r, pos, val);
  tim[k] = (tim[(k << 1)] + tim[(k << 1) + 1]) % mod;
}
int Ask[4010001], bl[4010001];
bool cmp(int x, int y) { return b[x] > b[y]; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    esit[a[i]] = 1;
  }
  scanf("%d", &S);
  for (int i = 1; i <= S; i++) {
    scanf("%d", &tsk);
    mx = max(mx, b[tsk]);
    Ask[i] = tsk;
  }
  sort(Ask + 1, Ask + n + 1, cmp);
  int lt;
  bl[Ask[lt = 1]] = 1;
  for (int i = 2; i <= n; i++) {
    if (a[Ask[i]] > a[Ask[lt]]) {
      lat[Ask[i]] = a[Ask[lt]] + 1;
      lt = i;
      bl[Ask[i]] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (b[i] <= mx) que.push(make_pair(-b[i], i));
  }
  int ans = 0, tot = 0;
  while (que.size()) {
    pair<int, int> x = que.top();
    que.pop();
    int val = query(1, 1, mx, a[x.second], b[x.second]) + 1;
    if (bl[x.second])
      ans += query(1, 1, mx, lat[x.second], b[x.second]) + 1, ans %= mod;
    add(1, 1, mx, a[x.second], val);
  }
  printf("%d\n", ans);
}
