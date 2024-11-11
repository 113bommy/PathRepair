#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, res = "";
  int carry = 0;
  int base;
  cin >> a >> b;
  base = max(*max_element(a.begin(), a.end()) - '0' + 1,
             *max_element(b.begin(), b.end()) - '0' + 1);
  if (a.size() > b.size()) swap(a, b);
  while (a.size() != b.size()) {
    a.insert(0, "0");
  }
  for (int i = a.size() - 1; i >= 0; i--) {
    res += (((a[i] - '0' + b[i] - '0') + carry) % base) + '0';
    if ((a[i] - '0' + b[i] - '0') >= base) {
      carry = 1;
    } else
      carry = 0;
  }
  if (carry != 0) res += carry + '0';
  reverse(res.begin(), res.end());
  cout << res.size() << endl;
}
