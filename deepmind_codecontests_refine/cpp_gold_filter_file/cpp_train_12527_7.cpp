#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
string second;
vector<string> ans;
bool ok(string &second) {
  if (second.empty()) return false;
  for (int i = 0; i < (int)second.size(); i++) {
    if (second[i] < 'a' || second[i] > 'z') return false;
  }
  return true;
}
int main() {
  cin >> second;
  vector<string> v;
  string cur = "";
  for (int i = 0; i < (int)second.size(); i++) {
    if (second[i] == '.') {
      v.push_back(cur);
      cur = "";
    } else
      cur += second[i];
  }
  v.push_back(cur);
  for (__typeof(v.begin()) it = v.begin(); it != v.end(); it++) {
    if (!ok(*it) || (int)v.size() == 1 || (int)v[0].size() > 8 ||
        (int)v.back().size() > 3 || (*it).size() > 11) {
      cout << "NO\n";
      return 0;
    }
  }
  if (v.size() == 2) {
    if ((int)v[0].size() <= 8 && (int)v[1].size() <= 3) {
      cout << "YES\n" << second << endl;
    } else
      cout << "NO" << endl;
    return 0;
  }
  ans.push_back(v[0] + ".");
  for (int i = 1; i < (int)v.size() - 1; i++) {
    int len = (int)v[i].size();
    if (len == 1) {
      cout << "NO" << endl;
      return 0;
    }
    int sz = min(len - 1, 3);
    ans.back() += v[i].substr(0, sz);
    ans.push_back(v[i].substr(sz) + ".");
  }
  ans.back() += v.back();
  cout << "YES" << endl;
  for (__typeof(ans.begin()) it = ans.begin(); it != ans.end(); it++)
    cout << *it << endl;
  return 0;
}
