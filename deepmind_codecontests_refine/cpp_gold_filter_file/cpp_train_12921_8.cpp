#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, r;
  cin >> n;
  vector<int> a(n), b(n);
  vector<bool> v(n + 1, true);
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  j = 0;
  for (i = 0; i < n; i++) {
    r = 0;
    while (v[b[i]]) v[a[j]] = false, j++, r++;
    cout << r << " ";
  }
  cout << endl;
}
