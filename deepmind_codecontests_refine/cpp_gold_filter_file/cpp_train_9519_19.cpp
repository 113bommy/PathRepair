#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  long long n, m, c, d, k;
  cin >> c >> d >> n >> m >> k;
  long long temp = n * m - k;
  long long i = 0;
  long long ans = 0;
  while (i < temp) {
    if (i + n < temp) {
      if (d > c / n) {
        i = i + n;
        ans += c;
      } else {
        i++;
        ans += d;
      }
    } else {
      ans += min((temp - i) * d, c);
      i = temp;
    }
  }
  cout << ans;
}
