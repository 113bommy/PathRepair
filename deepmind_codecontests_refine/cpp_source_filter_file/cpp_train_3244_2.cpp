#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, m, ara[20000], t;
  cin >> t;
  while (t--) {
    long long int cnt1 = 0, cnt2 = 0, cnt3 = 0, a, sum = 0, x;
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a;
      if (a % 3 == 0)
        cnt3++;
      else if (a % 3 == 1)
        cnt1++;
      else if (a % 3 == 2)
        cnt2++;
    }
    sum = cnt3;
    x = min(cnt1, cnt2);
    sum = sum + x;
    cnt1 = cnt1 - x;
    cnt2 = cnt2 - x;
    sum = sum + (cnt1 / 3);
    sum = sum + ((cnt2 * 2) / 3);
    cout << sum << endl;
  }
}
