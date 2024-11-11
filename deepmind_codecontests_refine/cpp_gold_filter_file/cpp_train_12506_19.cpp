#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n < 2 || (n < 3 && s[0] >= s[1]))
      cout << "NO" << endl;
    else {
      cout << "YES" << endl << '2' << endl;
      cout << s[0] << ' ';
      for (int i = 1; i < n; i++) cout << s[i];
      cout << endl;
    }
  }
}
