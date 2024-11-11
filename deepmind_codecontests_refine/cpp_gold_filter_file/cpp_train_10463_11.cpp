#include <bits/stdc++.h>
using namespace std;
long long int n;
int main() {
  cin >> n;
  long long int t[n];
  for (long long int i = 0; i < n; i++) cin >> t[i];
  sort(t, t + n);
  int z = 0, j = 0, k = n - 1;
  long long int res = t[n - 1] - t[0];
  for (long long int i = 0; i < n / 2; i++) {
    res = min(res, t[i + n / 2] - t[i]);
  }
  cout << res;
}
