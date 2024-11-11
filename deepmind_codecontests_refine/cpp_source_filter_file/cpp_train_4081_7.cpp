#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x) {
  x = 0;
  int f = 1;
  char c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
  x *= f;
}
const int N = 100010, mod = 1e9 + 7, inv2 = 5e8 + 4;
int n, m, l, id[N], pw[N], st[N], vis[N], inv[N];
vector<int> e[N], in[N];
vector<vector<int> > cyc;
int sum(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
int sub(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
int mul(int x, int y) { return 1ll * x * y % mod; }
void dfs(int x, int las = 0) {
  vis[x] = 1, st[id[x] = ++l] = x;
  for (int y : e[x]) {
    if (vis[y] == 2) continue;
    if (y == las) continue;
    if (vis[y]) {
      vector<int> tmp;
      tmp.clear();
      for (int i = id[y]; i <= l; i++) tmp.push_back(st[i]);
      cyc.push_back(tmp);
    } else
      dfs(y, x);
  }
  vis[x] = 2, st[l--] = 0;
}
int ver() { return sum(mul(n, inv[1]), mul(mul(n, n - 1), inv[2])); }
int edge() {
  int ret = mul(m, inv[2]);
  for (int x = 1; x <= n; x++)
    for (int y : e[x]) {
      if (x > y) continue;
      int s1 = m - e[x].size() - e[y].size() + 1,
          s2 = e[x].size() + e[y].size() - 2;
      ret = sum(ret, mul(s1, inv[4])), ret = sum(ret, mul(s2, inv[3]));
    }
  return ret;
}
int cycle() {
  int tmp = 0, ret = 0;
  for (auto cir : cyc) tmp = sum(tmp, inv[cir.size()]);
  for (auto cir : cyc) {
    int siz = cir.size(), val = tmp;
    ret = sum(ret, inv[siz]);
    for (int x : cir) {
      for (int s : in[x]) val = sub(val, inv[s]);
      val = sum(val, inv[siz]);
    }
    val = sub(val, inv[siz]), ret = sum(ret, mul(inv[siz], val));
    int res = sub(tmp, sum(val, inv[siz]));
    ret = sum(ret, mul(mul(res, 2), inv[siz]));
  }
  return ret;
}
int veredge() {
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    int s1 = e[i].size(), s2 = m - e[i].size();
    ret = sum(ret, mul(s1, inv[2])), ret = sum(ret, mul(s2, inv[3]));
  }
  return ret;
}
int vercycle() {
  int tmp = 0, ret = 0;
  for (auto cir : cyc) tmp = sum(tmp, inv[cir.size()]);
  for (int i = 1; i <= n; i++) {
    int ts = 0;
    for (int x : in[i]) ts = sum(ts, inv[x]);
    ret = sum(ret, ts), ret = sum(ret, mul(sub(tmp, ts), inv[1]));
  }
  return ret;
}
int edgecycle() {
  int ret = 0;
  for (auto cir : cyc) {
    int siz = cir.size(), ts = 0;
    ret = sum(ret, mul(siz, inv[siz]));
    for (int x : cir) ts += e[x].size() - 2;
    ret = sum(ret, mul(ts, inv[siz + 1]));
    ret = sum(ret, mul(m - siz - ts, inv[siz + 2]));
  }
  return ret;
}
int calc1() {
  int s1 = sum(ver(), sum(edge(), cycle())),
      s2 = sub(vercycle(), sum(veredge(), edgecycle()));
  return sum(s1, mul(s2, 2));
}
int calc2() {
  int ret = sub(mul(n, inv[1]), mul(m, inv[2]));
  for (auto cir : cyc) ret = sum(ret, inv[cir.size()]);
  return mul(ret, ret);
}
int main() {
  read(n), read(m), pw[0] = inv[0] = 1;
  for (int i = 1; i <= m; i++)
    pw[i] = mul(pw[i - 1], 2), inv[i] = mul(inv[i - 1], inv2);
  for (int i = 1; i <= m; i++) {
    int x, y;
    read(x), read(y);
    e[x].push_back(y), e[y].push_back(x);
  }
  dfs(1);
  for (auto cir : cyc)
    for (int i : cir) in[i].push_back(cir.size());
  cout << (calc1() - calc2() + mod) % mod << '\n';
  return 0;
}
