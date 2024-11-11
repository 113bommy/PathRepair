#include <bits/stdc++.h>
using namespace std;
int n, a[30], b[30], ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) ans += a[i] == b[j];
  cout << ans;
  return 0;
}
