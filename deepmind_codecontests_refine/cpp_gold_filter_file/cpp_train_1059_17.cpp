#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    string s;
    int k;
    cin >> k;
    int i = 1, j = 1;
    bool flag = false;
    while (j) {
      string a = to_string(j);
      s.append(a);
      int l = s.length();
      if (k <= l) {
        cout << s[k - 1] << endl;
        flag = true;
        break;
      } else
        k -= l;
      j++;
    }
  }
}
