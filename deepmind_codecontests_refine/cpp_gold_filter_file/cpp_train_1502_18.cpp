#include <bits/stdc++.h>
using namespace std;
string s;
long long money, ans;
long long nb, ns, nc, pb, ps, pc;
long long f[3];
long long cal(long long n) {
  long long ret = n * f[0] * pb + n * f[1] * pc + n * f[2] * ps;
  long long sub =
      min(nb, n * f[0]) * pb + min(ns, n * f[2]) * ps + min(nc, n * f[1]) * pc;
  ret -= sub;
  return ret;
}
int main() {
  cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> money;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'B')
      f[0]++;
    else if (s[i] == 'C')
      f[1]++;
    else
      f[2]++;
  }
  long long l = 0, r = 1e15, mid;
  while (l <= r) {
    mid = (l + r) / 2;
    long long res = cal(mid);
    if (money >= res) {
      ans = mid;
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  cout << ans;
  return 0;
}
