#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    vector<long long> v1;
    long long n, k;
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) {
      long long x;
      cin >> x;
      v1.push_back(x);
    }
    sort(v1.begin(), v1.end());
    long long ans = 0;
    long long temp = (1 << 30);
    for (long long i = 0; i + k < n; i++) {
      long long point = (v1[i + k] + v1[i]) / 2;
      long long dist = min(abs(point - v1[i]), abs(point - v1[i + k]));
      if (temp > dist) {
        temp = dist;
        ans = point;
      }
    }
    cout << ans << endl;
  }
}
