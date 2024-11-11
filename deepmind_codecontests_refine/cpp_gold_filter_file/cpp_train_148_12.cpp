#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int k, l, m, n, o;
  cin >> k >> l >> m >> n >> o;
  int s = k + l + m + n + o;
  if (k == 0 && l == 0 && m == 0 && n == 0 && o == 0)
    cout << "-1";
  else {
    if (s % 5 == 0)
      cout << s / 5;
    else
      cout << "-1";
  }
  return 0;
}
