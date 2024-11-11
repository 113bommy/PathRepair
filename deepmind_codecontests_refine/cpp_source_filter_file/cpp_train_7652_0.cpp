#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:20000000")
string problem_name = "a";
void init() { freopen((problem_name + ".in").c_str(), "rt", stdin); }
string r = "IVXLCDM";
string convtor(int a) {
  string res = "";
  int p = 1000;
  int pos = 6;
  while (p) {
    int c = a / p;
    if (c == 4)
      res += string(1, r[pos]) + string(1, r[pos + 1]);
    else if (c == 9)
      res += string(1, r[pos + 2]) + string(1, r[pos]);
    else if (c <= 3)
      for (int i = 0; i < c; i++) res += string(1, r[pos]);
    else {
      res += string(1, r[pos + 1]);
      c -= 5;
      for (int i = 0; i < c; i++) res += string(1, r[pos]);
    }
    a %= p;
    p /= 10;
    pos -= 2;
  }
  return res;
}
int main() {
  long long a;
  string bb;
  cin >> a >> bb;
  long long r = 0;
  if (bb == "R") {
    string c;
    cin >> c;
    for (int i = 0; i < int((c).size()); i++) {
      int v;
      if ('0' <= c[i] && c[i] <= '9')
        v = c[i] - '0';
      else
        v = c[i] - 'A' + 10;
      r = r * a + v;
    }
    cout << convtor(r);
    return 0;
  }
  string c;
  istringstream ss(bb);
  int b;
  ss >> b;
  cin >> c;
  r = 0;
  for (int i = 0; i < int((c).size()); i++) {
    int v;
    if ('0' <= c[i] && c[i] <= '9')
      v = c[i] - '0';
    else
      v = c[i] - 'A' + 10;
    r = r * a + v;
  }
  string res = "";
  if (r == 0) {
    cout << 0;
    return 0;
  }
  while (r) {
    int m = r % b;
    if (m < 10)
      res += '0' + m;
    else
      res += 'A' + m - 10;
    r /= b;
  }
  reverse((res).begin(), (res).end());
  cout << res << endl;
  return 0;
}
