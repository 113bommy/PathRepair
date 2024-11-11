#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
long long int n, k;
void solve() {
  long long int i, j, sum = 0, t = n;
  for (i = 0; i < k && i < n / 2; i++) {
    sum += 2 * t - 3;
    t -= 2;
  }
  printf("%I64d", sum);
  return;
}
int main() {
  scanf("%I64d%I64d", &n, &k);
  solve();
  return 0;
}
