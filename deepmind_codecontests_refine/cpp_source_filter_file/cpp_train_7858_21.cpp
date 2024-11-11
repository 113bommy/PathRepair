#include <bits/stdc++.h>
using namespace std;
long long n, a[100010], ans = 0, temp = 0, t = 1;
int main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  temp = a[1];
  for (long long i = 2; i <= n; i++) {
    if (a[i] >= temp) {
      t++;
      ans = max(ans, t);
      temp = a[i];
    } else {
      t = 1;
      temp = a[i];
    }
  }
  cout << ans;
}
