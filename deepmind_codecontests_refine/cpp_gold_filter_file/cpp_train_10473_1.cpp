#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, b;
  cin >> m >> b;
  long long ans = 0;
  for (long long i = 0; i < (long long)m * b + 1; i++) {
    int y = floor(-((long double)i / (long double)m) + (long double)b);
    long long t = i * (i + 1) / 2 * (y + 1);
    t += y * (y + 1) / 2 * (i + 1);
    if (t > ans) {
      ans = t;
    }
  }
  cout << ans;
  return 0;
}
