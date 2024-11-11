#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, n, i, x, y, m, p, q, sum, ans, cnt, mx, mn, j, k;
  cin >> t;
  while (t--) {
    sum = 0;
    cnt = 0;
    ans = 0;
    mx = INT_MIN;
    mn = 1e18;
    cin >> n;
    vector<long long int> a(n);
    for (i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    i = 0;
    j = n - 1;
    while (i < n / 2) {
      cout << a[j] << " " << a[0] << "\n";
      i++;
      j--;
    }
  }
}
