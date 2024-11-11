#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int a[300001];
int b[300001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int i, j;
  int n, m;
  cin >> n;
  ll sum = 0;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  cin >> m;
  for (i = 0; i < m; i++) {
    cin >> b[i];
    sum -= b[i];
  }
  if (sum != 0) {
    cout << -1;
    return 0;
  }
  ll cura = a[0], curb = b[0];
  int len = 0;
  for (i = j = 1; i < n && j < m;) {
    if (cura == curb) {
      cura = a[i++];
      curb = b[j++];
      len++;
    } else if (cura > curb) {
      curb += b[j++];
    } else {
      cura += a[i++];
    }
  }
  cout << len + 1;
}
