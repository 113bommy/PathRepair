#include <bits/stdc++.h>
using namespace std;
const long long int MOD = 1000000009;
const long long BIG = 1446803456761533460LL;
const int Big = 336860180;
const long long int INF = LONG_LONG_MAX;
const long long int adj4[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const long long int adj8[8][2] = {{0, 1},   {0, -1}, {1, 0},  {-1, 0},
                                  {-1, -1}, {1, -1}, {-1, 1}, {1, 1}};
long long int clk_ar[10];
long long int gcd(long long int a, long long int b) {
  return b == 0 ? a : gcd(b, a % b);
}
long long int powMod(long long int a, long long int b) {
  long long int n = 1;
  long long int p = a;
  while (b > 0) {
    if (b % 2 == 1) {
      n *= p;
      n %= MOD;
    }
    p *= p;
    p %= MOD;
    b /= 2;
  }
  return n;
}
long long int modularInverse(long long int a) { return powMod(a, MOD - 2); }
long long int binarysearch(long long int l, long long int r,
                           bool (*bsfunction)(long long int)) {
  while (r - l > 1) {
    long long int mid = (l + r) / 2;
    bool val = bsfunction(mid);
    if (val) {
      r = mid;
    } else {
      l = mid;
    }
  }
  return l;
}
stringstream sss;
const long long int maxn = 300010;
long long int n, Q;
long long int fib[maxn];
long long int ar[maxn];
long long int lazy[maxn * 4][2];
long long int seg[maxn * 4];
bool mark[maxn * 4];
void build(long long int x = 1, long long int l = 0, long long int r = n) {
  if (r - l == 1) {
    seg[x] = ar[l];
  } else {
    long long int mid = (l + r) / 2;
    build(x * 2, l, mid);
    build(x * 2 + 1, mid, r);
    seg[x] = (seg[x * 2] + seg[x * 2 + 1]) % MOD;
  }
}
void push(long long int x, long long int l, long long int r) {
  long long int mid = (l + r) / 2;
  long long int fibr =
      (lazy[x][0] * fib[r - l] % MOD + lazy[x][1] * fib[r - l - 1] % MOD) % MOD;
  long long int fibm0 =
      (lazy[x][0] * fib[mid - l] % MOD + lazy[x][1] * fib[mid - l - 1] % MOD) %
      MOD;
  long long int fibm1 =
      (lazy[x][0] * fib[mid - l - 1] % MOD +
       lazy[x][1] * (mid - l - 2 < 0 ? 0 : fib[mid - l - 2]) % MOD) %
      MOD;
  long long int fibl = lazy[x][0];
  seg[x * 2] = (seg[x * 2] + fibm0 - fibl + MOD) % MOD;
  lazy[x * 2][0] = (lazy[x * 2][0] + lazy[x][0]) % MOD;
  lazy[x * 2][1] = (lazy[x * 2][1] + lazy[x][1]) % MOD;
  mark[x * 2] = true;
  seg[x * 2 + 1] = (seg[x * 2 + 1] + fibr - fibm0 + MOD) % MOD;
  lazy[x * 2 + 1][0] = (lazy[x * 2 + 1][0] + fibm0) % MOD;
  lazy[x * 2 + 1][1] = (lazy[x * 2 + 1][1] + fibm1) % MOD;
  mark[x * 2 + 1] = true;
  lazy[x][0] = 0;
  lazy[x][1] = 0;
  mark[x] = false;
}
void update(long long int li, long long int ri, long long int x = 1,
            long long int l = 0, long long int r = n) {
  if (li >= r || l >= ri) {
    return;
  }
  if (li <= l && r <= ri) {
    seg[x] = (seg[x] + fib[r - li + 1] - fib[l - li + 1] + MOD) % MOD;
    lazy[x][0] = (lazy[x][0] + fib[l - li + 1]) % MOD;
    lazy[x][1] = (lazy[x][1] + fib[l - li]) % MOD;
    mark[x] = true;
  } else {
    if (mark[x]) {
      push(x, l, r);
    }
    long long int mid = (l + r) / 2;
    update(li, ri, x * 2, l, mid);
    update(li, ri, x * 2 + 1, mid, r);
    seg[x] = (seg[x * 2] + seg[x * 2 + 1]) % MOD;
  }
}
long long int get(long long int li, long long int ri, long long int x = 1,
                  long long int l = 0, long long int r = n) {
  if (li >= r || l >= ri) {
    return 0;
  }
  if (li <= l && r <= ri) {
    return seg[x];
  } else {
    if (mark[x]) {
      push(x, l, r);
    }
    long long int mid = (l + r) / 2;
    long long int a = get(li, ri, x * 2, l, mid);
    long long int b = get(li, ri, x * 2 + 1, mid, r);
    return (a + b) % MOD;
  }
}
void MAIN() {
  fib[0] = fib[1] = 1;
  for (long long int i = (2); i < (maxn); ++i) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  cin >> n >> Q;
  for (long long int i = 0; i < (n); ++i) {
    cin >> ar[i];
  }
  build();
  for (long long int q = 0; q < (Q); ++q) {
    long long int t, l, r;
    cin >> t >> l >> r;
    --l;
    if (t == 1) {
      update(l, r);
    } else if (t == 2) {
      cout << (get(l, r)) << '\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  sss << R"(
4 4
1 2 3 4
1 1 4
2 1 4
1 2 4
2 1 3
    )";
  MAIN();
  return 0;
}
