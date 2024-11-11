#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MINF = 0x3f3f3f3f;
const int MAXN = 200007;
const int MAX = 262144;
const int MAXS = MAX * 2 + 7;
class stT {
 public:
  void upd(int p, int x) {
    data[p += MAX - 1] = x;
    for (p >>= 1; p; p >>= 1)
      data[p] = (((data[p << 1]) < (data[p << 1 | 1])) ? (data[p << 1])
                                                       : (data[p << 1 | 1]));
  }
  void query(int l, int r, int k, int pl[], int &kp, int now = 1, int ll = 1,
             int rr = MAX) {
    if (data[now] > k) return;
    if (rr < l || ll > r)
      return;
    else if (ll == rr)
      pl[++kp] = ll;
    else {
      int mid = (ll + rr) >> 1;
      query(l, r, k, pl, kp, now << 1, ll, mid);
      query(l, r, k, pl, kp, now << 1 | 1, mid + 1, rr);
    }
  }

 private:
  int data[MAXS];
} st;
int n;
int sx[MAXN], sy[MAXN], tx[MAXN], ty[MAXN];
int pre[MAXN];
int pl[MAXN], kp, tpl[MAXN], kt;
int stk[MAXN], top;
vector<int> ar[MAXN];
void init();
void input();
void work();
int main() {
  init();
  input();
  work();
}
void init() { ios::sync_with_stdio(false); }
void input() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i)
    scanf("%d%d%d%d", &sx[i], &sy[i], &tx[i], &ty[i]);
}
void work() {
  map<int, int> mx, my;
  mx[0] = my[0] = 0;
  for (int i = 1; i <= n; ++i)
    mx[sx[i]] = mx[tx[i]] = 0, my[sy[i]] = my[ty[i]] = 0;
  int kx = 0, ky = 0;
  for (auto &x : mx) x.second = ++kx;
  for (auto &y : my) y.second = ++ky;
  for (int i = 1; i <= n; ++i)
    sx[i] = mx[sx[i]], sy[i] = my[sy[i]], tx[i] = mx[tx[i]], ty[i] = my[ty[i]];
  tx[0] = ty[0] = 1;
  for (int i = 1; i <= n; ++i) ar[sx[i]].push_back(i);
  for (int i = 1; i <= kx; ++i) {
    if (ar[i].size()) {
      sort(ar[i].begin(), ar[i].end(),
           [](int x, int y) { return sy[x] > sy[y]; });
      st.upd(i, sy[ar[i].back()]);
    } else
      st.upd(i, INF);
  }
  memset(pre, -1, sizeof(pre));
  pl[++kp] = 0;
  int px;
  while (1) {
    sort(pl + 1, pl + 1 + kp, [](int x, int y) {
      return (tx[x] ^ tx[y]) ? (tx[x] < tx[y]) : (ty[x] < ty[y]);
    });
    top = 0;
    for (int i = 1; i <= kp; ++i) {
      while (top && ty[pl[i]] >= ty[stk[top]]) --top;
      stk[++top] = pl[i];
    }
    kp = 0;
    px = 0;
    for (int i = 1; i <= top; ++i) {
      kt = 0;
      st.query(px + 1, tx[stk[i]], ty[stk[i]], tpl, kt);
      for (int j = 1; j <= kt; ++j) {
        while (ar[tpl[j]].size() && sy[ar[tpl[j]].back()] <= ty[stk[i]])
          pl[++kp] = ar[tpl[j]].back(), pre[pl[kp]] = stk[i],
          ar[tpl[j]].pop_back();
        st.upd(tpl[j], sy[ar[tpl[j]].size()] ? ar[tpl[j]].back() : INF);
      }
      px = tx[stk[i]];
    }
    if (!kp) break;
  }
  if (~pre[n]) {
    vector<int> ans;
    int now = n;
    while (now) ans.push_back(now), now = pre[now];
    reverse(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (auto x : ans) printf("%d ", x);
    putchar('\n');
  } else
    printf("-1\n");
}
