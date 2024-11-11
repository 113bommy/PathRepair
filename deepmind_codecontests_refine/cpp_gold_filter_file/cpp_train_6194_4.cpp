#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int a[100005];
  int b, c, i;
  int n;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (a[0] == 1)
    cout << -1 << endl;
  else {
    if (a[0] >= 2) cout << 1 << endl;
  }
  return 0;
}
