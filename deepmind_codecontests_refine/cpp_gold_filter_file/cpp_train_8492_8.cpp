#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  register int c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
inline void writeln(int x) {
  char buffor[21];
  register int i = 0;
  int neg = 0;
  if (x < 0) {
    neg = 1;
    x = -x;
  }
  do {
    buffor[i++] = (x % 10) + '0';
    x /= 10;
  } while (x);
  i--;
  if (neg) putchar('-');
  while (i >= 0) putchar(buffor[i--]);
  putchar('\n');
}
const int N = (int)1e5 + 10;
int n, a[N];
struct node {
  int l, r, sum;
  node(){};
  node(int l, int r, int sum) : l(l), r(r), sum(sum){};
};
int root[N];
int all = 0;
node it[50 * N];
int last[N];
void input() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
}
void cal(int x) { it[x].sum = it[it[x].l].sum + it[it[x].r].sum; }
int update(int L, int R, int u, int val, int oldid) {
  if (L == R) {
    it[++all] = node(L, R, val);
    return all;
  }
  int M = (L + R) / 2;
  int cur = ++all;
  if (u <= M) {
    it[cur].l = update(L, M, u, val, it[oldid].l);
    it[cur].r = it[oldid].r;
    cal(cur);
  }
  if (u > M) {
    it[cur].l = it[oldid].l;
    it[cur].r = update(M + 1, R, u, val, it[oldid].r);
    cal(cur);
  }
  return cur;
}
pair<int, int> query(int x, int l, int r, int R, int k) {
  if (l > R || x == 0) return pair<int, int>(0, 0);
  if (it[x].sum < k) return pair<int, int>(it[x].sum, 0);
  if (l == r) return pair<int, int>(it[x].sum, l);
  int m = (l + r) / 2;
  pair<int, int> tmp = query(it[x].r, m + 1, r, R, k);
  if (tmp.first >= k) return tmp;
  pair<int, int> tmp2 = query(it[x].l, l, m, R, k - tmp.first);
  tmp2.first += tmp.first;
  return tmp2;
}
void build_it() {
  for (int i = 1; i <= n; i++) {
    root[i] = update(1, n, i, 1, root[i - 1]);
    if (last[a[i]] != 0) root[i] = update(1, n, last[a[i]], 0, root[i]);
    last[a[i]] = i;
  }
}
void solve() {
  build_it();
  for (int k = 1; k <= n; k++) {
    int cur = n;
    int d = 0;
    while (cur > 0) {
      cur = query(root[cur], 1, n, cur, k + 1).second;
      d++;
    }
    cout << d << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  input();
  solve();
  return 0;
}
