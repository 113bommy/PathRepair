#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
int main() {
  std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int t = 1;
  while (t--) {
    int h1, a1, d1;
    cin >> h1 >> a1 >> d1;
    int h2, a2, d2;
    cin >> h2 >> a2 >> d2;
    int hc, ac, dc;
    cin >> hc >> ac >> dc;
    long long min_cost = 1000000000;
    for (int h = 0; h <= 1000; h++) {
      for (int a = 0; a <= 200; a++) {
        for (int d = 0; d <= 100; d++) {
          int dec1 = max(0, a2 - (d1 + d));
          int dec2 = max(0, a1 + a - d2);
          long long cost = h * hc + a * ac + d * dc;
          if (dec2 == 0) {
            continue;
          }
          if (dec1 == 0) {
            if (cost < min_cost) {
              min_cost = cost;
            }
          } else {
            if (ceil((double)(h1 + h) / (double)(a2 - d1 - d)) >
                ceil((double)(h2) / (double)(a1 + a - d2))) {
              if (cost < min_cost) {
                min_cost = cost;
              }
            }
          }
        }
      }
    }
    cout << min_cost;
  }
  return 0;
}
