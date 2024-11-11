#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int ans = 0, a1, d, d1;
  int i = 1;
  a1 = a[0];
  bool flag = true;
  d1 = a[1] - a[0];
  int k = n;
  --n;
  while ((n)--) {
    d = a[i + 1] - a[i];
    if (d != d1) {
      cout << a[k - 1] << endl;
      return 0;
    }
    i++;
  }
  if (flag == 1) {
    ans = a1 + (k)*d1;
    cout << ans << endl;
  }
  return 0;
}
