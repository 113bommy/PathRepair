#include <bits/stdc++.h>
using namespace std;
long long fp(long long b, long long p) {
  long long res = 1;
  while (p) {
    if (p % 2) res = (res * b) % 1000000007;
    b = (b * b) % 1000000007;
    p /= 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  if (k == -1 && n % 2 != m % 2)
    return cout << 0, 0;
  else
    cout << fp(2, (n - 1) * (m - 1));
  return 0;
}
