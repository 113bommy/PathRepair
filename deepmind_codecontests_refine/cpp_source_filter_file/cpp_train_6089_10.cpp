#include <bits/stdc++.h>
using namespace std;
int n, x, k, d, odd, even;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (x % 2 == 1)
      odd++;
    else
      even++;
  }
  d = n - k;
  if (d == 0) {
    if (odd % 2 == 1)
      cout << "Stannis";
    else
      cout << "Daenerys";
    return 0;
  }
  if (odd == 0) {
    cout << "Daenerys";
    return 0;
  }
  if (d % 2 == 1) {
    if (k % 2 == 1) {
      if (d / 2 >= odd)
        cout << "Daenerys";
      else
        cout << "Stannis";
    } else {
      if (d / 2 <= min(odd, even))
        cout << "Daenerys";
      else
        cout << "Stannis";
    }
  } else {
    if (k % 2 == 1 && d / 2 >= even && (odd - (even - d / 2) - d / 2) % 2 == 1)
      cout << "Stannis";
    else
      cout << "Daenerys";
  }
  return 0;
}
