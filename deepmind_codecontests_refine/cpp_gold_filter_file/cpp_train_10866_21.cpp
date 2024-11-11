#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<int> ll(n), lr(n);
  ll[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] <= a[i + 1])
      ll[i] = ll[i + 1];
    else
      ll[i] = i;
  }
  for (int i = 1; i < n; i++) {
    if (a[i] <= a[i - 1])
      lr[i] = lr[i - 1];
    else
      lr[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    if (ll[l] >= lr[r])
      cout << "Yes";
    else
      cout << "No";
    cout << endl;
  }
  return 0;
}
