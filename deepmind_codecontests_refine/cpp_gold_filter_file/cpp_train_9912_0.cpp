#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, sum, n, s, ans, maxi, num, max, a[100005];
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> s;
    for (int j = 1; j <= n; j++) {
      cin >> a[j];
    }
    sum = 0;
    maxi = 0;
    max = 0;
    ans = 0;
    for (int j = 1; j <= n; j++) {
      num = a[j];
      if (num > max) {
        max = num;
        maxi = j;
      }
      sum = sum + num;
      if (sum > s && (sum - max) <= s) {
        ans = maxi;
      }
    }
    cout << ans << endl;
  }
}
