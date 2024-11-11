#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int mi1 = 10000000009, mi2 = 0, ma1 = -10000000009, ma2 = 0, i, j,
                k, l, m, t, n, f = 0;
  string a;
  char b;
  cin >> t;
  while (t--) {
    string s;
    cin >> a >> n >> b;
    if (b == 'N') {
      if (a.size() == 1) {
        if (a[0] == '<')
          s += ">=";
        else
          s += "<=";
      } else {
        if (a[0] == '<')
          s += ">";
        else
          s += "<";
      }
    } else {
      s += a;
    }
    if (s.size() == 1) {
      if (s[0] == '<') {
        mi1 = min(mi1, n - 1);
      } else {
        ma1 = max(ma1, n + 1);
      }
    } else {
      if (s[0] == '<') {
        mi1 = min(mi1, n);
      } else {
        ma1 = max(ma1, n);
      }
    }
  }
  if (ma1 > mi1) {
    cout << "Impossible\n";
  } else {
    if (ma1 != -1000000000)
      cout << ma1 << '\n';
    else
      cout << mi1 << '\n';
  }
  return 0;
}
