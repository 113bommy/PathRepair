#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long INF = 1e18 + 7;
int main() {
  long long a, ta, b, tb;
  cin >> a >> ta >> b >> tb;
  long long h, m, t;
  scanf("%lld:%lld", &h, &m);
  t = h * 60 + m;
  long long to = t + ta;
  t -= tb;
  long long res = 0;
  while (t < (to)) {
    long long T = t - 300;
    if (300 <= t && t < 1440 && T % b == 0) res++;
    t++;
  }
  cout << res;
  return 0;
}
