#include <bits/stdc++.h>
using namespace std;
const int N = 600005;
int c[N], sa[N], rk[N], lim[N];
int one[N], other[N];
int st[N], in[N], pos[N];
map<int, int> two[N];
pair<int, int> eve[N], ask[N];
int ans[N];
int n, C;
int mx[N * 2];
void change(int k, int l, int r, int x, int v) {
  if (l == r) return mx[k] = v, void(0);
  int mid = (l + r) / 2;
  if (x <= mid)
    change(k * 2, l, mid, x, v);
  else
    change(k * 2 + 1, mid + 1, r, x, v);
  mx[k] = max(mx[k * 2], mx[k * 2 + 1]);
}
int askkk(int k, int l, int r, int x, int y) {
  if (l == x && r == y) return mx[k];
  int mid = (l + r) / 2;
  if (y <= mid) return askkk(k * 2, l, mid, x, y);
  if (x > mid) return askkk(k * 2 + 1, mid + 1, r, x, y);
  return max(askkk(k * 2, l, mid, x, mid),
             askkk(k * 2 + 1, mid + 1, r, mid + 1, y));
}
bool cmp(int x, int y) { return c[x] < c[y]; }
int cnt, Q, id[N];
int main() {
  scanf("%d%d", &n, &C);
  for (int i = (int)(1); i <= (int)(n); i++) {
    int l, r;
    scanf("%d%d%d", &l, &r, &c[i]);
    eve[++cnt] = pair<int, int>(l, i);
    eve[++cnt] = pair<int, int>(r, -i);
  }
  for (int i = (int)(1); i <= (int)(n); i++) id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  int k = n;
  for (int i = (int)(1); i <= (int)(n); i++) {
    rk[id[i]] = i;
    for (; k && c[id[i]] + c[id[k]] > C; k--)
      ;
    lim[i] = k;
  }
  scanf("%d", &Q);
  for (int i = (int)(1); i <= (int)(Q); i++) {
    int x;
    scanf("%d", &x);
    ask[i] = pair<int, int>(x, i);
  }
  sort(ask + 1, ask + Q + 1);
  int free = 0, top = 0, use = 0;
  eve[++cnt].first = 2147483647;
  sort(eve + 1, eve + cnt + 1);
  for (int i = 1, cur = 1; cur <= Q; i++) {
    int now = eve[i].first - eve[i - 1].first, k, t;
    if (top == 2 && c[k = st[1]] + c[t = st[2]] <= C) {
      two[k][t] += now;
      two[t][k] += now;
      other[k] = max(other[k], two[k][t] + one[t]);
      other[t] = max(other[t], two[k][t] + one[k]);
      use = max(use, one[k] + one[t] + two[k][t]);
    } else if (top == 1 && c[k = st[1]] <= C) {
      change(1, 1, n, rk[k], one[k] += now);
      use = max(use, one[k] + other[k]);
      if (rk[k] != 1 && lim[rk[k]])
        use = max(use, one[k] + askkk(1, 1, n, 1, min(rk[k] - 1, lim[rk[k]])));
      if (rk[k] != n && lim[rk[k]] > rk[k])
        use = max(use, one[k] + askkk(1, 1, n, rk[k] + 1, lim[rk[k]]));
    } else if (!top)
      free += now;
    if ((k = eve[i].second) > 0)
      st[pos[k] = ++top] = k;
    else
      t = pos[-k], pos[st[t] = st[top--]] = t;
    for (; cur <= Q && ask[cur].first <= free + use; cur++)
      ans[ask[cur].second] = eve[i].first - (free + use - ask[cur].first);
  }
  for (int i = (int)(1); i <= (int)(Q); i++) printf("%d\n", ans[i]);
}
