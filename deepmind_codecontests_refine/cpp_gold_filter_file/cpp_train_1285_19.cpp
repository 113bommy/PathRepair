#include <bits/stdc++.h>
using namespace std;
long double PI = 3.14159265358979323846;
const long long modo = 1e9 + 7;
const long long inf = 1e15;
const long long ms = (5e6) + 5;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  long double k, b, n, t;
  cin >> k >> b >> n >> t;
  if (k == 1) {
    long long aa = ceil((((n * b) + 1) - t) / b);
    cout << max(0ll, aa);
  } else {
    long double pp = ((t * (k - 1)) + b) / (k + b - 1);
    long double tt = floor(log(pp) / log(k));
    long long aa = max(0ll, (long long)(n - tt));
    cout << aa;
  }
  return 0;
}
