#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, p, k;
  cin >> n >> p >> k;
  string s = "";
  s += "(" + to_string(p) + ")";
  int i = 1;
  if (p > 1) {
    while (p - i >= 1 && i <= k) {
      s = to_string(p - i) + " " + s;
      i++;
    }
    if (p - i > 1) s = "<< " + s;
  }
  if (p < n) {
    i = 1;
    while (p + i <= n && i <= k) {
      s = s + " " + to_string(p + i);
      i++;
    }
    if (p + i < n) s += " >>";
  }
  cout << s << endl;
  return 0;
}
