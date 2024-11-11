#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int res = 1;
  int p = n - 1;
  while (res != k) {
    if (res == 1)
      res++, p--;
    else if (res == 2) {
      if (n == 3) {
        res++, p--;
        continue;
      } else
        p -= n / 2;
      if (n % 2 == 1)
        res++;
      else
        res += 2;
    } else
      res += 2, p -= 1;
  }
  int cnt = 0;
  int mod = p + 1;
  while (cnt < n) {
    if (cnt % mod == 0)
      cout << 1;
    else
      cout << 0;
    cnt++;
  }
}
