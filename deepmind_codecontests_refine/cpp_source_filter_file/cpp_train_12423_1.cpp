#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, s;
  cin >> a;
  cin >> s;
  long la = 0, ls = 0, i = 0, ps = 0, pv = 0;
  la = a.length();
  ls = s.length();
  vector<int> v;
  for (i = 0; i < ls; i++) v.push_back(s[i]);
  sort(v.rbegin(), v.rend());
  while (ps < la && pv < ls - 1) {
    if (a[ps] < v[pv]) {
      a[ps] = v[pv];
      ps++;
      pv++;
    } else if (a[ps] >= v[pv])
      ps++;
  }
  cout << a;
  return 0;
}
