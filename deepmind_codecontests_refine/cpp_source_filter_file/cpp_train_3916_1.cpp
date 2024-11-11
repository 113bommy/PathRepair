#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k, i, a, f = 0, tw1 = 0, tw2 = 0;
  cin >> n >> k;
  for (i = 0; i < k; i++) {
    cin >> a;
    f += a / 4;
    a %= 4;
    if (a == 3)
      f++;
    else {
      if (a == 2) tw2++;
      if (a == 1) tw1++;
    }
  }
  long long int tt = 2 * n, ff = n;
  long long int tem = min(tw2, tt);
  tt -= tem;
  tw2 -= tem;
  tem = min(tw1, tt);
  tt -= tem;
  tw1 -= tem;
  tem = min(tt, f * 2);
  tt -= tem;
  f -= tem / 2;
  tem = min(tw1, tw2);
  tw1 -= tem;
  tw2 -= tem;
  ff -= tem;
  ff -= 2 * tw2 / 3;
  ff -= (tw1 + 1) / 2;
  ff -= f;
  if (ff < 0) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  return 0;
}
