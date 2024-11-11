#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ind = -1;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '0') {
        ind = i;
        break;
      }
    }
    if (ind == -1) {
      cout << 1 << " " << s.size() - 1 << " " << 2 << " " << s.size() << endl;
    } else {
      if (ind <= s.size() / 2) {
        cout << ind + 1 << " " << s.size() << " " << ind + 2 << " " << s.size()
             << endl;
      } else {
        cout << 1 << " " << ind + 1 << " " << 1 << " " << ind << endl;
      }
    }
  }
  return 0;
}
