#include <bits/stdc++.h>
using namespace std;
string s;
map<string, int> m;
vector<pair<int, int> > v;
int g(string x) {
  int len = x.length();
  string cur = "";
  cur = cur + x[len - 2];
  cur = cur + x[len - 1];
  if (cur == "la" or cur == "ra" or cur == "es") return 0;
  return 1;
}
int t(string x) {
  int len = x.length();
  string cur = "";
  cur = cur + x[len - 2];
  cur = cur + x[len - 1];
  if (cur == "os" or cur == "la") return 0;
  if (cur == "tr" or cur == "ra") return 1;
  return 2;
}
int check(string x) {
  int len = x.length();
  if (len < 3) return 1;
  string cur = "";
  if (len >= 3) {
    cur = x[len - 1] + cur;
    cur = x[len - 2] + cur;
    cur = x[len - 3] + cur;
    if (cur == "etr") return 0;
    if (len > 3) {
      cur = x[len - 4] + cur;
      if (cur == "lios" or cur == "etra") return 0;
    }
    if (len > 4) {
      cur = x[len - 5] + cur;
      if (cur == "liala") return 0;
    }
    if (len > 5) {
      cur = x[len - 6] + cur;
      if (cur == "inites" or cur == "initis") return 0;
    }
    return 1;
  }
}
int main() {
  int inv = 0;
  while (cin >> s) {
    inv |= check(s);
    if (inv) break;
    v.push_back(make_pair(t(s), g(s)));
  }
  if (inv) {
    cout << "NO";
    return 0;
  }
  if (v.size() == 1 and
      (v[0].first == 1 or v[0].first == 2 or v[0].first == 0)) {
    cout << "YES";
    return 0;
  }
  int fl = 0;
  int fl_sorted = 0;
  vector<int> z;
  set<int> ss;
  for (int i = 0; i < v.size(); i++) {
    if (v[i].first == 1) fl++;
    z.push_back(v[i].first);
    ss.insert(v[i].second);
  }
  vector<int> y = z;
  sort(y.begin(), y.end());
  int sz = ss.size();
  if (fl == 1 and sz == 1 and (y == z)) {
    cout << "YES";
    return 0;
  }
  cout << "NO";
}
