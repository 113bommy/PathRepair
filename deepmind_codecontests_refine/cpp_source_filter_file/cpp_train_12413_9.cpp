#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    long long a[n];
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n == 1) {
      cout << "0" << endl;
    } else {
      sort(a, a + n);
      long long count = 0;
      long long countd = 1;
      long long max = 1;
      for (long long i = 0; i < n; i++) {
        if (a[i] == a[i + 1]) {
          count++;
          if (count > max) {
            max = count;
          } else {
            max = max;
          }
        } else {
          count = 0;
          countd++;
        }
      }
      if (countd == 1 && max == 2 && n == 2) {
        cout << "1" << endl;
      } else if (max == countd) {
        cout << countd - 1 << endl;
      } else if (countd > max) {
        cout << max << endl;
      } else {
        cout << countd << endl;
      }
    }
  }
  return 0;
}
