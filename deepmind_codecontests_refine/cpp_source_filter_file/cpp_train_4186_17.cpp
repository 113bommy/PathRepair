#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long n, i, j, max_dis = 0, k = 0;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == '1' || s[s.size() - 1] == '1')
      cout << 2 * s.size();
    else {
      for (i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
          max_dis = max(max(i + 1, n - i - 1), max_dis);
          k = 1;
        }
      }
      if (k == 1)
        cout << 2 * max_dis;
      else
        cout << n;
    }
    cout << endl;
  }
}
