#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long ans;
int f[110000], son[110000];
int num, sum, n, root;
int e[210000], last[110000], pre[210000], w[210000], pp[110000], col[210000];
const int maxn = 410000;
const int base = 200005;
long long v1[maxn], n1[maxn];
long long v2[maxn], n2[maxn];
long long v3[maxn], n3[maxn];
long long v4[maxn], n4[maxn];
long long pow_mod(long long a, long long e) {
  long long res = 1;
  for (; e; a = a * a % mod, e >>= 1)
    if (e & 1) res = res * a % mod;
  return res;
}
long long ni(long long x) { return pow_mod(x, mod - 2); }
inline int lowbit(int x) { return x & -x; }
void add(long long v[], int x, long long y) {
  if (x == 0) return;
  for (int i = x; i < maxn; i += lowbit(i)) v[i] = (v[i] * y) % mod;
}
long long get(long long v[], int x) {
  long long res = 1;
  for (int i = x; i; i -= lowbit(i)) res = (res * v[i]) % mod;
  return res;
}
void add2(long long v[], int x, long long y) {
  if (x == 0) return;
  for (int i = x; i < maxn; i += lowbit(i)) v[i] += y;
}
long long get2(long long v[], int x) {
  long long res = 0;
  for (int i = x; i; i -= lowbit(i)) res += v[i];
  return res;
}
void getroot(int x, int fa) {
  son[x] = 1, f[x] = 0;
  for (int i = last[x]; i; i = pre[i])
    if (!pp[e[i]] && e[i] != fa) {
      getroot(e[i], x);
      son[x] += son[e[i]];
      f[x] = max(f[x], son[e[i]]);
    }
  f[x] = max(f[x], sum - son[x]);
  if (f[x] < f[root]) root = x;
}
void init(int x, int fa) {
  son[x] = 1;
  for (int i = last[x]; i; i = pre[i])
    if (!pp[e[i]] && e[i] != fa) init(e[i], x), son[x] += son[e[i]];
}
void cal(int x, int fa, int op, int b, int r, long long cost) {
  if (op == 0) {
    ans = (ans * get(v1, 2 * r - b + base)) % mod;
    ans = (ans * ni(get(v2, r - 2 * b - 1 + base))) % mod;
    ans = (ans * pow_mod(cost, get2(n1, 2 * r - b + base) -
                                   get2(n2, r - 2 * b - 1 + base))) %
          mod;
    if (b) {
      ans = (ans * get(v3, 2 * r - b + base)) % mod;
      ans = (ans * ni(get(v4, r - 2 * b - 1 + base))) % mod;
      ans = (ans * pow_mod(cost, get2(n3, 2 * r - b + base) -
                                     get2(n4, r - 2 * b - 1 + base))) %
            mod;
    }
  } else if (op == 1) {
    if (b) {
      add(v1, b - 2 * r + base, cost), add2(n1, b - 2 * r + base, 1);
      add(v2, 2 * b - r + base, cost), add2(n2, 2 * b - r + base, 1);
    } else {
      add(v3, b - 2 * r + base, cost), add2(n3, b - 2 * r + base, 1);
      add(v4, 2 * b - r + base, cost), add2(n4, 2 * b - r + base, 1);
    }
  } else {
    if (b) {
      add(v1, b - 2 * r + base, ni(cost)), add2(n1, b - 2 * r + base, -1);
      add(v2, 2 * b - r + base, ni(cost)), add2(n2, 2 * b - r + base, -1);
    } else {
      add(v3, b - 2 * r + base, ni(cost)), add2(n3, b - 2 * r + base, -1);
      add(v4, 2 * b - r + base, ni(cost)), add2(n4, 2 * b - r + base, -1);
    }
  }
  for (int i = last[x]; i; i = pre[i])
    if (!pp[e[i]] && e[i] != fa)
      cal(e[i], x, op, b + col[i], r + (col[i] ^ 1), cost * w[i] % mod);
}
void work(int x) {
  pp[x] = 1;
  init(x, 0);
  add2(n3, base, 1), add2(n4, base, 1);
  for (int i = last[x]; i; i = pre[i])
    if (!pp[e[i]]) {
      cal(e[i], x, 0, col[i], col[i] ^ 1, w[i]);
      cal(e[i], x, 1, col[i], col[i] ^ 1, w[i]);
    }
  for (int i = last[x]; i; i = pre[i])
    if (!pp[e[i]]) cal(e[i], x, -1, col[i], col[i] ^ 1, w[i]);
  add2(n3, base, -1), add2(n4, base, -1);
  for (int i = last[x]; i; i = pre[i])
    if (!pp[e[i]]) {
      root = 0, sum = son[e[i]];
      getroot(e[i], 0);
      work(root);
    }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    e[++num] = b, pre[num] = last[a], last[a] = num, w[num] = c, col[num] = d;
    e[++num] = a, pre[num] = last[b], last[b] = num, w[num] = c, col[num] = d;
  }
  for (int i = 0; i < maxn; i++) v1[i] = v2[i] = v3[i] = v4[i] = 1;
  f[0] = sum = n;
  ans = 1;
  work(1);
  cout << ans << endl;
  return 0;
}
