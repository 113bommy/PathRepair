#include <bits/stdc++.h>
using namespace std;
const int N = 1001;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long i, j, k, n, r, t, ans, c;
  cin >> t;
  string a, b;
  while (t--) {
    cin >> n;
    r = 1;
    ans = LLONG_MAX;
    while (r <= 1e11) {
      c = 0;
      a = to_string(n);
      b = to_string(r);
      i = 0;
      for (j = 0; j < b.length(); j++) {
        if (i >= a.length()) {
          c++;
          i++;
        } else if (a[i] == b[j]) {
          i++;
        } else {
          i++;
          c++;
          j--;
        }
      }
      if (i < a.length()) {
        c += (a.length() - i);
      }
      ans = min(c, ans);
      r *= 2;
    }
    cout << ans << "\n";
  }
  return 0;
}
