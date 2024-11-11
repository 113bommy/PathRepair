#include <bits/stdc++.h>
using namespace std;
int isprime(int n) {
  int i, flag = 1;
  for (i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      flag = 0;
      break;
    }
  }
  if (flag == 1)
    return 1;
  else
    return 0;
}
int main() {
  int n, f, t = 0, z = 0;
  cin >> n;
  if (n < 6)
    cout << 0;
  else {
    for (int i = 6; i <= n; i++) {
      for (int j = 2; j <= i / 2; j++) {
        if (i % j == 0) {
          f = isprime(j);
          if (f) t++;
        }
      }
      if (t == 2) z++;
      t = 0;
    }
    cout << z;
  }
  return 0;
}
