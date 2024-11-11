#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  int a[n], i;
  for (i = 0; i < n; i++) cin >> a[i];
  if (n > m)
    cout << 0 << endl;
  else {
    int ans = 1;
    for (i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++) ans = (ans * abs(a[i] - a[j])) % m;
    cout << ans << endl;
  }
}
