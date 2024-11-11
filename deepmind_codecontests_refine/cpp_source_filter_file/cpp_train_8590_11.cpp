#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int n, d, h;
  cin >> n >> d >> h;
  if (d > 2 * h || d < h)
    cout << -1 << "\n";
  else if (d == 1 && n > 1) {
    cout << -1 << "\n";
  } else {
    long long int l = 1, r = 2, cnt = 0;
    while (cnt < h) {
      cout << l << " " << r << "\n";
      l++;
      r++;
      cnt++;
    }
    long long int rem = (d - h);
    l = 1, cnt = 0;
    while (cnt < rem) {
      cout << l << " " << r << "\n";
      l = r;
      r++;
      cnt++;
    }
    rem = n - 1 - d;
    long long int temp = 1;
    if (d == h) temp = 2;
    while (rem--) {
      cout << temp << " " << r << "\n";
      r++;
    }
  }
  return 0;
}
