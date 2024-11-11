#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int block_size = 320;
const long long mod = 1e9 + 7;
const long double eps = 1e-9;
const int inf = mod;
template <typename T>
inline int sign(const T &a) {
  if (a < 0) return -1;
  if (a > 0) return 1;
  return 0;
}
template <typename T>
inline void read(T &x) {
  x = 0;
  T f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  x *= f;
}
const int maxn = 1000010;
long long ans[maxn];
long long dp[maxn];
int arr[maxn];
int n;
int q;
struct query {
  int step;
  int ori, start;
  bool operator<(const query &b) const { return step < b.step; }
};
query qs[maxn];
void read() {
  (read(n));
  for (long long i = 1; i < n + 1; i++) {
    (read(arr[i]));
  }
  (read(q));
  for (long long i = 0; i < q; i++) {
    (read(qs[i].start));
    (read(qs[i].step));
    qs[i].ori = i;
  }
  sort(qs, qs + q);
}
void solve() {
  for (int i = 0; i < q; i++) {
    if (i > 0 && qs[i].step == qs[i - 1].step && qs[i].step <= 500) {
      ans[qs[i].ori] = dp[qs[i].start];
    } else if (qs[i].step <= 500) {
      for (int j = n; j >= 1; j--) {
        if (j + qs[i].step > n) {
          dp[j] = arr[j];
        } else {
          dp[j] = arr[j] + dp[j + qs[i].step];
        }
      }
      ans[qs[i].ori] = dp[qs[i].start];
    } else {
      long long res = 0;
      for (int j = qs[i].start; j <= n; j += qs[i].step) {
        res += arr[j];
      }
      ans[qs[i].ori] = res;
    }
  }
}
int main() {
  read();
  solve();
  for (long long i = 0; i < q; i++) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
