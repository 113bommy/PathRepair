#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, i, j;
  cin >> n;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  ;
  long long sum = 0, maxi = 0;
  for (i = 0; i < n; i++) {
    maxi = max(maxi, a[i]);
    sum += a[i];
  }
  for (i = maxi; i <= 100; i++) {
    long long c = 0;
    for (j = 0; j < n; j++) c += i - a[j];
    if (c > sum) {
      cout << i;
      return 0;
    }
  }
}
