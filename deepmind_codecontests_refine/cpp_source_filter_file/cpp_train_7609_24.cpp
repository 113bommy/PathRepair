#include <bits/stdc++.h>
using namespace std;
int s[100000];
int main() {
  int n, ma = 0, mi = 1000000;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ma = max(ma, a);
    mi = min(mi, a);
  }
  cout << abs(n - 2 - (ma - mi - 1));
  return 0;
}
