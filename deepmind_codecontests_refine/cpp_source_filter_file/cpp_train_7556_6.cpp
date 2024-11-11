#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, cnt = 1, x;
  cin >> n;
  x = n;
  if (n <= 9)
    cout << 1;
  else {
    while (n > 0) {
      if (n > 10)
        cnt *= 10;
      else
        k = n % 10;
      n /= 10;
    }
    cout << (k + 1) * cnt - x;
  }
  return 0;
}
