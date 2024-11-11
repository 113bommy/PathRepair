#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0;
  cin >> n;
  n++;
  for (int i = 1; i < n - 2; i++) {
    for (int j = i; j < n - 1; j++) {
      int k = (int)(i ^ j);
      if (k <= n && k > j) {
        if (!(i ^ j ^ k)) {
          int p = (i + j + k) / 2;
          double s = sqrt(p * (p - i) * (p - j) * (p - k));
          if (s > 0) {
            sum++;
          }
        }
      }
    }
  }
  cout << sum;
  return 0;
}
