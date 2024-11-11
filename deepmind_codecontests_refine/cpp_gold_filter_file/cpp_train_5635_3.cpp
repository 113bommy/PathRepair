#include <bits/stdc++.h>
using namespace std;
long long t, n, k = 1;
long long d[40];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  d[1] = 1;
  for (int i = 2; i <= 32; i++) d[i] = 1 + 4 * d[i - 1];
  for (int i = 0; i < t; i++) {
    cin >> n >> k;
    long long j = 1;
    while (j <= n && d[j] <= k) j++;
    j--;
    if (n < 32 && d[n] < k)
      cout << "NO" << endl;
    else if (n < 4 &&
             k - d[j] > d[n - j] * ((1 << (2 * j)) - (1 << (j + 1)) + 1) &&
             k - d[j] < d[n - j] * ((1 << (j + 1)) - 1))
      cout << "NO" << endl;
    else if (n < 32 && k - d[j] && k - d[j] >= d[n - j] * ((1 << (j + 1)) - 1))
      cout << "YES " << n - j - 1 << endl;
    else
      cout << "yes " << n - j << endl;
  }
  return 0;
}
