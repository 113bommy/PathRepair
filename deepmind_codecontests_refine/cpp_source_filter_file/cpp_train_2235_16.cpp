#include <bits/stdc++.h>
using namespace std;
int main() {
  string x, y;
  cin >> x >> y;
  int r = -1;
  for (int i = 0; i < x.size(); i++)
    if (r < x[i]) r = x[i];
  for (int i = 0; i < y.size(); i++)
    if (r < y[i]) r = y[i];
  r -= '0';
  r++;
  int carry = 0;
  int cal;
  string res = "";
  int i, j;
  for (i = x.size() - 1, j = y.size() - 1; j >= 0 || i >= 0; i--, j--) {
    if (i < 0)
      cal = (y[j] - '0') + carry;
    else if (j < 0)
      cal = (x[i] - '0') + carry;
    else
      cal = (x[i] - '0') + (y[i] - '0') + carry;
    carry = cal / r;
    cal = cal % r;
    res = (char)(cal + '0') + res;
  }
  if (carry != 0) res = (char)(carry + '0') + res;
  cout << res.size() << endl;
  return 0;
}
