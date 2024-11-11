#include <bits/stdc++.h>
using namespace std;
template <typename T>
bool cmax(T &a, T b) {
  return (a < b) ? a = b, 1 : 0;
}
template <typename T>
bool cmin(T &a, T b) {
  return (a > b) ? a = b, 1 : 0;
}
template <typename T>
T read() {
  T ans = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch) && ch != '-') ch = getchar();
  if (ch == '-') f = -1, ch = getchar();
  while (isdigit(ch))
    ans = (ans << 3) + (ans << 1) + (ch - '0'), ch = getchar();
  return ans * f;
}
template <typename T>
void write(T x, char y) {
  if (x == 0) {
    putchar('0'), putchar(y);
    return;
  }
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  static char wr[20];
  int top = 0;
  for (; x; x /= 10) wr[++top] = x % 10 + '0';
  while (top) putchar(wr[top--]);
  putchar(y);
}
void file() {}
const int N = 1e5 + 5;
int n;
long long K;
long long w[N], g[N];
long long pre[N], suf[N];
void input() {
  n = read<int>(), K = read<long long>();
  for (register int i = (int)(1); i <= (int)(n - 1); ++i) w[i] = read<int>();
  for (register int i = (int)(1); i <= (int)(n); ++i) g[i] = read<int>();
}
int st[N], top;
vector<int> E[N];
int nex[N];
long long lazy[N << 2], mp[N << 2], ms[N << 2], mans[N << 2];
void put_tag(int h, long long val) {
  ms[h] += val, mans[h] += val;
  lazy[h] += val;
}
void push_down(int h) {
  if (!lazy[h]) return;
  put_tag(h << 1, lazy[h]);
  put_tag(h << 1 | 1, lazy[h]);
  lazy[h] = 0;
}
long long cal(int h, int l, int r, long long t) {
  if (l == r) return mp[h] + t;
  push_down(h);
  if (ms[h << 1] >= t)
    return min(cal(h << 1, l, ((l + r) >> 1), t), mans[h]);
  else
    return min(t + mp[h << 1], cal(h << 1 | 1, ((l + r) >> 1) + 1, r, t));
}
void push_up(int h, int l, int r) {
  ms[h] = max(ms[h << 1], ms[h << 1 | 1]);
  mp[h] = min(mp[h << 1], mp[h << 1 | 1]);
  mans[h] = cal(h << 1 | 1, ((l + r) >> 1) + 1, r, ms[h << 1]);
}
void build(int h, int l, int r) {
  if (l == r) {
    ms[h] = suf[l];
    mp[h] = -suf[l];
    return;
  }
  build(h << 1, l, ((l + r) >> 1)), build(h << 1 | 1, ((l + r) >> 1) + 1, r);
  push_up(h, l, r);
}
int solve(int h, int l, int r, long long t) {
  if (l == r) return t + mp[h] <= K ? l : 0;
  push_down(h);
  if (t + mp[h << 1 | 1] <= K)
    return solve(h << 1 | 1, ((l + r) >> 1) + 1, r, t);
  else
    return solve(h << 1, l, ((l + r) >> 1), t);
}
int query(int h, int l, int r, long long t) {
  if (l == r) return t + mp[h] <= K ? l : 0;
  push_down(h);
  if (ms[h << 1] >= t) {
    if (mans[h] <= K)
      return query(h << 1 | 1, ((l + r) >> 1) + 1, r, ms[h << 1]);
    else
      return query(h << 1, l, ((l + r) >> 1), t);
  } else
    return max(solve(h << 1, l, ((l + r) >> 1), t),
               query(h << 1 | 1, ((l + r) >> 1) + 1, r, t));
}
void update(int h, int l, int r, int s, int t, long long val) {
  if (s > t) return;
  if (s <= l && r <= t)
    put_tag(h, val);
  else {
    push_down(h);
    if (s <= ((l + r) >> 1)) update(h << 1, l, ((l + r) >> 1), s, t, val);
    if (((l + r) >> 1) < t)
      update(h << 1 | 1, ((l + r) >> 1) + 1, r, s, t, val);
    push_up(h, l, r);
  }
}
const long long inf = 1e18;
void init() {
  w[n] = inf;
  for (register int i = (int)(1); i <= (int)(n); ++i)
    pre[i] = pre[i - 1] + g[i] - w[i], suf[i] = suf[i - 1] + g[i] - w[i - 1];
  st[0] = n;
  for (register int i = (int)(n - 1); i >= (int)(0); --i) {
    while (top && pre[st[top]] >= pre[i]) top--;
    nex[i + 1] = st[top] + 1;
    E[nex[i + 1]].push_back(i + 1);
    st[++top] = i;
  }
  build(1, 1, n);
}
int Ans;
void dfs(int u) {
  st[++top] = u;
  if (u != n + 1) {
    update(1, 1, n, 1, u - 1, -inf);
    update(1, 1, n, nex[u] - 1, n, pre[u - 1] - pre[nex[u] - 1]);
    int l = 1, r = top, mid, res = -1;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (pre[u - 1] - pre[st[mid] - 1] <= K)
        res = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    assert(~res);
    update(1, 1, n, st[res - 1], n, inf);
    cmax(Ans, query(1, 1, n, -inf) - u + 1);
    update(1, 1, n, st[res - 1], n, -inf);
    update(1, 1, n, 1, u - 1, inf);
  }
  for (int v : E[u]) dfs(v);
  if (u != n + 1) update(1, 1, n, nex[u] - 1, n, pre[nex[u] - 1] - pre[u - 1]);
}
void work() {
  top = 0;
  dfs(n + 1);
  write(Ans, '\n');
}
int main() {
  file();
  input();
  init();
  work();
  return 0;
}
