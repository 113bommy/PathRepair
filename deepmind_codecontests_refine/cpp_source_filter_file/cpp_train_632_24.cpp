#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, p;
  cin >> n >> k >> p;
  if (k == 0) {
    for (int i = 1; i <= p; i++) cout << ".";
    return 0;
  }
  if (k == 1) {
    for (int i = 1; i <= p; i++) {
      long long x;
      cin >> x;
      if (x == n)
        cout << "X";
      else
        cout << ".";
    }
    return 0;
  }
  long long m = 0;
  if (n % 2) {
    m = n--;
    k--;
  }
  if (n % 2 == 0) {
    if (k <= n / 2) {
      long long u = n - 2 * k + 1;
      for (int i = 1; i <= p; i++) {
        long long x;
        cin >> x;
        if ((x > u && x % 2 == 0) || x == m)
          cout << "X";
        else
          cout << ".";
      }
    } else {
      long long u = (n - k) * 2;
      for (int i = 1; i <= p; i++) {
        int x;
        cin >> x;
        if ((x % 2 == 0 || x > u) || x == m)
          cout << "X";
        else
          cout << ".";
      }
    }
    return 0;
  }
  return 0;
}
