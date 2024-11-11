#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 1000001;
int a, b, k;
int prime[MAX_N], sum[MAX_N];
bool C(int l) {
  int d = b - l + 1;
  for (int i = a; i <= d; ++i) {
    if (sum[i + l - 1] - sum[i - 1] < k) return false;
  }
  return true;
}
void solve() {
  fill(prime, prime + b + 1, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i <= b; ++i) {
    if (prime[i]) {
      for (int j = 2 * i; j <= b; j += i) {
        prime[j] = false;
      }
      sum[i] = sum[i - 1] + 1;
    } else
      sum[i] = sum[i - 1];
  }
  int l = 1, r = b - a + 1, ret = -1;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (C(mid))
      r = ret = mid;
    else
      l = mid;
  }
  if (C(r)) ret = r;
  printf("%d\n", ret);
}
int main() {
  scanf("%d%d%d", &a, &b, &k);
  solve();
  return 0;
}
