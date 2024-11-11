#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long sum = 1;
  n -= 1;
  if (n == 0) {
    printf("1\n");
    return 0;
  }
  if (m == 1) {
    n = 2 * n;
    long long x = sqrt(n);
    if (n - x * (x + 1) > 0)
      sum += x + 1;
    else
      sum += x;
    cout << sum << endl;
  } else {
    n += 1;
    if (m >= n)
      sum = n;
    else {
      sum = m;
      sum++;
      n = n - m - 1;
      if (n > 0) {
        n += 1;
        n = n * 2;
        long long x = sqrt(n);
        if (n - x * (x + 1) > 0)
          sum += x + 1;
        else
          sum += x;
        sum--;
      }
    }
    cout << sum << endl;
  }
}
