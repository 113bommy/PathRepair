#include <bits/stdc++.h>
using namespace std;
long long n, k, p, x;
int main() {
  cin >> n >> k >> p;
  while (p--) {
    cin >> x;
    if (k == 0) {
      cout << '.';
      return 0;
    }
    if (n % 2 == 0) {
      if (x % 2 == 0 && k >= (n - x + 2) / 2)
        cout << "X";
      else if (x % 2 == 1 && k >= n / 2 + (n - x + 1) / 2)
        cout << "X";
      else
        cout << ".";
    }
    if (n % 2 == 1) {
      if (x == n) {
        cout << "X";
        continue;
      }
      n--;
      k--;
      if (x % 2 == 0 && k >= (n - x + 2) / 2)
        cout << "X";
      else if (x % 2 == 1 && k >= n / 2 + (n - x + 1) / 2)
        cout << "X";
      else
        cout << ".";
      n++;
      k++;
    }
  }
  return 0;
}
