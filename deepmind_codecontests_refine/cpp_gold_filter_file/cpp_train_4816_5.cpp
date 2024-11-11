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
    int total = 0;
    int err = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        err++;
      } else {
        err--;
      }
      if (err < 0) {
        total++;
        err = 0;
      }
    }
    cout << total << endl;
  }
}
