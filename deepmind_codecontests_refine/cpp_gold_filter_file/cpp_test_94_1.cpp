#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int result;
  if (b == 0) return 1;
  if (b % 2 != 0) {
    result = a;
    result = (result * (power(a, b - 1)));
  } else {
    result = power(a, b / 2);
    result = (result * result);
  }
  return (long long int)result;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, k;
    cin >> n >> k;
    long long int sum = 0;
    long long int prev = 0;
    vector<long long int> v(n);
    for (auto &i : v) cin >> i;
    bool f = 1;
    for (int i = 0; i < n - 1; i++) {
      long long int temp = power(10, v[i + 1] - v[i]) - 1;
      if (temp <= k) {
        sum += temp * (power(10, v[i]));
        k -= temp;
      } else {
        sum += (k + 1) * (power(10, v[i]));
        f = 0;
        break;
      }
    }
    if (f) {
      sum += (k + 1) * (power(10, v[n - 1]));
    }
    cout << sum << "\n";
  }
  return 0;
}
