#include <bits/stdc++.h>
using namespace std;
long long a = 10e18;
long long d[65];
int main() {
  d[0] = 1;
  for (int i = 1; i <= 31; ++i) {
    d[i] = (1LL << i) * (1LL << i) + d[i - 1] * 2;
  }
  int T;
  cin >> T;
  while (T--) {
    long long x;
    cin >> x;
    int j = 0;
    while (x - d[j] >= 0) {
      x -= d[j];
      j++;
    }
    cout << j << "\n";
  }
}
