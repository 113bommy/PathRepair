#include <bits/stdc++.h>
using namespace std;
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first > b.first)
    return true;
  else
    return false;
}
int main() {
  long long n, m;
  cin >> n >> m;
  if (m % n != 0)
    cout << -1;
  else if (m / n == 1)
    cout << -1;
  else {
    long long x = m / n;
    long long a = 0;
    long long b = 0;
    bool lund = true;
    while (x > 1) {
      bool q = false;
      bool w = false;
      if (x % 2 == 0) {
        x = x / 2;
        a++;
        q = true;
      } else if (x % 3 == 0) {
        x = x / 3;
        b++;
        w = true;
      }
      if (q == false && w == false) {
        lund = false;
        break;
      }
    }
    if (lund == false || (a == 0 && b == 0))
      cout << -1;
    else
      cout << a + b;
  }
  return 0;
}
