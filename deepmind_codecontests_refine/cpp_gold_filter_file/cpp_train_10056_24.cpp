#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 1e9 + 7;
const long long maxn = 1e6 + 7;
const double eps = 0.00000001;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
int i, j;
long long k;
int sum;
int a[64], b[64];
int num[64];
void pushin(long long x) {
  int i;
  for (i = 0; i <= 60; i++) {
    if (x == 1ll << i) {
      a[i]++;
      return;
    }
    if (x < 1ll << i) {
      b[i - 1]++;
      return;
    }
  }
}
bool judge(int x) {
  int i, count = 0, prex = x, use;
  for (i = 0; i <= 60; i++) {
    if (a[i] < x) x = a[i];
    num[i] = x;
  }
  for (i = 60; i >= 0; i--) {
    count += a[i] + b[i] - num[i];
    if (count > num[i]) return 0;
  }
  return 1;
}
bool mark;
int n;
int main() {
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%I64d", &k);
    pushin(k);
  }
  for (i = 1; i <= a[0]; i++)
    if (judge(i)) printf("%d ", i), mark = 1;
  if (!mark) puts("-1");
}
