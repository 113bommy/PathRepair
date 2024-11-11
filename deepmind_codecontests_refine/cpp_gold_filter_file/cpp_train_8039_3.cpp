#include <bits/stdc++.h>
using namespace std;
bool isPal(const string& s) {
  int l = s.length();
  for (int i = 0; i < l / 2; i++) {
    if (s[i] != s[l - i - 1]) return false;
  }
  return true;
}
int getLongPal(const string& s) {
  int m = 0;
  int l = s.length();
  for (int i = 1; i <= l; i++) {
    if (isPal(s.substr(0, i))) m = i;
  }
  return m;
}
int main() {
  int n, k, l;
  string s, t, w, torig, trev;
  cin >> n;
  for (int j = 0; j < n; j++) {
    cin >> s;
    k = 0;
    l = s.length();
    while (s[k] == s[l - k - 1] && k < l - k - 1) k++;
    t = s.substr(k, l - 2 * k);
    torig = t;
    trev = t;
    reverse(trev.begin(), trev.end());
    int tl = t.length();
    int m1 = getLongPal(torig);
    int m2 = getLongPal(trev);
    w = (m1 >= m2) ? torig.substr(0, m1) : trev.substr(0, m2);
    cout << s.substr(0, k) << w << s.substr(l - k, k) << endl;
  }
  return 0;
}
