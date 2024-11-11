#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  string s;
  cin >> k >> s;
  int n = (int)s.length();
  vector<int> a(n, 0), b(1, 0);
  for (int(i) = (0); (i) < (n); (i)++) {
    if (i) a[i] += a[i - 1];
    if (s[i] == '1') {
      a[i]++;
      b.push_back(i);
    }
  }
  long long ans = 0;
  for (int(i) = (0); (i) < (n); (i)++) {
    int t = a[i] + k;
    int l = (int)b.size();
    if (s[i] == '1') {
      if (k == 0) continue;
      if (t - 1 < l) ans += (t < l ? b[t] : n) - b[t - 1];
    } else {
      if (k == 0) {
        ans += (t + 1 < l ? b[t + 1] : n) - i;
      } else if (t < l)
        ans += (t + 1 < l ? b[t + 1] : n) - b[t];
    }
  }
  cout << ans << endl;
  return 0;
}
