#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
using LD = long double;
vector<string> rasp = {"x^y^z",   "x^z^y", "(x^y)^z", "y^x^z",  "y^z^x",
                       "(y^x)^z", "z^x^y", "z^y^x",   "(z^x)^y"};
LD answer = -2, x, y, z;
string str;
void ch(LD &ret1, LD &toCh, string C) {
  if (ret1 - toCh > 0.0001) toCh = ret1, str = C;
}
void solve(LD x, LD y, LD z, int code) {
  vector<LD> arr = {log(x) * pow(y, z), log(x) * pow(z, y), log(x) * y * z};
  for (auto &cur : arr) ch(cur, answer, rasp[code + (&cur - &arr[0])]);
}
int main() {
  cin >> x >> y >> z;
  solve(x, y, z, 0);
  solve(y, x, z, 3);
  solve(z, x, y, 6);
  cout << str;
}
