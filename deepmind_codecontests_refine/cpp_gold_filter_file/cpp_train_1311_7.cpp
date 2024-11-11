#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long Inf = 1e18;
const int N = 6e5 + 10;
const int mod = 0;
int gi() {
  int x = 0, o = 1;
  char ch = getchar();
  while ((ch < '0' || ch > '9') && ch != '-') ch = getchar();
  if (ch == '-') o = -1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x * o;
}
template <typename T>
bool chkmax(T &a, T b) {
  return a < b ? a = b, 1 : 0;
};
template <typename T>
bool chkmin(T &a, T b) {
  return a > b ? a = b, 1 : 0;
};
int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
void inc(int &a, int b) { a = (a + b >= mod ? a + b - mod : a + b); }
void dec(int &a, int b) { a = (a - b < 0 ? a - b + mod : a - b); }
int ls[N], rs[N], key[N], val[N], siz[N], tag[N];
int tot = 0;
void update(int o) { siz[o] = siz[ls[o]] + siz[rs[o]] + 1; }
void down(int o) {
  val[ls[o]] += tag[o];
  tag[ls[o]] += tag[o];
  val[rs[o]] += tag[o];
  tag[rs[o]] += tag[o];
  tag[o] = 0;
}
int newnode(int v) {
  int o = ++tot;
  key[o] = rand();
  val[o] = v;
  siz[o] = 1;
  return o;
}
int merge(int a, int b) {
  if (!a || !b) return a | b;
  down(a);
  down(b);
  if (key[a] < key[b])
    return rs[a] = merge(rs[a], b), update(a), a;
  else
    return ls[b] = merge(a, ls[b]), update(b), b;
}
pair<int, int> split(int o, int k) {
  if (!o) return make_pair(0, 0);
  pair<int, int> y;
  down(o);
  if (siz[ls[o]] >= k)
    y = split(ls[o], k), ls[o] = y.second, update(o), y.second = o;
  else
    y = split(rs[o], k - siz[ls[o]] - 1), rs[o] = y.first, update(o),
    y.first = o;
  return y;
}
int getkth(int o, int v) {
  if (!o) return 0;
  down(o);
  return val[o] >= v ? getkth(ls[o], v) : getkth(rs[o], v) + siz[ls[o]] + 1;
}
int count(int o) {
  if (!o) return 0;
  down(o);
  return count(ls[o]) + count(rs[o]) + (val[o] < inf);
}
int n, rt = 0;
int main() {
  srand(141905 + 141936);
  cin >> n;
  for (int i = 1; i <= n; i++) rt = merge(rt, newnode(inf));
  for (int i = 1; i <= n; i++) {
    int l = gi(), r = gi();
    int k = getkth(rt, l);
    pair<int, int> x = split(rt, k);
    k = getkth(x.second, r);
    pair<int, int> y = split(x.second, k);
    val[y.first]++;
    tag[y.first]++;
    pair<int, int> z = split(y.second, 1);
    rt = merge(x.first, newnode(l));
    rt = merge(rt, y.first);
    rt = merge(rt, z.second);
  }
  printf("%d\n", count(rt));
  return 0;
}
