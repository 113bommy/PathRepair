#include <bits/stdc++.h>
using namespace std;
long long ans, mx, sum = -1, temp, mn = 1e14, flag, cnt;
int main() {
  long long n, k;
  cin >> n >> k;
  long long sum = k;
  long long a[k];
  for (long long i = 0; i < k; i++) {
    a[i] = 1;
  }
  for (long long i = k - 1; i >= 0; i--) {
    while (sum + a[i] <= n) {
      sum += a[i];
      a[i] *= 2;
    }
  }
  if (sum != n)
    cout << "NO";
  else {
    cout << "YES" << endl;
    for (long long i = 0; i < k; i++) cout << a[i] << " ";
  }
}
