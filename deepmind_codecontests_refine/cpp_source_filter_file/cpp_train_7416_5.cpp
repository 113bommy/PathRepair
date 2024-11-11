#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<long long> v;
  long long f = 0;
  for (long long i = 1; i <= 10000; i++) {
    long long d = i * (i + 1);
    v.push_back(d + f);
    f += i;
  }
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int ans = 0;
    auto it = lower_bound(v.begin(), v.end(), n);
    int ind = it - v.begin();
    if (v[ind] > n) {
      int i = ind - 1;
      while (n >= 2) {
        if (n >= v[i]) {
          ans += (n / v[i]);
          n = n - ((n / v[i]) * v[i]);
        }
        i--;
      }
    } else
      ans = 1;
    cout << ans << "\n";
  }
}
