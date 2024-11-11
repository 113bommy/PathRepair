#include <bits/stdc++.h>
using namespace std;
string f[10] = {"", "0", "00", "000", "01", "1", "10", "100", "1000", "02"};
int dd[333];
int ddr[333];
string roma = "IVXLCDM";
int base;
int toI(string s) {
  int ans = 0;
  for (auto x : s) {
    ans = ans * base + dd[x];
  }
  return ans;
}
string toR(int x) {
  string ans;
  for (int i = (int)roma.size() - 1, p = 1000; i >= 0; i -= 2, p /= 10) {
    int d = (x / p) % 10;
    for (auto x : f[d]) {
      ans.push_back(roma[i + x - '0']);
    }
  }
  return ans;
}
int main(void) {
  for (int i = 0; i < 10; i++) {
    dd[i + '0'] = i;
    ddr[i] = i + '0';
  }
  for (int i = 'A'; i <= 'Z'; i++) {
    dd[i] = i - 'A' + 10;
    ddr[i - 'A' + 10] = i;
  }
  string a, b, c;
  cin >> a >> b >> c;
  base = atoi(a.c_str());
  if (b == "R") {
    cout << toR(toI(c)) << endl;
  } else {
    int aa = atoi(a.c_str());
    for (int i = 0; i < c.size(); i++) {
      c[i] = dd[c[i]];
    }
    int f = 1;
    string ans;
    while (f) {
      f = 0;
      int p = 0;
      for (int i = 0; i < c.size(); i++) {
        if (c[i]) {
          f = 1;
        }
        p = (p * base + c[i]);
        c[i] = p / aa;
        p %= aa;
      }
      if (f) ans.push_back(ddr[p]);
    }
    if (ans.size() == 0) ans = "0";
    reverse((ans).begin(), (ans).end());
    cout << ans << endl;
  }
  return 0;
}
