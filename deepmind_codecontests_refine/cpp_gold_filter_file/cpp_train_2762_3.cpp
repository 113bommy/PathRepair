#include <bits/stdc++.h>
using namespace std;
int n;
string a, b;
int beta(string b) {
  int b_l = b.length(), s = 0;
  for (int i = 0; i < b_l; i++) s = s * 10 + (int)(b[i] - '0');
  return s;
}
int alpha(string a) {
  if (a.length() == 1) {
    if (a[0] == '9') return 1989;
    return 1990 + (int)(a[0] - '0');
  }
  if (a.length() == 2) {
    if (a == "99") return 1999;
    return 2000 + beta(a);
  }
  if (a.length() == 3) {
    if (a == "099") return 2099;
    if (a[0] == '0') return 3000 + beta(a);
    return 2000 + beta(a);
  }
  if (a.length() == 4) {
    if (a < "3099") return 10000 + beta(a);
    return beta(a);
  }
  if (a.length() == 5) {
    if (a < "13099") return 100000 + beta(a);
    return beta(a);
  }
  if (a.length() == 6) {
    if (a < "113099") return 1000000 + beta(a);
    return beta(a);
  }
  if (a.length() == 7) {
    if (a < "1113099") return 10000000 + beta(a);
    return beta(a);
  }
  if (a.length() == 8) {
    if (a < "11113099") return 100000000 + beta(a);
    return beta(a);
  }
  if (a.length() == 9) {
    if (a < "111113099") return 1000000000 + beta(a);
    return beta(a);
  }
  if (a.length() == 10) {
    if (a < "1111113099") return 10000000000 + beta(a);
    return beta(a);
  }
}
int main() {
  int n;
  string s = "";
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    s = s.substr(4, s.length() - 4);
    cout << alpha(s) << "\n";
  }
}
