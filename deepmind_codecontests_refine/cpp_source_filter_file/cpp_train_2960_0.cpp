#include <bits/stdc++.h>
using namespace std;
int arr[1000005];
int n;
int sum[1000005], num[1000005];
void update(int x) {
  while (x <= n) {
    ++sum[x];
    x += (x & -x);
  }
}
int get(int x) {
  int ret = 0;
  while (x) {
    ret += sum[x];
    x -= (x & -x);
  }
  return ret;
}
long long dp[1000005][2], p = 1e9 + 7, ss[1000005], fact[1000005];
long long solve1(int i) {
  if (i == n) return 1;
  long long &ret = ss[i];
  if (ret != -1) return ret;
  long long x = arr[i] - num[i];
  ret = (x - 1) * fact[x - 1] + solve1(i + 1);
  ret %= p;
  return ret;
}
long long solve(int i, bool les) {
  if (i == n) return 0;
  long long &ret = dp[i][les];
  if (ret != -1) return ret;
  ret = 0;
  if (les) {
    long long x = n - i;
    ret = x * solve(i + 1, 1) + (((x * (x - 1) / 2) % p) * fact[x - 1]);
    ret %= p;
  } else {
    long long x = arr[i] - num[i];
    ret = (x - 1) * solve(i + 1, 1);
    ret %= p;
    ret += (((x - 1) * (x - 2) / 2) % p) * fact[n - i - 1];
    ret %= p;
    ret += solve(i + 1, 0) + (x - 1) * solve1(i + 1);
    ret %= p;
  }
  return ret;
}
int main() {
  memset(ss, -1, sizeof ss);
  memset(dp, -1, sizeof dp);
  cin >> n;
  fact[0] = 1;
  for (int i = 1; i < n + 2; ++i) fact[i] = (fact[i - 1] * i) % p;
  for (int i = 0; i < n; ++i) {
    scanf("%d", arr + i);
    num[i] = get(arr[i]);
    update(arr[i]);
  }
  cout << solve(0, 0) << endl;
}
