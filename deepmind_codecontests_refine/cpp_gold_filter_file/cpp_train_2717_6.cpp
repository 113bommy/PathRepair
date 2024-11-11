#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, x, flag = 0, check = 0, sum = 0, maxi = INT_MIN;
  cin >> n;
  vector<long long int> v;
  for (long long int i = 0; i < n; i++) {
    cin >> x;
    v.push_back(x);
    if (x < 0) {
      flag = 1;
      check += 1;
    }
    sum += x;
  }
  if (n == 1) {
    cout << v[0];
    return 0;
  }
  if (n == 2) {
    cout << abs(v[0] - v[1]);
  } else {
    if (flag == 1 and check != n) {
      long long int ans = 0;
      for (long long int i = 0; i < n; i++) {
        ans += abs(v[i]);
      }
      cout << ans;
    } else if (check == n or check == 0) {
      if (flag == 1) {
        for (long long int i = 0; i < n; i++) {
          v[i] = -1 * v[i];
        }
        sum = -1 * sum;
      }
      for (long long int i = 0; i < n - 1; i++) {
        long long int sum1 = INT_MIN;
        long long int sum2 = INT_MIN;
        if (i - 1 >= 0) {
          sum1 = sum - v[i] - v[i - 1] + v[i] - v[i - 1];
        }
        if (i + 1 < n) {
          sum2 = sum + v[i] - v[i + 1] - v[i] - v[i + 1];
        }
        maxi = max(max(maxi, sum1), sum2);
      }
      cout << maxi;
    }
  }
}
