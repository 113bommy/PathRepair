#include <bits/stdc++.h>
const int V = 1000000000;
using namespace std;
inline void rcin() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
long long n, t;
int main() {
  rcin();
  cin >> t;
  while (t--) {
    cin >> n;
    long long sum = 0;
    sum = n * (n + 1) / 2;
    long long lg = 0;
    while ((1 << lg) <= n) {
      sum -= (1 << lg) * 2;
      lg++;
    }
    cout << sum << endl;
  }
  return 0;
}
