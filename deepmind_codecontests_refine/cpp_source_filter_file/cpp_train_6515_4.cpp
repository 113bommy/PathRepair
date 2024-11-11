#include <bits/stdc++.h>
using namespace std;
int n, mx, mn = 12, i;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    int x;
    cin >> x;
    mx = max(x, mx);
    mn = min(x, mn);
  }
  cout << (mx ^ mn) << endl;
}
