#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
const int PRIME = 999983;
const int MOD = 1000000007;
const int MULTI = 1000000007;
const long double EPS = 1e-10;
const double ce = 2.718281828;
inline bool isodd(int x) { return x & 1; }
inline bool isodd(long long x) { return x & 1; }
int a[200010], n;
bool cmp(int a, int b) { return abs(a) < abs(b); }
int solve() {
  int sum = 0;
  sort(a, a + 2 * n - 1, cmp);
  if (n % 2) {
    for (int i = 0; i < 2 * n - 1; i++) sum += abs(a[i]);
  } else {
    int cnt = 0;
    for (int i = 0; i < 2 * n - 1; i++)
      if (a[i] < 0) cnt++;
    if (cnt % 2) {
      for (int i = 0; i < 2 * n - 1; i++) sum += abs(a[i]);
    } else {
      sum = -abs(a[0]);
      for (int i = 1; i < 2 * n - 1; i++) sum += abs(a[i]);
    }
  }
  return sum;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < 2 * n - 1; i++) scanf("%d", &a[i]);
  printf("%d\n", solve());
  return 0;
}
