#include <bits/stdc++.h>
using namespace std;
long long k, d, t, ans, p, s, flag;
int main() {
  scanf("%lld%lld%lld", &k, &d, &t);
  t *= 2;
  p = (k + d - 1) / d;
  s = 2 * k + p * d - k;
  ans = t / s * p * d;
  t = t % s;
  if (t <= 2 * k)
    ans += t / 2, flag = t % 2;
  else
    t -= 2 * k, ans += t + k;
  cout << ans;
  if (flag)
    cout << ".5";
  else
    cout << ".0";
  return 0;
}
