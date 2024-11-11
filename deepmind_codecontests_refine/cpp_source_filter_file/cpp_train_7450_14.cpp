#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int M = 107;
const int INF = 1e9 + 7;
const long double EPS = 1e-9;
long long t[N];
int main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) t[i] = t[i - 1] * 2ll + 1ll;
  while (n >= 0) {
    if (k > t[n] / 2ll + 1ll) {
      k -= t[n] / 2ll + 1ll;
    } else if (k == t[n] / 2ll + 1ll)
      return cout << n, 0;
    n--;
  }
}
