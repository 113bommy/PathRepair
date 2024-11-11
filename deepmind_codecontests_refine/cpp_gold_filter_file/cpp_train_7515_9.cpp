#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const long long inf = 1e18;
int n;
long long s[N];
long long cal(long long k) {
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    long long limMin = s[i] / k * k;
    long long limMax = (s[i] / k + 1) * k;
    ans += min(s[i] - limMin, limMax - s[i]);
  }
  return ans;
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  if (fopen("main.in", "r"))
    freopen("main.in", "r", stdin);
  else if (fopen("1255E"
                 ".inp",
                 "r"))
    freopen(
        "1255E"
        ".inp",
        "r", stdin),
        freopen(
            "1255E"
            ".out",
            "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    s[i] = s[i - 1] + x;
  }
  long long res = inf;
  int p = 2;
  long long tmp = s[n];
  while (1LL * p * p <= tmp) {
    if (tmp % p == 0) {
      res = min(res, cal(p));
      while (tmp % p == 0) tmp /= p;
    }
    p++;
  }
  if (tmp != 1) res = min(res, cal(tmp));
  if (res == inf) res = -1;
  cout << res << '\n';
  return 0;
}
