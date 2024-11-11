#include <bits/stdc++.h>
using namespace std;
const int OO = (int)1e8;
const double EPS = 1e-11;
string f(string a) {
  string res = "";
  int c = 1;
  for (int i = (int)a.size() - 1; i >= 0; --i) {
    int d = a[i] - '0';
    d += c;
    if (d > 10)
      res += ('0' + (d % 10)), c = d / 10;
    else
      res += ('0' + d);
  }
  reverse(res.begin(), res.end());
  return res;
}
int main() {
  string s;
  cin >> s;
  int idx = s.find(".");
  string a;
  for (int i = 0; i < idx; ++i) a += s[i];
  s = s.substr(idx + 1);
  if (a[(int)a.size() - 1] == '9')
    cout << "GOTO Vasilisa.";
  else {
    if (s[0] >= '5') {
      cout << f(a);
    } else
      cout << a << endl;
  }
  return 0;
}
