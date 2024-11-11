#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, sum = 0, z = 0, v = 0, s = 0, d = 0, x;
  cin >> n;
  long long a[n], l = 0, r = n - 1, c = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = l; l <= r;) {
    c++;
    if (a[l] <= a[r] || a[l] >= a[r]) {
      if (c % 2 != 0) {
        sum += max(a[l], a[r]);
      }
      if (c % 2 == 0) {
        s += max(a[l], a[r]);
      }
      if (a[l] >= a[r])
        l++;
      else if (a[l] <= a[r])
        r--;
    }
  }
  cout << sum << " " << s;
  return 0;
}
