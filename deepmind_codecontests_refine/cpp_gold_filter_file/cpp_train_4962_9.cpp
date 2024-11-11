#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, a, b, c, t;
  cin >> n >> a >> b >> c >> t;
  vector<long long> times(n);
  long long profit = n * a;
  for (int i = 0; i < n; ++i) {
    cin >> times[i];
  }
  sort(times.begin(), times.end());
  if (c > b) {
    for (int i = 1; i < n; ++i) {
      profit += (times[i] - times[i - 1]) * i * (c - b);
    }
    profit += (t - times[n - 1]) * n * (c - b);
  }
  cout << profit << endl;
  return 0;
}
