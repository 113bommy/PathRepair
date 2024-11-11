#include <bits/stdc++.h>
const int nmax = 1000000;
using namespace std;
long long a[nmax], n, k, sum[nmax];
long long res = 0;
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[1] += a[i];
  }
  for (int i = 2; i <= n; i++) {
    sum[i] = sum[i - 1] - a[i - 1];
  }
  res += sum[1];
  sort(sum + 2, sum + n + 1);
  for (int i = n - k + 2; i <= n; i++) res += sum[i];
  cout << res << endl;
  return 0;
}
