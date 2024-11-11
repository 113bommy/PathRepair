#include <bits/stdc++.h>
using namespace std;
const int NMAX = 100 + 7;
long long n, k, a[NMAX];
long long sum, s, mx;
bool moze(long long m) {
  long long sol = 0;
  for (int i = 1; i <= n; i++) sol += (a[i] + m - 1) / m;
  return m * sol <= s;
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
  }
  s = sum + k;
  long long res = 0;
  for (int i = 1; i <= sqrt(mx) + 1; i++) {
    if (moze(i)) res = max(res, 1LL * i);
    if (moze(mx / i)) res = max(res, 1LL * mx / i);
  }
  cout << res;
  return 0;
}
