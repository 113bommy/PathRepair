#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b;
  cin >> n >> a >> b;
  long long x = -1, y = -1;
  for (long long i = 0; i <= n; i++) {
    long long k = n - a * i;
    if (k % b == 0) {
      x = i;
      y = (n - a * i) / b;
      break;
    }
  }
  if (x == -1 || y == -1)
    cout << "-1";
  else {
    long long i = 1;
    while (i <= x) {
      long long st = (i - 1) * a + 1;
      long long cnt = st + 1;
      long long c = a - 1;
      while (c--) {
        cout << cnt << " ";
        cnt++;
      }
      cout << st << " ";
      i++;
    }
    i = x * a;
    long long j = 1;
    while (j <= y) {
      long long st = (j - 1) * b + 1;
      long long cnt = st + 1;
      long long c = b - 1;
      while (c--) {
        cout << cnt + i << " ";
        cnt++;
      }
      cout << st + i << " ";
      j++;
    }
  }
  return 0;
}
