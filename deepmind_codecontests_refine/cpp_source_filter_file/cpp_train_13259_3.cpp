#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
long long bigmod(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = (ret * a) % 1000000007;
    b >>= 1;
    a = (a * a) % 1000000007;
  }
  return ret;
}
long long inverse(long long n) { return bigmod(n, 1000000007 - 2); }
bool checkBit(int n, int i) { return (n & (1 << i)); }
int setBit(int n, int i) { return (n | (1 << i)); }
int resetBit(int n, int i) { return (n & (~(1 << i))); }
int dp[1000010], cnt[1000010][10];
int f(int n) {
  if (n < 2) return 0;
  int &ret = dp[n];
  if (ret != -1) return ret;
  double sq = sqrt(n);
  int start = ceil(sqrt(sq));
  int end = floor(sq);
  int a[300] = {0};
  for (int y = start; y <= end; ++y) a[f(y)] = 1;
  ret = 0;
  while (a[ret]) ++ret;
  return ret;
}
int main() {
  cnt[1][0] = 1;
  for (int i = 2; i < 1000010; ++i) {
    double sq = sqrt(i);
    int start = ceil(sqrt(sq));
    int end = floor(sq);
    for (int j = 0; j < 10; ++j) {
      if (cnt[end][j] - cnt[start - 1][j] == 0) {
        dp[i] = j;
        ++cnt[i][j];
        break;
      }
    }
    for (int j = 0; j < 10; ++j) cnt[i][j] += cnt[i - 1][j];
  }
  int n;
  long long x;
  scanf("%d", &n);
  long long nim = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &x);
    if (x < 1000010)
      nim ^= dp[x];
    else {
      double sq = sqrt(i);
      int start = ceil(sqrt(sq));
      int end = floor(sq);
      for (int j = 0;; ++j) {
        if (cnt[end][j] - cnt[start - 1][j] == 0) {
          nim ^= j;
          break;
        }
      }
    }
  }
  printf("%s\n", nim ? "Furlo" : "Rublo");
  return 0;
}
