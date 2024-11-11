#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const int INF = (int)(1e9 + 1337);
const long long LINF = (long long)(1e18);
const double EPS = 1e-11;
const int MOD = 1000000007;
const int HBASE = 1003;
inline int add(int a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
  return a;
}
inline int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
  return a;
}
inline int mul(int a, int b) { return (long long)a * b % MOD; }
inline int bin_pow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = mul(res, a);
    }
    b >>= 1;
    a = mul(a, a);
  }
  return res;
}
const int MAXN = 25;
int n, st;
int sl[MAXN], sr[MAXN];
char ssl[MAXN], ssr[MAXN];
int cnt[10], c[10];
long long l, r;
int ans;
void check() {
  for (int i = sl[st] + 1; i < sr[st]; i++) {
    if (cnt[i]) {
      ans++;
      return;
    }
  }
  if (cnt[sl[st]]) {
    memcpy(c, cnt, sizeof(int) * 10);
    c[sl[st]]--;
    int mx = 9;
    while (!c[mx] && mx >= 0) {
      mx--;
    }
    bool fail = false;
    for (int i = st + 1; i < n; i++) {
      if (sl[i] < mx) {
        ans++;
        return;
      }
      if (!c[sl[i]]) {
        fail = true;
        break;
      }
      c[sl[i]]--;
      while (!cnt[mx] && mx >= 0) {
        mx--;
      }
    }
    if (!fail) {
      ans++;
      return;
    }
  }
  if (cnt[sr[st]]) {
    memcpy(c, cnt, sizeof(int) * 10);
    c[sr[st]]--;
    int mn = 0;
    while (!c[mn] && mn < 10) {
      mn++;
    }
    bool fail = false;
    for (int i = st + 1; i < n; i++) {
      if (sr[i] > mn) {
        ans++;
        return;
      }
      if (!c[sr[i]]) {
        fail = true;
        break;
      }
      c[sr[i]]--;
      while (!cnt[mn] && mn < 10) {
        mn++;
      }
    }
    if (!fail) {
      ans++;
      return;
    }
  }
}
void calc(int pos, int d) {
  if (pos == n) {
    check();
    return;
  }
  for (int i = d; i < 10; i++) {
    cnt[i]++;
    calc(pos + 1, i);
    cnt[i]--;
  }
}
void init() { scanf("%lld%lld", &l, &r); }
void solve() {
  init();
  if (l == r) {
    printf("1\n");
    return;
  }
  if (r == 1000000000000000000) {
    --r;
    if (l > 100000000000000000) {
      ans++;
    }
  }
  sprintf(ssr, "%lld", r);
  sprintf(ssl, "%lld", l);
  n = strlen(ssr);
  int d = strlen(ssr) - strlen(ssl);
  if (d) {
    for (int i = n - 1; i >= 0; i--) {
      if (i >= d) {
        ssl[i] = ssl[i - d];
      } else {
        ssl[i] = '0';
      }
    }
  }
  for (st = 0; st < n; st++) {
    if (ssl[st] != ssr[st]) {
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    sl[i] = ssl[i] - '0';
    sr[i] = ssr[i] - '0';
  }
  if (st == n - 1) {
    printf("%d\n", sr[n - 1] - sl[n - 1] + 1);
    return;
  }
  calc(st, 0);
  printf("%d\n", ans);
}
void precalc() {}
int main() {
  srand(333);
  double st = clock();
  int t = 1;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
