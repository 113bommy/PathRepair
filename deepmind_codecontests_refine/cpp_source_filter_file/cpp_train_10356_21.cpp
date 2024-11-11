#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, temp, sum, ret;
  while (cin >> n >> m) {
    sum = 0;
    for (long long i = 1; i <= n; i++) {
      ret = i * i;
      if (ret <= m)
        sum += ret * 2 - 1;
      else
        sum += m * 2;
    }
    for (long long j = -2 * n; j < 0; j++) {
      temp = max(-2 * m - j, n / j);
      if (j & 1) temp--;
      temp = (-temp) >> 1;
      temp--;
      if (temp > 0) sum -= temp;
    }
    cout << sum << endl;
  }
}
