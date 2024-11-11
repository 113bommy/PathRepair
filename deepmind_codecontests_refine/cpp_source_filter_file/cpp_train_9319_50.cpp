#include <bits/stdc++.h>
using namespace std;
long long a[1005];
long long b[1005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  int ans = (a[0] | a[1]) + (b[0] | b[1]);
  for (int i = 1; i < n; i++) {
    long long a1 = a[i];
    long long b1 = b[i];
    for (int j = i + 1; j <= n; j++) {
      a1 = a1 | a[j];
      b1 = b1 | b[j];
    }
    if (ans < (a1 + b1)) ans = a1 + b1;
  }
  cout << ans << endl;
  return 0;
}
