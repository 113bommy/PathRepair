#include <bits/stdc++.h>
using namespace std;
long long p1[300200];
long long p2[300200];
signed main() {
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long c1 = 0;
  long long c2 = 0;
  long long s1 = 0;
  long long s2 = 0;
  for (long long i = 0; i < s.size() / 2; ++i) {
    if (s[i] == '?') c1++;
    if (s[i] != '?') s1 += s[i] - '0';
  }
  for (long long i = s.size() / 2; i < s.size(); ++i) {
    if (s[i] == '?') c2++;
    if (s[i] != '?') s2 += s[i] - '0';
  }
  if (c1 == c2) {
    if (s1 == s2)
      cout << "Bicarp" << '\n';
    else
      cout << "Monocarp" << '\n';
    return 0;
  }
  if (c1 > c2) swap(c1, c2), swap(s1, s2);
  if (s1 == s2) {
    cout << "Monocarp";
    return 0;
  }
  long long r = (c2 - c1) / 2;
  long long mxl = s1 + c1 * 9;
  long long mxr = (c2 - r) * 9 + s2;
  if (mxl > mxr) {
    cout << "Monocarp";
  } else
    cout << "Bicarp";
  return 0;
}
