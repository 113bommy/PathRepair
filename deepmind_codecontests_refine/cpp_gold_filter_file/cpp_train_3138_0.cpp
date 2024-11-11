#include <bits/stdc++.h>
using namespace std;
int main() {
  iostream::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int mn = INT_MAX, mn2 = INT_MAX;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
    if (mn > a[i]) {
      mn2 = mn;
      mn = a[i];
    } else {
      mn2 = min(mn2, a[i]);
    }
  }
  if (n == 1) cout << a[0] << "\n";
  int minpow = sum;
  for (int i = 0; i < n; ++i) {
    int k = 2;
    int current_num = a[i];
    int other = current_num == mn ? mn2 : mn;
    while (k * k <= current_num) {
      if (current_num % k == 0) {
        minpow = min(minpow, (sum - other - current_num) + other * k +
                                 (current_num / k));
      }
      ++k;
    }
    minpow = min(minpow, (sum - other - current_num) + other * current_num + 1);
  }
  cout << minpow << "\n";
  return 0;
}
