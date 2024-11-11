#include <bits/stdc++.h>
using namespace std;
int chh;
long long n, ans;
vector<long long> a;
long long add(long long x, long long y, long long z) {
  if (x == y && y == z) return 1;
  if (x == y || x == z || y == z) return 3;
  return 6;
}
int main() {
  long long r, x, y, z, sz, cnt;
  while (cin >> n) {
    if (n % 3) {
      puts("0");
      continue;
    }
    n /= 3;
    a.clear();
    for (long long i = 2; i * i <= n; i++) {
      if (n % i) continue;
      a.push_back(i), a.push_back(n / i);
    }
    sort((a).begin(), (a).end());
    sz = (a).size();
    ans = 0;
    for (int i = 0; i < (sz); i++) {
      x = a[i];
      if (x * x * x > n) break;
      for (int j = (i); j <= (sz); j++) {
        y = a[j];
        if (n % (x * y)) continue;
        z = n / (x * y);
        if (z < y) break;
        if (z > x + y) continue;
        cnt = x % 2 + y % 2 + z % 2;
        if (cnt == 1 || cnt == 3) continue;
        ans += add(x, y, z);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
