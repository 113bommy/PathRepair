#include <bits/stdc++.h>
using namespace std;
int n;
int k;
vector<string> vs;
vector<string> upg() {
  vector<string> res0 = vs;
  for (string& s : res0) {
    string sc = s;
    reverse(sc.begin(), sc.end());
    s += sc;
  }
  vector<string> res1 = res0;
  for (string& s : res1) {
    for (int i = vs.size(); i < s.size(); i++) {
      if (s[i] == '+')
        s[i] = '-';
      else
        s[i] = '+';
    }
  }
  for (string s : res1) res0.push_back(s);
  return move(res0);
}
int main() {
  cin >> k;
  vs.push_back("+");
  for (int i = 1; i <= k; i++) vs = upg();
  for (string& s : vs) cout << s << "\n";
}
