#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  string s, t;
  cin >> s;
  int ans = 0;
  for (long long i = 0; i < (int)s.size(); i++) {
    int a = s[i] - 'a';
    int x = 25 - a;
    if (ans + max(x, a) <= k) {
      ans += max(x, a);
      if (a > x)
        t += 'a';
      else
        t += 'z';
    } else {
      x = k - ans;
      ans = k;
      if (a + x <= 25)
        s[i] += x;
      else
        s[i] -= x;
      t += s.substr(i, 1);
    }
  }
  if (ans != k)
    cout << "-1\n";
  else
    cout << t << endl;
  return 0;
}
