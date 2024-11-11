#include <bits/stdc++.h>
long long m, n, t;
long long sum = 0;
const int ma = 3e5 + 5;
long long a[ma], b[ma];
using namespace std;
int main() {
  cin >> n;
  for (int j = 0; j < n; j++) {
    cin >> m >> t;
    long long sum1 = 0;
    if (m % 2 == 0 && t % 2 == 0)
      sum1 = sum1 + (m + t) / 2;
    else if (m % 2 == 1 && t % 2 == 1)
      sum1 = sum1 - (m + t) / 2;
    else if (m % 2 == 0 && t % 2 == 1)
      sum1 += (m + t + 1) / 2 - t - 1;
    else if (m % 2 == 1 && t % 2 == 0)
      sum1 = sum1 - (m + t - 1) / 2 + t;
    cout << sum1 << "\n";
  }
}
