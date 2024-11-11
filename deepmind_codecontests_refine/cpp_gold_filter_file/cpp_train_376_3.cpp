#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  ;
  int b;
  cin >> b;
  ;
  int fl = abs(b - a) / 2.0;
  int cl = (abs(b - a) + 1) / 2.0;
  int ans = 0;
  int i;
  for (i = 1; i <= abs(b - a) / 2; i++) ans += i;
  ans *= 2;
  if (cl > fl) ans += i;
  cout << ans;
  return 0;
}
