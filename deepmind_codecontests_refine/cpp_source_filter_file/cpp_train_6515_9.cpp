#include <bits/stdc++.h>
using namespace std;
int mx, n;
int a[101];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  cout << (a[n - 1] ^ mx);
  return 0;
}
