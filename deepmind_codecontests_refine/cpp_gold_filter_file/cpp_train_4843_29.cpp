#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int C = 26;
void add(int &x, int y) {
  x += y;
  while (x >= MOD) x -= MOD;
  while (x < 0) x += MOD;
}
int fix(int x) {
  while (x >= MOD) x -= MOD;
  while (x < 0) x += MOD;
  return x;
}
int pw(int a, int b) {
  int ret = 1;
  while (b) {
    if (b & 1) ret = 1ll * ret * a % MOD;
    b >>= 1;
    a = 1ll * a * a % MOD;
  }
  return ret;
}
const int MAXN = 1e6 + 10;
long long n, A, c[2], m;
long long a[MAXN], pre[MAXN];
int sec[MAXN];
void solve() {
  cin >> n >> A >> c[0] >> c[1] >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  iota(sec, sec + n, 0);
  sort(sec, sec + n, [](int i, int j) { return a[i] < a[j]; });
  for (int i = 0; i < n; i++) {
    pre[i + 1] = pre[i] + a[sec[i]];
  }
  tuple<long long, long long, long long> best = {-1, -1, -1};
  for (int r = n; ~r; --r) {
    long long have = pre[n] - pre[r];
    long long want = A * (n - r);
    long long need = want - have;
    if (need > m) {
      break;
    }
    long long rem = m - need;
    long long small = 0;
    for (int i = 30; ~i; --i) {
      long long maybe = small + (1LL << i);
      if (maybe <= A) {
        int j = r;
        for (int k = 20; ~k; --k) {
          if (j - (1 << k) >= 0 && a[sec[j - (1 << k)]] >= maybe) {
            j -= 1 << k;
          }
        }
        need = maybe * j - pre[j];
        if (need <= rem) {
          small = maybe;
        }
      }
    }
    best = max(best,
               make_tuple(c[0] * (n - r) + c[1] * small, (long long)r, small));
  }
  auto [score, r, lo] = best;
  cout << score << "\n";
  for (int i = 0; i < n; i++) {
    if (i < r) {
      a[sec[i]] = max(a[sec[i]], lo);
    } else {
      a[sec[i]] = A;
    }
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  cout << "\n";
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int te = 1;
  for (int w = 1; w <= te; w++) {
    solve();
  }
  return 0;
}
