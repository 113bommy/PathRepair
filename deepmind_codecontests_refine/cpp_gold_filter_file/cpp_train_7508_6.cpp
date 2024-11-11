#include <bits/stdc++.h>
using namespace std;
string s;
string ret;
string *rev(int x) {
  ret = "";
  for (int i = x; i < s.size(); i++) ret += s[i];
  for (int i = 0; i < x; i++) ret += s[i];
  return &ret;
}
bool paranoid(string &x, int sz) {
  for (int i = 0; i + i <= sz; i++)
    if (x[i] != x[sz - i]) return false;
  return true;
}
int main() {
  iostream::sync_with_stdio(0);
  cin >> s;
  int l = 0, r = s.size();
  int mid = (l + r) / 2;
  for (int i = 1; i < r; i++) {
    string &p = *rev(i);
    if (paranoid(p, s.size() - 1) && s != p) {
      cout << 1;
      exit(0);
    }
  }
  for (int i = 1; i < mid; i++) {
    if (!paranoid(s, i)) {
      cout << 2;
      exit(0);
    }
  }
  cout << "Impossible";
}
