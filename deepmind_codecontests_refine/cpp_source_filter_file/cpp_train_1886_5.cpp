#include <bits/stdc++.h>
using namespace std;
string rreplace(string s, string temp, string temp2) {
  string t = temp + '#' + s;
  vector<int> z(s.size() + 1 + temp.size(), 0);
  int l = 0, r = 0;
  for (int i = 1; i < t.size(); ++i) {
    if (r >= i) z[i] = min(r - i + 1, z[i - l]);
    while (i + z[i] < t.size() && t[i + z[i]] == t[z[i]]) ++z[i];
    if (i + z[i] - 1 > r) {
      r = i + z[i] - 1;
      l = i;
    }
  }
  for (int i = 1; i < t.size(); ++i) {
    if (z[i] == temp.size()) {
      for (int j = 0; j < temp.size(); ++j)
        s[i - temp.size() - 1 + j] = temp2[j];
      return s;
    }
  }
  return s;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  vector<string> b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  string s, t;
  int l, r, ll, rr;
  bool f = true;
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      int l1, r1;
      l1 = -1, r1 = a[i].size() - 1;
      for (int j = 0; j < a[i].size(); ++j)
        if (a[i][j] != b[i][j]) {
          r1 = j;
          if (l1 == -1) l1 = j;
        }
      if (f) {
        ll = l1, rr = r1;
        l = 0, r = a[i].size() - 1;
        s = a[i], t = b[i];
        f = false;
      } else {
        if (rr - ll != r1 - l1) {
          cout << "NO\n";
          return 0;
        }
        for (int j = 0; j < rr - ll + 1; ++j)
          if (s[ll + j] != a[i][l1 + j] || t[ll + j] != b[i][l1 + j]) {
            cout << "NO\n";
            return 0;
          }
        int j = 1;
        while (ll - j >= 0 && l1 - j >= 0 && s[ll - j] == a[i][l1 - j] &&
               t[ll - j] == b[i][l1 - j])
          ++j;
        l = max(ll - j + 1, l);
        j = 1;
        while (rr + j < s.size() && rr + j < a[i].size() &&
               s[rr + j] == a[i][r1 + j] && t[rr + j] == b[i][rr + j])
          ++j;
        r = min(r, rr + j - 1);
      }
    }
  }
  string s1, t1;
  for (int i = ll; i <= rr; ++i) {
    s1 += s[i];
    t1 += t[i];
  }
  s = s1;
  t = t1;
  for (int i = 0; i < n; ++i) {
    a[i] = rreplace(a[i], s, t);
    if (a[i] != b[i]) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  cout << s << '\n';
  cout << t << '\n';
  return 0;
}
