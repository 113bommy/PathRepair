#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int a, b;
  cin >> a >> b;
  if (b % 2 == 1) {
    if ((b + 1) / 2 >= a)
      cout << b / 2 << endl;
    else
      cout << b - a << endl;
  } else {
    if ((b / 2) + 2 >= a)
      cout << (b / 2) - 1 << endl;
    else
      cout << b - a << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
