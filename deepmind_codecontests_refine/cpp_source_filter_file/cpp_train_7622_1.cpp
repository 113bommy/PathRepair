#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f = ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
  return f ? -x : x;
}
const int N = 300005, S = N * 30, mod = 1e9 + 7;
int Pow(int x, int y) {
  int ans = 1;
  for (; y; y >>= 1, x = (long long)x * x % mod)
    if (y & 1) ans = (long long)ans * x % mod;
  return ans;
}
void Add(int &x, int y) {
  if ((x += y) >= mod) x -= mod;
}
void Del(int &x, int y) {
  if ((x -= y) < 0) x += mod;
}
int Add(int x) { return x >= mod ? x - mod : x; }
int Del(int x) { return x < 0 ? x + mod : x; }
int n;
int a[N], val[N * 2], p2[N * 2];
int ls[S], rs[S];
int cnt[S], lv[S], rv[S], sum[S];
int ndcnt = 0, rt = 0;
int st[N], top = 0;
void recover(int &x) {
  ls[x] = rs[x] = cnt[x] = lv[x] = rv[x] = sum[x] = 0;
  st[++top] = x;
  x = 0;
}
int newnode() { return top ? st[top--] : ++ndcnt; }
void pushup(int rt) {
  sum[rt] = ((long long)lv[ls[rt]] * rv[rs[rt]] +
             (long long)sum[ls[rt]] * p2[cnt[rs[rt]]] +
             (long long)sum[rs[rt]] * p2[cnt[ls[rt]]]) %
            mod;
  lv[rt] = ((long long)lv[rs[rt]] * p2[cnt[ls[rt]]] + lv[ls[rt]]) % mod;
  rv[rt] = ((long long)rv[ls[rt]] * p2[cnt[rs[rt]]] + rv[rs[rt]]) % mod;
  cnt[rt] = cnt[ls[rt]] + cnt[rs[rt]];
}
void upd(int &rt, int L, int R, int x, int d) {
  if (!rt) rt = newnode();
  if (L == R) {
    cnt[rt] += d;
    sum[rt] = (long long)val[cnt[rt]] * L % mod * L % mod;
    lv[rt] = rv[rt] = (long long)(p2[cnt[rt]] - 1) * L % mod;
    if (cnt[rt] == 0) recover(rt);
    return;
  }
  int mid = (L + R) >> 1;
  if (x <= mid)
    upd(ls[rt], L, mid, x, d);
  else
    upd(rs[rt], mid + 1, R, x, d);
  pushup(rt);
  if (cnt[rt] == 0) recover(rt);
}
int main() {
  n = read();
  for (int i = (1); i <= (n); i++) a[i] = read();
  int q = read();
  val[0] = val[1] = 0;
  int cc = Pow(2, mod - 1 - n);
  p2[0] = 1;
  for (int i = (1); i <= (n + q); i++) p2[i] = p2[i - 1] * 2 % mod;
  for (int i = (2); i <= (n + q); i++)
    val[i] = (2LL * val[i - 1] + p2[i - 1] - 1) % mod;
  for (int i = (1); i <= (n); i++) upd(rt, 1, 1000000000, a[i], 1);
  cout << (long long)sum[rt] * cc % mod << endl;
  while (q--) {
    int i = read(), x = read();
    upd(rt, 1, 1000000000, a[i], -1);
    upd(rt, 1, 1000000000, a[i] = x, 1);
    cout << (long long)sum[rt] * cc % mod << endl;
  }
  return 0;
}
