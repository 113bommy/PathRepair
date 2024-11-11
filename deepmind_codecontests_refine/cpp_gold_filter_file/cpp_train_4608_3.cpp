#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, n, m;
    cin >> a >> b >> n >> m;
    if (a < b) {
      swap(a, b);
    }
    long long d = a - b;
    if (n >= d) {
      n -= d;
      a -= d;
      long long temp = min(n, m);
      a -= temp;
      b -= temp;
      n -= temp;
      m -= temp;
      if (a < 0 || b < 0) {
        cout << "No\n";
        continue;
      }
      if (n > m) {
        if (n > b + a)
          cout << "No\n";
        else
          cout << "Yes\n";
      } else {
        if (m > a)
          cout << "No\n";
        else
          cout << "Yes\n";
      }
    } else {
      a -= n;
      n = 0;
      if (b < m)
        cout << "No\n";
      else
        cout << "Yes\n";
    }
  }
}
