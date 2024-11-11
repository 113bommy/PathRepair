#include <bits/stdc++.h>
using namespace std;
int main() {
  int k, n, s, p;
  cin >> k >> n >> s >> p;
  int ans1, ans2;
  if (n / s != 0 && n % s != 0)
    ans1 = n / s + 1;
  else if (n / s != 0 && n % s == 0)
    ans1 = n / s;
  else
    ans1 = 1;
  ans1 = ans1 * k;
  if (ans1 / p != 0 && ans1 % p != 0)
    ans2 = ans1 / p + 1;
  else if (ans1 / p != 0 && ans1 % p == 0)
    ans2 = ans1 / p;
  else
    ans2 = ans1;
  cout << ans2 << endl;
  return 0;
}
