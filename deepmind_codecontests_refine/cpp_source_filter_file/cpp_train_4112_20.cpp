#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ans = 0;
  int n;
  cin >> n;
  int a = 9, t = 1;
  while (n > a) {
    n = n - a;
    ans += a * t;
    t++;
    a *= 10;
  }
  if (n != 10) ans += n * t;
  cout << ans;
  return 0;
}
