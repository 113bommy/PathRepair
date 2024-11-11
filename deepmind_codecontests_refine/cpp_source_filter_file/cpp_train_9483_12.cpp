#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m;
  cin >> n >> m;
  long long int c[n], a[m];
  for (long long int i = 0; i < n; i++) {
    cin >> c[i];
  }
  for (long long int i = 0; i < m; i++) {
    cin >> a[i];
  }
  long long int ans = 0;
  long long int bill = a[0];
  long long int j = 0;
  for (long long int i = 0; i < n; i++) {
    if (bill >= c[i]) {
      ans++;
      j++;
      bill = a[j];
    }
    if (j == (m - 1)) {
      break;
    }
  }
  cout << ans;
}
