#include <bits/stdc++.h>
using namespace std;
const long long N = 100100 * 2;
long long n, k, s[N];
string ss, ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k >> ss;
  for (long long i = 0; i <= ss.length() - 1; i++) s[i] = ss[i] - 'a';
  for (long long i = 0; i <= ss.length() - 1; i++) {
    if (k > 0) {
      long long di = 25 - s[i];
      if (s[i] >= di) {
        if (k >= s[i]) {
          ans += 'a', k -= s[i];
        } else {
          ss[i] += k;
          ans += (ss[i]);
          k -= k;
          continue;
        }
      } else {
        if (k >= di) {
          ans += 'z', k -= di;
        } else {
          ss[i] -= k;
          ans += (ss[i]);
          k -= k;
          continue;
        }
      }
    } else {
      ans += ss[i];
    }
  }
  if (k > 0)
    cout << "-1" << endl;
  else
    cout << ans << endl;
}
