#include <bits/stdc++.h>
using namespace std;
const int maxn = 2E5 + 5;
const long long int inf = 1E16;
int n, size, root, fa[maxn], son[maxn][2];
long long int a[maxn], val[maxn], sum[maxn], A[maxn], B[maxn];
void out() {
  for (int i = 1; i <= size; ++i) cout << fa[i] << " ";
  cout << endl;
  for (int i = 1; i <= size; ++i) cout << son[i][0] << " ";
  cout << endl;
  for (int i = 1; i <= size; ++i) cout << son[i][1] << " ";
  cout << endl;
  for (int i = 1; i <= size; ++i) cout << sum[i] << " ";
  cout << endl << endl;
}
inline void update(int num) {
  sum[num] = sum[son[num][0]] + sum[son[num][1]] + 1;
}
inline void add(int num, long long int x, long long int y) {
  val[num] += x * (son[sum[num]][0] + 1) + y;
  A[num] += x, B[num] += y;
}
inline void pushdown(int num) {
  if (A[num] | B[num]) {
    long long int x = A[num], y = B[num];
    A[num] = B[num] = 0;
    add(son[num][0], x, y);
    add(son[num][1], x, y + x * (sum[son[num][0]] + 1));
  }
}
inline void rotate(int x) {
  int y = fa[x];
  int c = son[y][0] == x;
  fa[x] = fa[y];
  son[y][!c] = son[x][c];
  if (son[x][c]) fa[son[x][c]] = y;
  if (son[fa[y]][0] == y)
    son[fa[y]][0] = x;
  else
    son[fa[y]][1] = x;
  son[x][c] = y;
  fa[y] = x;
  update(y);
  update(x);
  if (root == y) root = x;
}
void down(int x) {
  if (x == root) {
    pushdown(x);
    return;
  }
  down(fa[x]);
  pushdown(x);
}
inline void splay(int x, int to) {
  if (x == to) return;
  down(x);
  while (true) {
    int y = fa[x];
    if (x == root) break;
    if (y == to) {
      rotate(x);
      break;
    }
    if ((son[fa[y]][0] == y) == (son[y][0] == x))
      rotate(y), rotate(x);
    else
      rotate(x), rotate(x);
  }
}
inline long long int ask(int id) {
  int p = root;
  sum[0] = 0;
  while (true) {
    if (sum[son[p][0]] + 1 == id) break;
    if (sum[son[p][0]] >= id)
      p = son[p][0];
    else
      id -= sum[son[p][0]] + 1, p = son[p][1];
  }
  splay(p, root);
  return val[p];
}
long long int dfs(int num) {
  if (!num) return -inf;
  pushdown(num);
  return max(max(val[num], dfs(son[num][0])), dfs(son[num][1]));
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  sum[1] = root = size = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    int l = 0, r = i - 2, mid, ans = i - 1;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (ask(mid + 1) + a[i] * (mid + 1) > ask(mid + 2)) {
        ans = mid;
        r = mid - 1;
      } else
        l = mid + 1;
    }
    long long int x = ask(ans + 1);
    fa[++size] = root;
    fa[son[root][1]] = size;
    son[size][1] = son[root][1];
    son[root][1] = size;
    val[size] = val[root];
    add(size, a[i], a[i] * ans);
  }
  cout << dfs(root) << endl;
  return 0;
}
