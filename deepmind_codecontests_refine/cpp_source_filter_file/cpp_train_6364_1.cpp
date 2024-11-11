#include <bits/stdc++.h>
using namespace std;
long long int binEXP(long long int x, long long int pw,
                     long long int MOD = LLONG_MAX) {
  long long int res = 1;
  while (pw > 0) {
    pw % 2 ? res *= x : 0;
    x *= x;
    x %= MOD;
    pw /= 2;
    res %= MOD;
  }
  return res %= MOD;
}
const int mod = 998244353;
const int MAX = 1005;
long long int arr[MAX], x, y;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> x;
  for (int i = 0; i < x; i++) cin >> arr[i];
  sort(arr, arr + x);
  long long int cnt = 0;
  long long int sum = LLONG_MAX;
  long long int t = LLONG_MAX;
  for (int i = 0; i <= 100; i++) {
    cnt = 0;
    for (int j = 0; j < x; j++) {
      if (abs(arr[j] - i) > 1) cnt += abs(arr[j] - i) - 1;
    }
    if (cnt < sum) {
      sum = cnt;
      t = i;
    }
  }
  cout << t << " " << sum;
  return 0;
}
