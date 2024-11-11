#include <bits/stdc++.h>
using namespace std;
void read(int a = 0) {
  freopen("in", "r", stdin);
  if (a) freopen("out", "w", stdout);
}
long long power(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans *= a, ans %= 1000000009;
    b /= 2;
    a *= a, a %= 1000000009;
  }
  return ans;
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long blank = n - m;
  long long save = min(n - blank, (k - 1) * blank);
  long long dead = n - blank - save;
  save += dead % k;
  dead -= dead % k;
  long long t = dead / k;
  long long ans = (2 * k) % 1000000009 * (1 - power(2, t)) % 1000000009 * (-1);
  ans %= 1000000009;
  ans += save;
  ans %= 1000000009;
  cout << ans << endl;
}
