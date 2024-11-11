#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long gcd(long long a, long long b) { return (b == 0) ? a : gcd(b, a % b); }
int main() {
  ios_base::sync_with_stdio(false);
  long long m, t, r;
  cin >> m >> t >> r;
  vector<long long> w;
  for (int i = 0; i < m; i++) {
    long long a;
    cin >> a;
    w.push_back(a);
  }
  if (t - r + 1 <= 0) {
    cout << -1 << endl;
    return 0;
  }
  long long cnt = 0;
  vector<long long> candles;
  long long cur = 0;
  long long dif = 0;
  for (int i = 0; i < w.size(); i++) {
    if (i != 0) {
      dif = w[i] - w[i - 1];
      for (int i = 0; i < candles.size(); i++) {
        if (candles[i] > 0) {
          candles[i] = candles[i] - dif;
          if (candles[i] <= 0) {
            cur--;
          }
        }
      }
    }
    long long x = r - cur;
    for (int i = 1; i <= x; i++) {
      candles.push_back(t - x + i);
    }
    cnt += x;
    cur = r;
  }
  cout << candles.size() << endl;
  return 0;
}
