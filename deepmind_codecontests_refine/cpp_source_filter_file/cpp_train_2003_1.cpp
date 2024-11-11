#include <bits/stdc++.h>
using namespace std;
template <typename T>
ostream& operator<<(ostream& stream, const pair<T, T>& p) {
  return stream << "(" << p.first << "," << p.second << ") ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  while (T--) {
    int i, j, n;
    cin >> n;
    long long a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long mx = a[0], mxdiff = a[0] - a[1];
    for (i = 1; i < n; i++) {
      if (mx - a[i] > mxdiff) mxdiff = mx - a[i];
      mx = max(mx, a[i]);
    }
    if (mxdiff > 0)
      cout << (int)ceil(log2f(mxdiff)) + 1 << "\n";
    else
      cout << 0 << "\n";
  }
  return 0;
}
