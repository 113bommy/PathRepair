#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long ans;
long long erfen(long long l, long long r) {
  if (l == r) {
    return l;
  }
  long long mid = (l + r) / 2;
  long long c = ((mid - 1) * mid) / 2;
  if (c >= m)
    return erfen(l, mid);
  else
    return erfen(mid + 1, r);
}
int main() {
  cin >> n >> m;
  if (m == 0) {
    cout << n << " " << n << endl;
    return 0;
  }
  cout << max(n - 2 * m, 0ll) << " ";
  cout << n - erfen(0, n) << endl;
  return 0;
}
