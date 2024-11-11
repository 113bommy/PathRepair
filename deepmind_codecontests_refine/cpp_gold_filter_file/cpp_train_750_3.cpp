#include <bits/stdc++.h>
using namespace std;
void read(int &x) {
  x = 0;
  int f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -f;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  x *= f;
}
void print(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (!x) return;
  print(x / 10), putchar(x % 10 + 48);
}
void write(int x) {
  if (!x)
    putchar('0');
  else
    print(x);
  putchar('\n');
}
const int maxn = 1e6 + 10;
const int inf = 1e9;
const double eps = 1e-8;
const int mod = 1e9 + 7;
int p[maxn], sta[maxn], top, c[26], n, tot, vis[maxn];
char s[maxn];
vector<pair<int, int> > ans;
int check() {
  int mx = 0, sum = 0;
  for (int i = 0; i < 26; i++) mx = max(mx, c[i]), sum += c[i];
  if (sum / 2 <= mx) return 1;
  return 0;
}
struct segment_tree {
  int t[maxn << 2], tag[maxn << 2];
  void push(int p) { tag[p << 1] = tag[p << 1 | 1] = 1, t[p] = 0; }
  void pushdown(int p) {
    if (!tag[p]) return;
    push(p << 1), push(p << 1 | 1);
  }
  void build(int p, int l, int r) {
    tag[p] = 0, t[p] = r - l + 1;
    if (l == r) return t[p << 1] = t[p << 1 | 1] = 0, void();
    build(p << 1, l, ((l + r) >> 1)), build(p << 1 | 1, ((l + r) >> 1) + 1, r);
  }
  void cov(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return push(p), void();
    pushdown(p);
    if (x <= ((l + r) >> 1)) cov(p << 1, l, ((l + r) >> 1), x, y);
    if (y > ((l + r) >> 1)) cov(p << 1 | 1, ((l + r) >> 1) + 1, r, x, y);
    t[p] = t[p << 1] + t[p << 1 | 1];
  }
  int query(int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return t[p];
    pushdown(p);
    int ans = 0;
    if (x <= ((l + r) >> 1)) ans += query(p << 1, l, ((l + r) >> 1), x, y);
    if (y > ((l + r) >> 1))
      ans += query(p << 1 | 1, ((l + r) >> 1) + 1, r, x, y);
    return ans;
  }
} T;
void put(int x, int y) {
  ans.push_back(
      make_pair(max(1, T.query(1, 1, n, 1, x)), T.query(1, 1, n, 1, y)));
  T.cov(1, 1, n, x, y);
}
void solve() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  T.build(1, 1, n);
  for (int i = 1; i <= n; i++) s[i] -= 'a';
  for (int i = 1; i < n; i++)
    if (s[i] == s[i + 1]) p[++tot] = i, c[s[i]]++;
  for (int i = 1; i <= tot; i++) {
    if (check()) break;
    if (!top || s[p[sta[top]]] == s[p[i]])
      sta[++top] = i;
    else {
      put(p[sta[top]] + 1, p[i]);
      vis[i] = 1, vis[sta[top]] = 1;
      c[s[p[sta[top]]]]--, c[s[p[i]]]--;
      top--;
    }
  }
  top = 0;
  int col = 0, mx = 0;
  for (int i = 0; i < 26; i++) {
    if (c[i] > mx) mx = c[i], col = i;
  }
  for (int i = 1; i <= tot; i++) {
    if (vis[i]) continue;
    if (!top)
      sta[++top] = i;
    else if ((s[p[sta[top]]] == col) + (s[p[i]] == col) == 1) {
      put(p[sta[top]] + 1, p[i]);
      top--;
    } else
      sta[++top] = i;
  }
  if (top)
    put(1, p[sta[1]]), put(p[sta[top]] + 1, n);
  else
    put(1, n);
  for (int i = 2; i <= top; i++) put(p[sta[i - 1]] + 1, p[sta[i]]);
  write(ans.size());
  for (auto x : ans) printf("%d %d\n", x.first, x.second);
}
void clear() {
  ans.clear();
  top = tot = 0;
  for (int i = 1; i <= n; i++) p[i] = vis[i] = 0;
  memset(c, 0, sizeof c);
}
int main() {
  int t;
  read(t);
  while (t--) solve(), clear();
  return 0;
}
