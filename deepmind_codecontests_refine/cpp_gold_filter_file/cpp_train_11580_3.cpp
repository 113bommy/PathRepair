#include <bits/stdc++.h>
using namespace std;
const long long N = 1e4 + 5, inf = 1e9 + 6, mod = 1e9 + 7;
int d[N][2];
int ask(string s) {
  cout << s << endl;
  int res;
  cin >> res;
  if (res == 0) exit(0);
  return res;
}
int main() {
  string str;
  for (int i = 0; i < 300; i++) str += "a";
  int qa = ask(str);
  str = "";
  for (int i = 0; i < 300; i++) str += "b";
  int qb = ask(str);
  int n = 300 - qa + 300 - qb;
  str = "";
  for (int i = 0; i < n; i++) str += "a";
  int pre = 300 - qb;
  for (int i = 0; i < n - 1; i++) {
    str[i] = 'b';
    int cur = ask(str);
    if (pre > cur) {
      pre--;
    } else {
      str[i] = 'a';
    }
  }
  if (pre) str.back() = 'b';
  ask(str);
}
