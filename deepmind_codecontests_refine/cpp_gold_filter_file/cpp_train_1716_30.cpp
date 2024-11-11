#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int m;
int n;
int main() {
  long long d = 100000;
  long long c, h[2], w[2];
  cin >> c >> w[0] >> w[1] >> h[0] >> h[1];
  long long ans = 0;
  for (int o = 0; o < (2); o++) {
    for (long long i = 0; i <= d; i++) {
      if (i * h[o] > c) break;
      long long t1 = i * w[o];
      long long t2 = w[1 - o] * ((c - i * h[o]) / h[1 - o]);
      ans = max(ans, t1 + t2);
    }
  }
  cout << ans << endl;
  return 0;
}
