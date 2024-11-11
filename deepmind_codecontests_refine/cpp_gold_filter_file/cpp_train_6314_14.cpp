#include <bits/stdc++.h>
using namespace std;
long long n, q, x;
long long get(long long a) {
  if (a % 2 == 1)
    return (a + 1) / 2;
  else {
    long long cnt = (2 * n - a) / 2;
    return get(a + cnt);
  }
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> q;
  for (long long i = 1; i <= q; ++i) {
    cin >> x;
    cout << get(x) << '\n';
  }
}
