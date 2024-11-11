#include <bits/stdc++.h>
using namespace std;
long long n, a[100000], ans = 0;
int main() {
  cin >> n;
  long long min = 100000333;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i];
    if (a[i] % 2 == 1 && a[i] < min) {
      min = a[i];
    }
  }
  if (ans % 2 == 0)
    cout << ans;
  else {
    cout << ans - min;
  }
  return 0;
}
