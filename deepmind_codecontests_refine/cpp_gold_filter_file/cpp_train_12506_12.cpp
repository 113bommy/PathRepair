#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n == 2 and s[0] >= s[1])
      cout << "NO" << endl;
    else {
      cout << "YES" << endl << 2 << endl << s[0] << ' ';
      for (int i = 1; i < n; i++) cout << s[i];
      cout << endl;
    }
  }
}
