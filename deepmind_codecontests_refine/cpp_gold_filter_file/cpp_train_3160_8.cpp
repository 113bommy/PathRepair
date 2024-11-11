#include <bits/stdc++.h>
using namespace std;
bool stf(const vector<string>& a, const vector<string>& b) {
  if (a.size() != b.size()) return false;
  for (int i = 0; i != a.size(); ++i) {
    if (a[i] != b[i]) {
      if (a[i] != "T") return false;
    }
  }
  return true;
}
int main(void) {
  int n, m, k;
  string str, f, a;
  cin >> n;
  map<string, vector<vector<string> > > v;
  vector<string> q;
  cin.get();
  for (int i = 0; i != n; ++i) {
    cin >> str;
    getline(cin, str);
    f.clear();
    for (int j = 0; j != str.size(); ++j) {
      if (str[j] != ' ' && str[j] != '(') f += str[j];
      if (str[j] == '(') {
        str = str.substr(j);
        break;
      }
    }
    q.clear();
    for (int j = 0; j != str.size(); ++j) {
      if (isalnum(str[j])) {
        a += str[j];
      } else {
        if (!a.empty()) q.push_back(a);
        a.clear();
      }
    }
    v[f].push_back(q);
  }
  cin >> m;
  cin.get();
  string x, y;
  map<string, string> p;
  for (int i = 0; i != m; ++i) {
    cin >> x >> y;
    p[y] = x;
  }
  cin >> k;
  cin.get();
  vector<vector<string> > ja;
  for (int i = 0; i != k; ++i) {
    getline(cin, str);
    f.clear();
    for (int j = 0; j != str.size(); ++j) {
      if (str[j] != ' ' && str[j] != '(') f += str[j];
      if (str[j] == '(') {
        str = str.substr(j);
        break;
      }
    }
    q.clear();
    for (int j = 0; j != str.size(); ++j) {
      if (isalnum(str[j])) {
        a += str[j];
      } else {
        if (!a.empty()) q.push_back(p[a]);
        a.clear();
      }
    }
    ja = v[f];
    int re = 0;
    for (int j = 0; j != ja.size(); ++j) {
      if (stf(ja[j], q)) ++re;
    }
    cout << re << endl;
  }
  return 0;
}
