#include <bits/stdc++.h>
using namespace std;
template <typename T>
void maxtt(T& t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T& t1, T t2) {
  t1 = min(t1, t2);
}
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "no");
  exit(0);
}
void addmod(int& x, int y, int mod = 998244353) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 998244353) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
int a[1000035], pre[1000035], suf[1000035], lst[1000035], nxt[1000035];
int cnt;
void del(int l, int r) {
  pre[suf[r]] = pre[l];
  suf[pre[l]] = suf[r];
}
int gen() {
  ++cnt;
  while (lst[cnt]) cnt++;
  if (cnt > n) etp();
  lst[cnt] = -1;
  return cnt;
}
void cal(int l, int r) {
  if ((r - l) & 1) etp();
  for (int i = l; i <= r; i = suf[i]) {
    while (nxt[i]) {
      if (nxt[i] > r) etp();
      cal(suf[i], pre[nxt[i]]);
      del(suf[i], nxt[i]);
      nxt[i] = nxt[nxt[i]];
    }
  }
  int tt = 0, posi = 0, rt = a[pre[l]];
  for (int i = l; i <= r; i = suf[i]) {
    tt++;
    posi += a[i] > 0;
  }
  tt = (tt + 1) / 2;
  if (tt < posi) etp();
  for (int i = suf[l]; i <= r; i = suf[i])
    if (a[i] == 0 && posi < tt) {
      a[i] = gen();
      posi++;
    }
  if (tt == 1 && posi == 0) a[l] = gen();
  for (int i = l; suf[i] <= r; i = suf[i]) {
    while (i > l && suf[i] <= r && a[pre[i]] == 0 && a[i] && a[suf[i]]) {
      a[pre[i]] = a[suf[i]];
      del(i, suf[i]);
      i = pre[pre[i]];
    }
    while (suf[i] <= r && pre[i] >= l && a[pre[i]] && a[i] && a[suf[i]] == 0) {
      a[suf[i]] = a[pre[i]];
      del(i, suf[i]);
      i = pre[i];
    }
  }
  for (int i = l; i <= r; i = suf[i])
    if (a[i] == 0) a[i] = rt;
}
void fmain(int tid) {
  scanf("%d", &n);
  for (int(i) = 1; (i) <= (int)(n + n - 1); (i)++) scanf("%d", a + i);
  int N = n + n - 1;
  if (a[1] && a[N] && a[1] != a[N]) etp();
  if (a[1] == 0)
    a[1] = a[N];
  else
    a[N] = a[1];
  for (int(i) = 0; (i) < (int)(n + n); (i)++) {
    pre[i] = i - 1;
    suf[i] = i + 1;
  }
  for (int i = N; i; i--)
    if (a[i]) {
      nxt[i] = lst[a[i]];
      lst[a[i]] = i;
    }
  cal(1, N);
  puts("yes");
  for (int(i) = 1; (i) <= (int)(N); (i)++) printf("%d ", a[i]);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
