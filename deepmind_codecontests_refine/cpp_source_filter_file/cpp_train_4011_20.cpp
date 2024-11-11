#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int s, x, ans;
  cin >> s >> x;
  long long int hieu = s - x;
  if (hieu & 1ll) {
    cout << "0";
    return 0;
  }
  hieu = hieu / 2ll;
  int no = __builtin_popcountll(x);
  ans = 1ll << no;
  for (int i = 0; i < 64; i++) {
    int a = (x & (1 << i)) && 1;
    int b = (hieu & (1 << i)) && 1;
    if (a == b && a == 1) ans = 0;
  }
  if (s == x) ans -= 2;
  if (ans > 0)
    cout << ans << endl;
  else
    cout << "0" << endl;
}
