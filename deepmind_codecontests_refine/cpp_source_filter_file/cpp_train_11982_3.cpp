#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int cnt = 0;
  string res = "";
  for (int i = 0; i < a.length(); i++) {
    if (a[i] == '1')
      cnt++;
    else
      res += a[i];
  }
  int pos = -1;
  while (pos + 1 < a.length() && a[pos + 1] == '0') pos++;
  res.insert(pos + 1, string(cnt, '1'));
  cout << res << endl;
}
