#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k, l, i, c = 0;
  cin >> n >> m;
  cin >> k >> l;
  long long int a[n], b[m];
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < m; i++) cin >> b[i];
  for (i = 0; i < n; i++) {
    if (a[i] < b[m - l]) c++;
  }
  if (c >= k && m >= l)
    cout << "yes";
  else
    cout << "no";
}
