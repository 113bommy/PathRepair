#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, s = 0;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    int l;
    cin >> l;
    s += l;
  }
  s = abs(s);
  int ans = s / x;
  if (s % x != 0) ans++;
  cout << ans << endl;
}
