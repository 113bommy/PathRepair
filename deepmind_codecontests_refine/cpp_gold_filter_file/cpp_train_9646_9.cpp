#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 10;
string shit[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
string str(int x) {
  if (x == 0) {
    return "0";
  }
  string w;
  while (x) {
    int a = x % 10;
    string c = shit[a];
    w = c + w;
    x /= 10;
  }
  return w;
}
map<string, bool> ok;
set<int> res;
int d = 0;
void f(string s) {
  for (int i = 0; i < s.size(); ++i) {
    string t = s.substr(0, i);
    t = t + s.substr(i + 1, s.size() - i - 1);
    if (ok[t]) {
      res.insert(d + 1);
    }
    if (t[0] != '0') {
      d++;
      f(t);
      d--;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  for (int i = 1; i * i <= 2e9 + 1; ++i) {
    string t = str(i * i);
    ok[t] = 1;
  }
  f(s);
  if (ok[s]) {
    res.insert(0);
  }
  if (res.empty()) {
    cout << -1 << endl;
  } else {
    cout << (*res.begin()) << endl;
  }
  return 0;
}
