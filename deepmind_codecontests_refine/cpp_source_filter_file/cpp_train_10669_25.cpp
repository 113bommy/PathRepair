#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) {
    int ans = 1;
    for (int j = 1; j < n; j++)
      if (a[j] > a[i]) ans++;
    cout << ans << " ";
  }
}
