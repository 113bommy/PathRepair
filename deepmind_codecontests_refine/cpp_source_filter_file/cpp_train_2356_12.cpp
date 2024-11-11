#include <bits/stdc++.h>
using namespace std;
long long i, j, n, k, a[100], q, ans, b[100], x, y, f;
string s, str, v[100];
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 1; i < n - 1; i++) {
    if (a[i] > a[i - 1] and a[i] > a[i + 1]) ans++;
    if (a[i] < a[i - 1] and a[i] < a[i + 1]) ans++;
  }
  cout << ans << endl;
  return 0;
}
