#include <bits/stdc++.h>
using namespace std;
pair<int, int> t[2000];
int main() {
  ios_base::sync_with_stdio(0);
  int a;
  cin >> a;
  string s;
  cin >> s;
  int f = 0, k = 0, z = 0, i = 0, l = 0, fa = 0, fl = 0;
  while (i < s.length()) {
    if (fa && f == 2) {
      t[l].first = k;
      if (fl == 0) t[l].first = 1;
      if (z) t[l].first = -t[l].first;
      if (s[i - 1] == 'a') t[l].second = 1;
      l++;
      z = f = k = fa = fl = 0;
      if (s[i] == '-') z = 1;
    } else if (s[i] == '+')
      f++;
    else if (s[i] == 'a')
      fa = 1;
    else if (s[i] != '*') {
      k = (k * 10) + (s[i] - '0');
      fl = 1;
    }
    i++;
  }
  t[l].first = k;
  if (k == 0) t[l].first = 1;
  if (z) t[l].first = -t[l].first;
  if (s[i - 1] == 'a') t[l].second = 1;
  l++;
  sort(t, t + l);
  long long ans = 0;
  for (int i = 0; i < l; i++) {
    if (t[i].second == 1) {
      a++;
      ans += t[i].first * a;
    } else {
      ans += t[i].first * a;
      a++;
    }
  }
  cout << ans << endl;
  return 0;
}
