#include <bits/stdc++.h>
using namespace std;
vector<int> primes;
int arr[102];
int n;
int dp[102][(1 << 17)];
int num[102][1 << 17];
int help[60];
int finalArr[102];
int curArr[102];
int totalans = 50000;
int getAns(int idx, int mask) {
  if (idx == n + 1) {
    return 0;
  }
  if (dp[idx][mask] != -1) {
    return dp[idx][mask];
  }
  int curans = 50000;
  int bst = 0;
  for (int i = 1; i < 60; ++i) {
    if ((mask & help[i]) != help[i]) continue;
    curArr[idx] = i;
    int ans = getAns(idx + 1, (mask ^ help[i]));
    ans += abs(arr[idx] - i);
    if (curans > ans) {
      bst = i;
    }
    curans = min(curans, ans);
  }
  dp[idx][mask] = curans;
  num[idx][mask] = bst;
  return curans;
}
int main() {
  bool pri[60] = {0};
  memset(dp, -1, sizeof dp);
  for (int i = 2; i < 60; ++i) {
    if (pri[i] != 0) continue;
    primes.push_back(i);
    for (int j = i * i; j < 60; j += i) {
      pri[j] = 1;
    }
  }
  for (int i = 1; i < 60; ++i) {
    help[i] = 0;
    for (int j = 0; j < 17; ++j) {
      if ((i % primes[j]) == 0) {
        help[i] += (1 << j);
      }
    }
  }
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> arr[i];
  arr[n] = 1;
  int mycst = getAns(0, (1 << 17) - 1);
  int msk = (1 << 17) - 1;
  for (int i = 0; i < n; ++i) {
    cout << num[i][msk] << " ";
    msk ^= num[i][msk];
  }
}
