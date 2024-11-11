#include <bits/stdc++.h>
using namespace std;
const int N = 500;
char getCharEven(long long n, long long k, long long t) {
  if (2 * k <= n) {
    if (t <= n - 2 * k)
      return '.';
    else {
      if (t % 2 == 0)
        return 'X';
      else
        return '.';
    }
  } else {
    long long kop = k - n / 2;
    if (t <= n - kop * 2) {
      if (t % 2 == 0)
        return 'X';
      else
        return '.';
    } else
      return 'X';
  }
}
int main() {
  long long n, k, p;
  cin >> n >> k >> p;
  for (int i = 0; i < p; i++) {
    long long t;
    cin >> t;
    if (k == 0)
      cout << '.';
    else {
      if (t == n)
        cout << 'X';
      else {
        if (n % 2 == 0)
          cout << getCharEven(n, k, t);
        else
          cout << getCharEven(n - 1, k - 1, t);
      }
    }
  }
  return 0;
}
