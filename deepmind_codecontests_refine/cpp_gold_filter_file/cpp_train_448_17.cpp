#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, ans = 0;
  cin >> n;
  vector<long long> a(n + 1);
  for (i = 1; i <= n; i++) cin >> a[i];
  for (i = 1; i <= n - 1; i++) {
    int step = 1;
    while (i + step * 2 <= n) step *= 2;
    ans += a[i];
    a[i + step] += a[i];
    a[i] = 0;
    cout << ans << endl;
  }
}
