#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100], m = -1;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    m = max(m, a[i]);
  }
  cout << (a[n] | m) << endl;
  return 0;
}
