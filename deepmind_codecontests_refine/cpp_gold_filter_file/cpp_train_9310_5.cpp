#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
int main() {
  string s;
  cin >> s;
  vector<string> v;
  v.push_back("");
  for (int i = 0; i < s.length(); ++i) {
    v.back() += s[i];
    string t = v.back();
    if (t.length() >= 2 && t.substr(t.length() - 2) == "at")
      v.back() = v.back().substr(0, t.size() - 2), v.push_back("@"),
      v.push_back("");
    if (t.length() >= 3 && t.substr(t.length() - 3) == "dot")
      v.back() = v.back().substr(0, t.size() - 3), v.push_back("."),
      v.push_back("");
  }
  if (v.back() == "") v.pop_back();
  bool hasat = 0;
  int f = 0;
  if (v.front() == "") f++;
  for (int i = 0; i < v.size(); ++i) {
    if (v[i] != "." && v[i] != "@")
      cout << v[i];
    else if (v[i] == ".") {
      if (i != f && i != v.size() - 1)
        cout << v[i];
      else
        cout << "dot";
    } else if (v[i] == "@") {
      if (!hasat && i != f && i != v.size() - 1) {
        hasat = 1;
        cout << "@";
      } else {
        cout << "at";
      }
    }
  }
  return 0;
}
