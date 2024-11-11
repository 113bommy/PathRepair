#include <bits/stdc++.h>
using namespace std;
const int N = 50005;
long long one[19] = {0, 1};
void init() {
  for (int i = (2); i <= (16); i++) one[i] = one[i - 1] * 10 + 1;
}
long long dfs(long long sum, long long n) {
  if (n == 1) return sum;
  long long k1 = sum / one[n];
  long long k2 = k1 + 1;
  long long r1 = dfs(sum - k1 * one[n], n - 1),
            r2 = dfs(k2 * one[n] - sum, n - 1);
  return min(k1 * n + r1, k2 * n + r2);
}
long long get(long long n) {
  long long ret = 0;
  while (n) {
    ret++;
    n /= 10;
  }
  return ret;
}
int main() {
  init();
  long long n;
  scanf("%I64d", &n);
  printf("%I64d\n", dfs(n, get(n) + 1));
  return 0;
}
