#include <bits/stdc++.h>
using namespace std;
template <class t>
vector<t> sort(vector<t> &a) {
  return sort(a.begin(), a.end());
}
long long a[2000100], b[2000100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int s = 0;
    for (int i = 0; i < n; i++) cin >> a[i], a[n + i] = a[i], s += a[i];
    for (int i = 0; i < n; i++) cin >> b[i], b[n + i] = b[i], s -= b[i];
    long long d = b[0];
    bool res = 1;
    for (int i = 1; i < 2 * n; i++) {
      d += b[i] - a[i];
      if (d < 0) {
        res = 0;
      }
      d = min(d, b[i]);
    }
    if (s > 0) res = 0;
    cout << (res ? "Yes\n" : "No\n");
  }
  return 0;
}
