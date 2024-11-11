#include <bits/stdc++.h>
using namespace std;
long long _d, n, k;
long long findpos(long long Id) {
  if (Id == 0) return k * (k + 1) / 2;
  long long pos2 = findpos(Id / k);
  long long fore = pos2 - 1, back = k * k + 1 - pos2;
  long long A = Id % k, B = k - Id % k;
  if (fore / k >= Id % k + 1) return k * (k + 1) / 2 - Id % k;
  if (back / k >= B) return k * (k + 1) / 2 + B;
  return k * (k + 1) / 2 - A - 1 + back % k;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    _d = k * k + 1;
    long long id = (n - 1) / _d;
    long long p = findpos(id);
    long long rest = (n - 1) % _d + 1;
    if ((n - 1) % _d + 1 == p)
      printf("%lld\n", (id + 1) * (k + 1));
    else {
      long long ans1 = id * k * (k + 1);
      long long ans2 = rest - (rest >= p);
      ans2 = ((ans2 - 1) / k) * (k + 1) + (ans2 - 1) % k + 1;
      printf("%lld\n", ans1 + ans2);
    }
  }
}
