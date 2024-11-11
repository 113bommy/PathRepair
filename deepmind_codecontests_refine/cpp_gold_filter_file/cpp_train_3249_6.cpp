#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    if (n <= 9) {
      cout << n << endl;
      continue;
    }
    long long x = 1, sum = 0, p = x;
    while (x <= 9) {
      p = x;
      int i = 1;
      sum++;
      while ((x * round(pow(10, i)) + p) <= n) {
        p += (x * round(pow(10, i)));
        sum++;
        i++;
      }
      x++;
    }
    cout << sum << endl;
  }
  return 0;
}
