#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, j, i, k, l;
  cin >> n;
  for (i = 0; i <= n; i++) {
    if (i * i * i > n) break;
  }
  long long cb = i - 1, sq = sqrt(n), maxi = 0, mini = 1000000000;
  for (i = 1; i <= cb; i++) {
    for (j = i; j <= sqrt(n / i); j++) {
      k = n / (i * j);
      if (n == i * j * k) {
        maxi = max(maxi, (i + 1) * (j + 2) * (k + 2) - i * j * k);
        maxi = max(maxi, (j + 1) * (i + 2) * (k + 2) - i * j * k);
        maxi = max(maxi, (j + 2) * (i + 2) * (k + 1) - i * j * k);
        mini = min(mini, (i + 1) * (j + 2) * (k + 2) - i * j * k);
        mini = min(mini, (j + 1) * (i + 2) * (k + 2) - i * j * k);
        mini = min(mini, (j + 2) * (i + 2) * (k + 1) - i * j * k);
      }
    }
  }
  cout << mini << " " << maxi << endl;
  return 0;
}
