#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  string s[n], t, k;
  string mid = "", first, last, res;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++) {
    t = s[i];
    reverse(t.begin(), t.end());
    if (t == s[i]) {
      if (t.size() > mid.size())
        mid = t;
      else if (mid.substr(0, t.size()) == t)
        mid += t;
    } else {
      for (int j = i + 1; j < n; j++) {
        k = s[j];
        reverse(k.begin(), k.end());
        if (k == s[i]) first += s[i], last += k;
      }
    }
  }
  reverse(last.begin(), last.end());
  res = first + mid + last;
  cout << res.size() << endl << res;
  return 0;
}
