#include <bits/stdc++.h>
#pragma GCC target("sse4.2")
using namespace std;
void grayserge() {
  long long n;
  cin >> n;
  long long sum = 0;
  vector<long long> x;
  vector<long long> y;
  for (long long i = 0; i < n; i++) {
    long long a, b;
    cin >> a >> b;
    if (a == 1) {
      x.push_back(b);
    } else {
      y.push_back(b);
    }
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  long long min1 = 1000000009;
  for (long long i = 0; i <= x.size(); i++) {
    for (long long j = 0; j <= y.size(); j++) {
      long long z = i + 2 * (j);
      long long sum1 = 0;
      long long sum2 = 0;
      sum1 = accumulate(x.begin(), x.begin() + x.size() - i, 0);
      sum2 = accumulate(y.begin(), y.begin() + y.size() - j, 0);
      if (sum1 + sum2 <= z) {
        min1 = min(z, min1);
      }
    }
  }
  if (min1 != 1000000009)
    cout << min1 << "\n";
  else {
    cout << x.size() + 2 * y.size() << "\n";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    grayserge();
  }
  return 0;
}
