#include <bits/stdc++.h>
using namespace std;
void prepare() {}
void solve() {
  int n;
  cin >> n;
  int osn = 2341;
  vector<string> ss(n);
  for (int i = 0; i < (n); ++i) cin >> ss[i];
  string s;
  cin >> s;
  char ch;
  cin >> ch;
  char CH = ch - 'a' + 'A';
  set<pair<int, unsigned long long> > sp;
  vector<int> used((int)(s).size(), 0);
  for (int i = 0; i < n; ++i) {
    unsigned long long h = 0;
    for (int j = 0; j < (int)(ss[i]).size(); ++j) {
      int t = ss[i][j];
      if (isupper(ss[i][j]))
        t -= 'A';
      else
        t -= 'a';
      h = h * osn + t;
    }
    sp.insert(make_pair((int)(ss[i]).size(), h));
  }
  for (int i = 0; i < (int)(s).size(); ++i) {
    string t(s.begin() + i, s.end());
    for (auto it = sp.begin(); it != sp.end(); ++it) {
      if ((int)(t).size() < (*it).first) continue;
      string tt(t.begin(), t.begin() + (*it).first);
      unsigned long long h = 0;
      for (int j = 0; j < (int)(tt).size(); ++j) {
        int t = tt[j];
        if (isupper(t))
          t -= 'A';
        else
          t -= 'a';
        h = h * osn + t;
      }
      if ((*it).second == h)
        for (int j = i; j < i + (*it).first; ++j) used[j] = 1;
    }
  }
  for (int i = 0; i < (int)(s).size(); ++i) {
    if (used[i])
      if (isupper(s[i])) {
        if (s[i] == CH) {
          if (CH == 'A')
            s[i] = 'B';
          else
            s[i] = 'A';
        } else
          s[i] = CH;
      } else {
        if (s[i] == ch) {
          if (ch == 'a')
            s[i] = 'b';
          else
            s[i] = 'a';
        } else
          s[i] = ch;
      }
  }
  cout << s << endl;
}
int main() {
  prepare();
  solve();
  return 0;
}
