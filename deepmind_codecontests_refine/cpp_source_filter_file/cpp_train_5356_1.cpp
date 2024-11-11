#include <bits/stdc++.h>
using namespace std;
int n, p, x, ans, k;
bool mark[400];
int main() {
  cin >> p >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (mark[x % p] && k == 0) {
      ans = i;
      k = 1;
    } else
      mark[x % p] = 1;
  }
  if (ans == 0)
    cout << "-1" << endl;
  else
    cout << ans << endl;
  return 0;
}
