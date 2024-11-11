#include <bits/stdc++.h>
using namespace std;
long long a[101];
int main() {
  long long n;
  cin >> n;
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    res = max(res, a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      long long tmp = 0;
      for (int k = i; k <= j; ++k) {
        tmp ^= a[k];
      }
      res = max(res, tmp);
    }
  }
  cout << res;
}
