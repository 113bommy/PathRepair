#include <bits/stdc++.h>
using namespace std;
long long M;
bool ada = false;
long long f(long long a, long long n) {
  long long t1 = (a - 1) / 2 * (a);
  long long t2 = a * (n - 1);
  return t1 + t2;
}
int main() {
  cin >> M;
  for (long long i = 1; i <= M + 1; i *= 2) {
    long long l = 0, r = 1e18 / (i - 1);
    r = min(r, (long long)1000000000);
    while (l <= r) {
      long long mid = (l + r) / 2;
      long long tmp = f(2 * mid + 1, i);
      if (tmp == M) {
        cout << (2 * mid + 1) * i << endl;
        ada = 1;
        break;
      }
      if (tmp > M) r = mid - 1;
      if (tmp < M) l = mid + 1;
    }
  }
  if (!ada) puts("-1");
}
