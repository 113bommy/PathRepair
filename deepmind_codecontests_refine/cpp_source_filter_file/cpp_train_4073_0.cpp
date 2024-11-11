#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k, ans = 0;
  cin >> n >> m >> k;
  int a[n];
  for (int i = n - 1; i > -1; i--) {
    cin >> a[i];
  }
  long long int temp = k;
  m--;
  int i = 0;
  while (i < n) {
    if (temp >= a[i]) {
      temp = temp - a[i];
      ans++;
    }
    if (a[i] > temp) {
      if (m > 0) {
        m--;
        temp = k - a[i];
        ans++;
      } else {
        cout << ans << endl;
        return 0;
      }
    }
    i++;
  }
  cout << ans << endl;
  return 0;
}
