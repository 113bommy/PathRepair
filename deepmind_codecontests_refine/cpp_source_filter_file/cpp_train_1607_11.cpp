#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(20);
  int a[3], b[3];
  for (int i = (0); i <= (2); ++i) cin >> a[i];
  for (int i = (0); i <= (2); ++i) cin >> b[i];
  int ans = 0;
  for (int i = (0); i <= (2); ++i) ans += a[i] == b[i];
  if (ans >= 2)
    puts("YES");
  else
    puts("NO");
  return 0;
}
