#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  long long int a, b, c, d, i, j, k, n, m, t;
  cin >> t;
  while (t--) {
    cin >> a;
    vector<int> v(a);
    for (i = 0; i < a; i++) cin >> v[i];
    string s = "", x = "";
    for (i = 0; i < v[0]; i++) {
      s += 'a';
      x += 'a';
    }
    if (v[0] == 0) {
      s = "a";
      x = "b";
    }
    cout << s << endl;
    if (a == 0) cout << x << endl;
    char g;
    g = 'y';
    for (i = 1; i < a; i++) {
      s = x;
      if (v[i] == 0) {
        if (s[0] < 'z')
          g = s[0] + 1;
        else
          g = s[0] - 1;
        x = g;
      } else if (v[i] <= s.size()) {
        x = "";
        for (j = 0; j < v[i]; j++) {
          x += s[j];
        }
      } else {
        x = s;
        for (j = s.size(); j < v[i]; j++) {
          if (g >= 'z') g = 'a';
          g++;
          x += g;
          s += g;
        }
      }
      cout << s << endl;
      if (i == a - 1) cout << x << endl;
    }
  }
  return 0;
}
