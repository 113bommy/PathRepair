#include <bits/stdc++.h>
using namespace std;
long long n, ans;
string s, t, d;
int main() {
  long long i, j, x;
  cin >> n >> s;
  ans = n;
  t = "";
  for (j = 0; j < n; j++) {
    t += s[j];
    d = t + t;
    if (s.find(d) == 0) {
      x = n - t.size() + 1;
      ans = min(ans, x);
    }
  }
  cout << ans << endl;
  return 0;
}
