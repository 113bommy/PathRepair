#include <bits/stdc++.h>
using namespace std;
string transform(string s, int l, int r, int k) {
  string s1, s2;
  int a[s.size()];
  for (int i = 0; i < l; i++) a[i] = 1;
  for (int i = l; i < s.size(); i++) a[i] = 0;
  for (int i = 0; i < l; i++) s1 += s[i];
  if (r - l != 0)
    k = k % (r - l);
  else
    return s;
  int i = r;
  while (k--) {
    a[i] = 1;
    s2 += s[i];
    i--;
  }
  for (int i = s2.size() - 1; i >= 0; i--) {
    s1 += s2[i];
  }
  for (int i = l; i < s.size(); i++) {
    if (a[i] == 0) s1 += s[i];
  }
  return s1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  int t, l, r, k;
  cin >> t;
  while (t--) {
    cin >> l >> r >> k;
    l--;
    r--;
    s = transform(s, l, r, k);
  }
  cout << s;
}
