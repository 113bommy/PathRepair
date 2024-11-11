#include <bits/stdc++.h>
using namespace std;
int const MAX = 10;
int const OO = (1 << 28);
int main() {
  long long N;
  cin >> N;
  long long mx = -1, mn = (1LL << 62);
  for (long long i = 1; (i * i) <= N; ++i) {
    if (N % i) continue;
    long long n = N / i;
    for (long long j = 1; (j * j) <= n; ++j) {
      if (n % j) continue;
      long long A = i, B = j, C = n / j;
      mn = min(mn, ((A + 1) * (B + 2) * (C + 2)) - N);
      mn = min(mn, ((B + 1) * (A + 2) * (C + 2)) - N);
      mn = min(mn, ((C + 1) * (A + 2) * (B + 2)) - N);
      mx = max(mx, ((A + 1) * (B + 2) * (C + 2)) - N);
      mx = max(mx, ((B + 1) * (A + 2) * (C + 2)) - N);
      mx = max(mx, ((C + 1) * (B + 2) * (A + 2)) - N);
    }
  }
  cout << mn << " " << mx << endl;
}
