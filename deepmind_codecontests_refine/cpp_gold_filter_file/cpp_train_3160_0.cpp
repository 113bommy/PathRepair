#include <bits/stdc++.h>
using namespace std;
map<string, string> my;
int main() {
  int n;
  cin >> n;
  vector<vector<string> > a(n);
  for (int i = 0; i < n; i++) {
    string s, buf = "";
    cin >> s;
    getline(cin, s);
    for (int j = 0; j < s.length(); j++) {
      if (isalpha(s[j]) || isdigit(s[j])) buf += s[j];
      if (!(isalpha(s[j]) || isdigit(s[j])) && buf != "")
        a[i].push_back(buf), buf = "";
    }
  }
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s1, s2;
    cin >> s1 >> s2;
    my[s2] = s1;
  }
  cin >> n;
  string f;
  getline(cin, f);
  vector<string> b;
  for (int i = 0; i < n; i++) {
    string s, buf;
    getline(cin, s);
    for (int j = 0; j < s.length(); j++) {
      if (isalpha(s[j]) || isdigit(s[j])) buf += s[j];
      if (!(isalpha(s[j]) || isdigit(s[j])) && buf != "")
        b.push_back(buf), buf = "";
    }
    int cc = 0;
    for (int k = 0; k < a.size(); k++) {
      int c = 0;
      if (a[k].size() != b.size()) continue;
      for (int j = 1; j < b.size(); j++) {
        if (b[0] == a[k][0] && (a[k][j] == "T" || a[k][j] == my[b[j]])) {
          c++;
        }
      }
      if (c == a[k].size() - 1) cc++;
    }
    cout << cc << endl;
    b.clear();
  }
  return 0;
}
