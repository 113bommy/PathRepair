#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  map<long long, long long> home_freq;
  map<long long, long long> away_freq;
  for (long long i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    home_freq[x]++;
    away_freq[y]++;
  }
  long long sum = 0;
  for (auto x : away_freq) {
    long long freq = home_freq[x.first];
    if (freq != 0) {
      sum += freq * x.second;
    }
  }
  cout << sum;
  return 0;
}
