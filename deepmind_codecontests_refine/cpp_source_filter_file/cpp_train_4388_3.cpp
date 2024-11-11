#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, j, i, suml = 0, sumr = 0, sml = 0, smr = 0, pin = 1, x, ans = 0, k,
               markl, markr, p;
  vector<unsigned long long> odd, even;
  cin >> n;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (j = 1; j <= n; j++) {
    cin >> k;
    if (j % 2 == 1) {
      p = 0;
      if (odd.size() != 0) p = odd[odd.size() - 1];
      odd.push_back(k + p);
    } else {
      p = 0;
      if (even.size() != 0) p = even[even.size() - 1];
      even.push_back(p + k);
    }
  }
  while (pin <= n) {
    suml = 0;
    sumr = 0;
    if (pin % 2 == 1) {
      if (pin / 2 - 1 >= 0) {
        suml = suml + odd[pin / 2 - 1];
        sumr = sumr + even[pin / 2 - 1];
      }
      if (pin / 2 - 1 >= 0)
        x = even[pin / 2 - 1];
      else
        x = 0;
      if (even[even.size() - 1] > x) {
        suml = suml + (even[even.size() - 1] - x);
      }
      if (pin / 2 >= 0)
        x = odd[pin / 2];
      else
        x = 0;
      if (odd[odd.size() - 1] > x) {
        sumr = sumr + (odd[odd.size() - 1] - x);
      }
    } else {
      if (pin / 2 - 1 >= 0) suml = suml + odd[pin / 2 - 1];
      if (pin / 2 - 2 >= 0) sumr = sumr + even[pin / 2 - 2];
      if (even[even.size() - 1] > even[pin / 2 - 1])
        suml = suml + (even[even.size() - 1] - even[pin / 2 - 1]);
      if (odd[odd.size() - 1] > odd[pin / 2 - 1])
        sumr = sumr + (odd[odd.size() - 1] - odd[pin / 2 - 1]);
    }
    pin++;
    if (suml == sumr) ans++;
  }
  cout << ans << endl;
  return 0;
}
