#include <bits/stdc++.h>
using namespace std;
const int N = 100005, K = 100005, M = 100005;
const int inf = 1000000005;
template <class T>
void read(T &x) {
  int sgn = 1;
  char ch;
  x = 0;
  for (ch = getchar(); (ch < '0' || ch > '9') && ch != '-'; ch = getchar())
    ;
  if (ch == '-') ch = getchar(), sgn = -1;
  for (; '0' <= ch && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  x *= sgn;
}
template <class T>
void write(T x) {
  if (x < 0)
    putchar('-'), write(-x);
  else if (x < 10)
    putchar(x + '0');
  else
    write(x / 10), putchar(x % 10 + '0');
}
int n, m, a[N], pre[N], val1[N], val2[N], b[M], c[M], tim[M], cnt;
int lowbit(int x) { return x & -x; }
struct fenwick {
  pair<int, int> bit[N + M];
  void init() {
    for (int i = 1; i <= n + m + 1; i++) bit[i] = make_pair(-inf, -1);
  }
  void add(int pos, pair<int, int> pi) {
    for (; pos <= n + m + 1; pos += lowbit(pos)) bit[pos] = max(bit[pos], pi);
  }
  pair<int, int> query(int pos) {
    pair<int, int> ans = make_pair(-inf, -1);
    for (; pos; pos ^= lowbit(pos)) ans = max(ans, bit[pos]);
    return ans;
  }
  void clear(int pos) {
    for (; pos <= n + m + 1; pos += lowbit(pos)) bit[pos] = make_pair(-inf, -1);
  }
} bit1, bit2;
int f[N], prv[N];
vector<int> id;
bool cmp(int x, int y) {
  if (a[x] < a[y])
    return true;
  else if (a[x] > a[y])
    return false;
  else
    return x > y;
}
void solve(int l, int r) {
  if (l == r) return;
  int mid = l + r >> 1;
  solve(l, mid), id.clear();
  for (int i = l; i <= r; i++) {
    if (a[i] != -1) id.push_back(i);
  }
  sort(id.begin(), id.end(), cmp);
  for (int i = 0; i < id.size(); i++) {
    if (id[i] <= mid) {
      bit1.add(pre[id[i]] - val2[id[i]] + m + 1,
               make_pair(f[id[i]] - val2[id[i]], id[i]));
      bit2.add(n + 1 - pre[id[i]] + val2[id[i]],
               make_pair(f[id[i]] - pre[id[i]], id[i]));
    } else {
      pair<int, int> pi1 = bit1.query(pre[id[i]] - val1[id[i]] + m + 1);
      pair<int, int> pi2 = bit2.query(n + 1 - pre[id[i]] + val1[id[i]]);
      if (f[id[i]] < pi1.first + val1[id[i]] + 1) {
        f[id[i]] = pi1.first + val1[id[i]] + 1;
        prv[id[i]] = pi1.second;
      }
      if (f[id[i]] < pi2.first + pre[id[i]] + 1) {
        f[id[i]] = pi2.first + pre[id[i]] + 1;
        prv[id[i]] = pi2.second;
      }
    }
  }
  for (int i = 0; i < id.size(); i++) {
    if (id[i] <= mid) {
      bit1.clear(pre[id[i]] - val2[id[i]] + m + 1);
      bit2.clear(n + 1 - pre[id[i]] + val2[id[i]]);
    }
  }
  solve(mid + 1, r);
}
int main() {
  read(n);
  for (int i = 1; i <= n; i++) read(a[i]);
  read(m);
  for (int i = 1; i <= m; i++) read(b[i]);
  a[0] = -inf, a[n + 1] = inf;
  pre[0] = 0;
  for (int i = 1; i <= n + 1; i++) pre[i] = pre[i - 1] + (a[i] == -1);
  for (int i = 1; i <= m; i++) c[i] = b[i];
  sort(c + 1, c + m + 1);
  cnt = unique(c + 1, c + m + 1) - c - 1;
  for (int i = 1; i <= cnt; i++) tim[i] = 0;
  for (int i = 1; i <= m; i++) tim[lower_bound(c + 1, c + cnt + 1, b[i]) - c]++;
  for (int i = 0; i <= n + 1; i++) {
    val1[i] = lower_bound(c + 1, c + cnt + 1, a[i]) - c - 1;
    val2[i] = lower_bound(c + 1, c + cnt + 1, a[i] + 1) - c - 1;
  }
  for (int i = 0; i <= n + 1; i++) f[i] = -inf, prv[i] = -1;
  f[0] = 0, bit1.init(), bit2.init();
  solve(0, n + 1);
  int now = n + 1;
  for (; now; now = prv[now]) {
    int pos = val1[now];
    for (int i = now; i >= prv[now]; i--) {
      if (a[i] == -1 && pos > val2[prv[now]]) tim[pos]--, a[i] = c[pos--];
    }
  }
  for (int i = 1, j = 1; i <= n; i++) {
    if (a[i] == -1) {
      while (!tim[j]) j++;
      a[i] = c[j], tim[j]--;
    }
  }
  for (int i = 1; i <= n; i++) write(a[i]), putchar(' ');
  putchar('\n');
  return 0;
}
