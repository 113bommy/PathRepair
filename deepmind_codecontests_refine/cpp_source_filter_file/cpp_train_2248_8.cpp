#include <bits/stdc++.h>
using namespace std;
vector<string> v;
string s;
int k;
void doit() {
  string cur = "";
  int i;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == ' ' || s[i] == '-') {
      cur += s[i];
      v.push_back(cur);
      cur = "";
    } else
      cur += s[i];
  }
  if (cur != "") v.push_back(cur);
}
bool can(int x) {
  int cur = 0, nol = 1;
  int i;
  for (i = 0; i < v.size(); i++)
    if (x < v[i].size()) return 0;
  for (i = 0; i < v.size(); i++) {
    if (cur + v[i].size() > x) {
      cur = v[i].size();
      nol++;
    } else
      cur += v[i].size();
  }
  return nol <= k;
}
int main() {
  cin >> k;
  getline(cin, s);
  getline(cin, s);
  doit();
  int st = 1, en = s.size();
  int mid, ans;
  while (st < en) {
    mid = (st + en) / 2;
    if (can(mid)) {
      ans = mid;
      en = mid;
    } else
      st = mid + 1;
  }
  cout << ans << endl;
}
