#include <bits/stdc++.h>
using namespace std;
int prime[100001], pNum, bound, depth, total, t;
bool notPrime[100001];
void dfs(int dep, int count, int val) {
  if (dep == depth) {
    if (count) {
      if (count & 1)
        total += t / val;
      else
        total -= t / val;
    }
    return;
  }
  dfs(dep + 1, count, val);
  if ((long long)prime[dep] * val <= t)
    dfs(dep + 1, count + 1, val * prime[dep]);
}
int cal(int a, int k) {
  a /= k;
  t = a;
  bound = min(k - 1, a);
  if (bound < 2) return a;
  for (int i = 0; i < pNum; ++i)
    if (bound >= prime[i]) depth = i + 1;
  total = 0;
  dfs(0, 0, 1);
  return a - total;
}
int main() {
  for (int i = 2; i < 100001; ++i) {
    if (!notPrime[i]) prime[pNum++] = i;
    for (int j = 0; j < pNum && i * prime[j] < 100001; ++j) {
      notPrime[i * prime[j]] = true;
      if (!(i % prime[j])) break;
    }
  }
  int a, b, k;
  scanf("%d%d%d", &a, &b, &k);
  for (int i = 2; i * i <= k; ++i)
    if (k % i == 0) {
      puts("0");
      return 0;
    }
  int res = cal(b, k) - cal(a - 1, k);
  printf("%d\n", res);
  return 0;
}
