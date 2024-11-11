#include <bits/stdc++.h>
using namespace std;
string i_str(int n) {
  char buff[10];
  sprintf(buff, "%d", n);
  return string(buff);
}
int main() {
  int a, b;
  cin >> a >> b;
  if (a < b) {
    cout << b;
    return 0;
  }
  string sa, sb, t, r = "", si = "";
  sb = i_str(b);
  for (int j = a + 1; j <= 1000000; j++) {
    r = "";
    si = i_str(j);
    int ni = si.length();
    for (int i = 0; i < ni; i++) {
      if (si[i] == '4') r = r + si[i];
      if (si[i] == '7') r = r + si[i];
    };
    if (r == sb) {
      cout << j;
      return 0;
    }
  }
  return 0;
}
