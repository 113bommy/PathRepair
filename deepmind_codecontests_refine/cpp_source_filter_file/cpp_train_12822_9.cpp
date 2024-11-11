#include <bits/stdc++.h>
using namespace std;
const long long int N = 300009;
long long int n, k, m;
long long int a[N];
long long int c = 0;
int main() {
  cin >> n >> m >> k;
  for (long long int i = 0; i < m; ++i) cin >> a[i];
  long long int j = 0;
  long long int ans = 0;
  long long int t = k;
  k = ((a[0] + k) / k) * k;
  while (j < m) {
    if (a[j] <= k && j < m) {
      c = 0;
      while (a[j] <= k && j < m) {
        j++;
        c++;
      }
      k = k + c;
      ans++;
    } else {
      k = k + (((a[j] - 1 - k) / t) + 1) * t;
    }
  }
  cout << ans << endl;
}
