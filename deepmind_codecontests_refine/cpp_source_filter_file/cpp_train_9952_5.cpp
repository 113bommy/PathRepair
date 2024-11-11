#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 1e9 + 7;
const long long maxn = 1e5 + 7;
const double eps = 0.00000001;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
int cnt[6];
int a[6], b[6];
int i, j, k;
int sum;
int num(int m, int n) {
  if (m * 2 > n) return 1;
  if (m * 4 > n) return 2;
  if (m * 8 > n) return 3;
  if (m * 16 > n) return 4;
  if (m * 32 > n) return 5;
  return 6;
}
int n, m;
bool judge(int x) {
  int sum = 0, i;
  for (i = 1; i <= 5; i++) {
    if (a[i] == 0 || a[i] > b[i])
      sum += num(cnt[i], n + x) * (a[i] - b[i]);
    else
      sum += num(cnt[i] + x, n + x) * (a[i] - b[i]);
  }
  return sum > 0;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= 5; i++) {
    scanf("%d", &k);
    if (k != -1)
      cnt[i]++, a[i] = 250 - k;
    else
      a[i] = 0;
  }
  for (i = 1; i <= 5; i++) {
    scanf("%d", &k);
    if (k != -1)
      cnt[i]++, b[i] = 250 - k;
    else
      b[i] = 0;
  }
  for (j = 0; j < n - 2; j++)
    for (i = 1; i <= 5; i++) {
      scanf("%d", &k);
      if (k != -1) cnt[i]++;
    }
  for (i = 1; i <= 10000; i++)
    if (judge(i)) {
      printf("%d", i);
      return 0;
    }
  puts("-1");
}
