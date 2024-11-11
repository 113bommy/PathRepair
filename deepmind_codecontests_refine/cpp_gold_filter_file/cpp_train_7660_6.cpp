#include <bits/stdc++.h>
using namespace std;
long long o[200001], a[200001];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long i, j, n, y, f;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < n; i++) o[i] = 1e9;
  y = 0, f = 0;
  for (i = 0; i < n; i++) {
    if (a[i] == 0 && f != 1) f = 1;
    if (a[i] == 0 && f == 1) y = 0, f = 1;
    if (f == 1) o[i] = y, y++;
  }
  y = 0, f = 0;
  for (i = n - 1; i >= 0; i--) {
    if (a[i] == 0 && f != 1) f = 1;
    if (a[i] == 0 && f == 1) y = 0, f = 1;
    if (f == 1) o[i] = min(y, o[i]), y++;
  }
  for (i = 0; i < n; i++) cout << o[i] << " ";
  cout << endl;
  return 0;
}
