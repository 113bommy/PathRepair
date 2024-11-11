#include <bits/stdc++.h>
#pragma warning(disable : 4996)
const long long MOD = 1000000007;
using namespace std;
vector<long long> dp;
vector<int> func(int n, int k) {
  assert(k % 2);
  vector<int> ans;
  int i;
  if (k == 1) {
    for (i = 0; i < n; i++) {
      ans.push_back(i);
    }
    return ans;
  }
  int m = n / 2;
  assert(dp[m] + dp[n - m] + 1 >= k && k >= 1);
  int k0 = ((dp[m]) > (k - 2) ? (k - 2) : (dp[m]));
  int k1 = k - 1 - k0;
  assert(k0 % 2);
  assert(k1 % 2);
  vector<int> v0 = func(m, k0);
  vector<int> v1 = func(n - m, k1);
  for (i = 0; i < (int)v0.size(); i++) {
    ans.push_back(v0[i] + n - m);
  }
  for (i = 0; i < (int)v1.size(); i++) {
    ans.push_back(v1[i]);
  }
  return ans;
}
int main(int argc, char* argv[]) {
  int n, k;
  scanf("%d%d", &n, &k);
  if (k % 2 == 0) {
    printf("-1\n");
    return 0;
  }
  dp.resize(n + 1);
  dp[1] = 1;
  int i;
  for (i = 2; i <= n; i++) {
    int j = i / 2;
    dp[i] = dp[j] + dp[i - j] + 1;
  }
  if (k > dp[n]) {
    printf("-1\n");
    return 0;
  }
  vector<int> v = func(n, k);
  for (i = 0; i < n; i++) {
    printf("%d", v[i] + 1);
    if (i < n - 1) printf(" ");
  }
  printf("\n");
  return 0;
}
