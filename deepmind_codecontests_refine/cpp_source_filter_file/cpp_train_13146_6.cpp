#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int maxx = 0, minx = 1e8;
  for (long long int i = 1; i <= sqrt(n) + 1; i++) {
    if (n % i == 0) {
      long long int p = n / i;
      for (long long int j = 1; j <= sqrt(p) + 1; j++) {
        if (p % j == 0) {
          long long int k = p / j;
          minx = min(minx, (i + 1) * (j + 2) * (k + 2));
          minx = min(minx, (i + 2) * (j + 1) * (k + 2));
          minx = min(minx, (i + 2) * (j + 2) * (k + 1));
          maxx = max(maxx, (i + 1) * (j + 2) * (k + 2));
          maxx = max(maxx, (i + 2) * (j + 1) * (k + 2));
          maxx = max(maxx, (i + 2) * (j + 2) * (k + 1));
        }
      }
    }
  }
  cout << minx - n << " " << maxx - n << endl;
  return 0;
}
