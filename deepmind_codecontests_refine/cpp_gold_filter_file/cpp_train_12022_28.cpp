#include <bits/stdc++.h>
using namespace std;
const int INFint = 2147483647;
const long long INF = 9223372036854775807ll;
const long long MOD = 1000000007ll;
const long double EPS = 1e-9;
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> l(n);
  vector<int> r(n);
  int mx = 0;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    mx = max(mx, r[i]);
  }
  long double ans = 0;
  for (int i = 0; i <= mx; i++) {
    for (int m = 0; m < (1 << n); m++) {
      int cnt = 0;
      for (int j = 0; j < n; j++)
        if ((m & (1 << j))) cnt++;
      if (cnt < 2) continue;
      long double cur = 1;
      for (int j = 0; j < n; j++) {
        int cl = l[j];
        int cr = r[j];
        if ((m & (1 << j)))
          cl = (cl <= i) ? i + 1 : cl;
        else
          cr = (cr > i) ? i : cr;
        if (cl > cr) {
          cur = 0;
          break;
        }
        cur *= 1.0 * (cr - cl + 1) / (r[j] - l[j] + 1);
      }
      ans += cur;
    }
  }
  cout << fixed << setprecision(9) << ans;
  fprintf(stderr, "\nTIME = %lf\n", 1.0 * clock() / CLOCKS_PER_SEC);
  return 0;
}
