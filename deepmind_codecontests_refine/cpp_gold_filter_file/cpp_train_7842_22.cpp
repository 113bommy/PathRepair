#include <bits/stdc++.h>
using namespace std;
long long n, k, b, t;
long long fp(long long b, long long p) {
  if (p == 0) return 1;
  if (p % 2 == 0) return fp(b * b, p / 2);
  return fp(b, p - 1) * b;
}
int main() {
  while (cin >> k >> b >> n >> t) {
    long long aye = 1, i = 0;
    while (aye <= t) {
      aye *= k;
      aye += b;
      i++;
    }
    cout << max(n - i + 1, 0ll) << endl;
  }
}
