#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, a[2] = {0}, b[2] = {0};
  string in;
  bool fail = false;
  cin >> i >> in;
  for (i = 0; i < in.length(); i++) {
    if (in[i] == '4')
      a[i < in.length() / 2]++;
    else if (in[i] == '7')
      b[i < in.length() / 2]++;
    else {
      fail = true;
      break;
    }
  }
  if (fail || a[0] != a[1] || b[0] != b[1])
    cout << "NO\n";
  else
    cout << "YES\n";
  return 0;
}
