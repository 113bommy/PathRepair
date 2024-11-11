#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  cin.get();
  vector<long long> a(n + 1);
  vector<bool> ingame(n + 1);
  for (long long i = 0; i < n + 1; ++i) {
    ingame[i] = true;
  }
  a[0] = 0;
  for (long long i = 1; i < n + 1; ++i) {
    cin >> a[i];
  }
  cin.get();
  long long d1, d2, out;
  out = 0;
  d1 = 0;
  d2 = 0;
  for (long long i = 1; i < n + 1; ++i) {
    if (ingame[i - 1]) d1 += a[i - 1] * (i - 2 - out);
    d2 = (i - 1 - out) * (n - i) * a[i];
    if (d1 - d2 < k) {
      ingame[i] = false;
      ++out;
      cout << i << endl;
    }
  }
  return 0;
}
