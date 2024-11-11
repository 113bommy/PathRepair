#include <bits/stdc++.h>
using namespace std;
long long int a[300005];
int main() {
  long long int n, i, sum = 0, ans = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    sum = sum + a[i];
  }
  sort(a, a + n);
  if (n == 1)
    ans = sum;
  else if (n == 2)
    ans = sum * 2;
  else {
    ans = sum * 2;
    for (i = 0; i < n - 3; i++) {
      sum = sum - a[i];
      ans += sum * 2;
    }
    ans += a[n - 1] + a[n - 2];
  }
  cout << ans << endl;
}
