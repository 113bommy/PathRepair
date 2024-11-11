#include <bits/stdc++.h>
using namespace std;
string n;
int main() {
  cin >> n;
  int len = n.length();
  bool f00 = 0, f01 = 0, f10 = 0, f11 = 0;
  int n0 = 0, n1 = 0, nq = 0;
  for (int i = 0; i < len; i++) {
    n0 += (n[i] == '0');
    n1 += (n[i] == '1');
    nq += (n[i] == '?');
  }
  if (n1 < (n0 + nq)) f00 = true;
  if (n0 + 1 < (n1 + nq)) f11 = true;
  for (int i = 0; i <= nq; i++) {
    if ((len % 2 == 0 && n0 + i == n1 + (nq - i)) ||
        (len % 2 == 1 && n0 + i + 1 == n1 + (nq - i))) {
      if (n[len - 1] == '0')
        f10 = true;
      else if (n[len - 1] == '1')
        f01 = true;
      else if (n[len - 2] == '0' && i >= 1 & nq - i >= 1)
        f01 = f10 = true;
      else if (n[len - 2] == '0' && nq - i >= 1)
        f01 = true;
      else if (n[len - 2] == '0')
        f10 = true;
      else if (n[len - 2] == '1' && i >= 1 && nq - i >= 1)
        f10 = f01 = true;
      else if (n[len - 2] == '1' && i >= 1)
        f10 = true;
      else if (n[len - 2] == '1')
        f01 = true;
      else if (n[len - 2] == '?' && n[len - 1] == '?' && i >= 1 && nq - i >= 1)
        f01 = f10 = true;
      else if (n[len - 2] == '?' && n[len - 1] == '?' && i >= 1)
        f00 = true;
      else if (n[len - 2] == '?' && n[len - 1] == '?' && nq - i >= 1)
        f11 = true;
      break;
    }
  }
  if (f00) cout << "00" << endl;
  if (f01) cout << "01" << endl;
  if (f10) cout << "10" << endl;
  if (f11) cout << "11" << endl;
  return 0;
}
