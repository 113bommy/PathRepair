#include <bits/stdc++.h>
using namespace std;
long long N, H;
long long f(long long mx) {
  long long n = N;
  long long res = 0;
  if (mx <= H) {
    res = mx;
    n -= mx * (mx + 1) / 2;
    if (n < 0) return -1;
    res += n / mx;
    if (n % mx > 0) res++;
  } else {
    n -= mx * (mx + 1) - H * (H + 1) / 2 - mx;
    res = mx + mx - H - 1;
    if (n < 0) return -1;
    res += n / mx;
    if (n % mx > 0) res++;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(nullptr);
  cin >> N >> H;
  long long L = 0, R = 2e9 + 7;
  while (L + 1 < R) {
    long long M = L + (R - L) / 2;
    if (f(M) == -1)
      R = M;
    else
      L = M;
  }
  cout << f(L);
  return 0;
}
