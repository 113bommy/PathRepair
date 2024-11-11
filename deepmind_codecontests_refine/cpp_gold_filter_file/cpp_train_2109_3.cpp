#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    char c[100005];
    int n;
    cin >> n;
    string s0 = "";
    string sm = "";
    string s1 = "";
    bool flag0 = true;
    int pos1 = -1;
    int pos0 = -1;
    for (int i = 1; i <= n; i++) {
      cin >> c[i];
      if (c[i] == '1') {
        if (flag0) flag0 = false;
        if (pos1 == -1) pos1 = i;
        s1 = s1 + '1';
      } else {
        if (flag0) s0 = s0 + '0';
        s1 = "";
        pos0 = i;
      }
    }
    if (pos1 != -1 && pos0 != -1 && pos0 > pos1) sm = "0";
    string s = s0 + sm + s1;
    cout << s << endl;
  }
}
