#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, i, e, f, g, n, m, k, l, t, A[500005], le, ri, mid, ans;
string s, s1;
int main() {
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
      cin >> s;
      a = 1;
      ans = 0;
      for (long long i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '1') ans += a;
        a *= 2;
      }
      A[i] = ans;
    }
    le = 0;
    ri = (1 << m) - 1;
    ans = 0;
    while (le <= ri) {
      mid = (le + ri) / 2;
      a = 0;
      b = 0;
      for (long long i = 1; i <= n; i++) {
        if (A[i] < mid)
          a++;
        else
          b++;
      }
      if (mid - a < (1ll << m) - mid - b) {
        le = mid + 1;
        ans = mid;
      } else
        ri = mid - 1;
    }
    s1 = "";
    while (ans > 0) {
      if (ans % 2 == 1)
        s1 += '1';
      else
        s1 += '0';
      ans /= 2;
    }
    while (s1.size() < m) s1 = s1 + '0';
    reverse(s1.begin(), s1.end());
    cout << s1 << endl;
  }
}
