#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, count0 = 0, count1 = 0, ans = 0, n0 = 0, n1 = 0;
  cin >> n;
  string a, b;
  cin >> a >> b;
  for (long i = 0; i < n; i++) {
    if (a[i] == '0') {
      count0++;
    } else {
      count1++;
    }
  }
  for (long i = 0; i < n; i++) {
    if (b[i] == '1') {
      continue;
    }
    if (a[i] == '0') {
      ans += count1;
      n0++;
      ans -= n1;
    }
    if (a[i] == '1') {
      ans += count0;
      n1++;
      ans -= n0;
    }
  }
  cout << ans << endl;
  return 0;
}
