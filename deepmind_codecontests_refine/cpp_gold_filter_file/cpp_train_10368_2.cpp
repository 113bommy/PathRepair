#include <bits/stdc++.h>
using namespace std;
vector<long> a;
long n;
inline bool check(long x) {
  long i;
  for (i = 0; i < n; i++)
    if (((a[i] - 1) / (x + 1) + 1) * x > a[i]) break;
  return i == n;
}
void solve() {
  long bound = sqrt(a[0]), max_x;
  for (max_x = bound; max_x >= 1; max_x--)
    if (check(max_x)) break;
  for (long k = 1; k <= bound; k++) {
    long x = a[0] / k;
    if (check(x)) {
      max_x = max(max_x, x);
      break;
    }
    if (check(x - 1)) {
      max_x = max(max_x, x - 1);
      break;
    }
  }
  long long total = 0;
  for (long i = 0; i < n; i++) total += (a[i] - 1) / (max_x + 1) + 1;
  printf("%I64d\n", total);
}
int main() {
  scanf("%ld", &n);
  a.resize(n);
  for (long i = 0; i < n; i++) scanf("%ld", &a[i]);
  solve();
  return 0;
}
