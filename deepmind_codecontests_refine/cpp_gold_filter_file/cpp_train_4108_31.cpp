#include <bits/stdc++.h>
using namespace ::std;
vector<long long> Dp(100001, -1);
vector<long long> county(100001, 0);
long long f(int j) {
  if (j <= 0) return 0;
  if (Dp[j] == -1) Dp[j] = max(j * county[j] + f(j - 2), f(j - 1));
  return Dp[j];
}
int main() {
  int N;
  cin >> N;
  int ausi, arr[N + 1], a, i = 1;
  arr[0] = 0;
  while (i <= N) {
    cin >> a;
    arr[i++] = a;
  }
  for (auto it : arr) county[it]++;
  f(100000);
  auto res = max_element(Dp.begin(), Dp.end());
  cout << *res << "\n";
  return 0;
}
