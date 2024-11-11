#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  long long ans = 0, s1 = 0, s2 = 0;
  for (int i = int(0); i <= int(n - 1); i++) {
    cin >> a[i];
    ans += a[i] / 2;
    a[i] %= 2;
  }
  for (int i = int(0); i <= int(n - 1); i++) {
    if (a[i] % 2)
      s1 += a[i];
    else
      s2 += a[i];
  }
  ans += min(s1, s2);
  cout << ans;
}
