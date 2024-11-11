#include <bits/stdc++.h>
using namespace std;
void boost() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long cubic_root(long long x) {
  long long l = 0, r = 2000005;
  while (l != r) {
    long long m = (l + r + 1) / 2;
    if (m * m * m > x)
      r = m - 1;
    else
      l = m;
  }
  return l;
}
int main(void) {
  boost();
  long long t;
  cin >> t;
  while (t--) {
    long long a, b, flag = 0;
    cin >> a >> b;
    long long x = a * b;
    long long n = cubic_root(x);
    long long t1 = n * n * n;
    if (t1 != x) {
      flag = 1;
    }
    if (flag)
      cout << "NO"
           << "\n";
    else {
      if (a % n == 0 && b % n == 0) {
        cout << "YES"
             << "\n";
      } else
        cout << "NO"
             << "\n";
    }
  }
}
