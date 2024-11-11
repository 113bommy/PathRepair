#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    double n;
    cin >> n;
    vector<long long> a(n);
    long long maxi = INT16_MIN, sum = 0;
    for (int i = 0; i < a.size(); i++) {
      cin >> a[i];
      sum += a[i];
      if (a[i] > maxi) maxi = a[i];
    }
    double av = (sum - maxi) / (n - 1);
    double ans = maxi + av;
    printf("%.9f\n", ans);
  }
  return 0;
}
