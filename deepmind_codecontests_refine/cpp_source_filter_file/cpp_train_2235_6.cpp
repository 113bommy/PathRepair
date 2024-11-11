#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b;
  cin >> a >> b;
  int sys = 2;
  for (int i = 0; i < (int)a.length(); ++i) {
    if (a[i] - '0' >= sys) {
      sys = a[i] - '0' + 1;
    }
  }
  for (int i = 0; i < (int)b.length(); ++i) {
    if (b[i] - '0' >= sys) {
      sys = b[i] - '0' + 1;
    }
  }
  string ar = a, br = b;
  for (int i = 0; i < (int)a.length(); ++i) {
    ar[i] = a[a.length() - i - 1];
  }
  for (int i = 0; i < (int)b.length(); ++i) {
    br[i] = b[b.length() - i - 1];
  }
  string res = "";
  int ram = 0;
  for (int i = 0; (i < ar.length()) || (i < br.length()); ++i) {
    if (i < ar.length()) {
      if (i < br.length()) {
        if (ar[i] - '0' + br[i] - '0' + ram >= sys) {
          res += (ar[i] - '0' + br[i] - '0' + ram) % sys + '0';
          ram = 1;
        } else {
          res += ar[i] - '0' + br[i] + ram;
          ram = 0;
        }
      } else {
        if (ar[i] - '0' + ram >= sys) {
          res += (ar[i] - '0' + ram) % sys + '0';
          ram = 1;
        } else {
          res += ar[i] + ram;
          ram = 0;
        }
      }
    } else {
      if (br[i] - '0' + ram >= sys) {
        res += (br[i] - '0' + ram) % sys + '0';
        ram = 1;
      } else {
        res += br[i] + ram;
        ram = 0;
      }
    }
  }
  if (ram = 1) {
    res += '1';
  }
  cout << res.length();
  return 0;
}
