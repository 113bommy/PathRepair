#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  t = 1;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pos = n - 1;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] > s[i + 1]) {
        pos = i;
        break;
      }
    }
    cout << s.substr(0, pos) + s.substr(pos + 1) << endl;
  }
  return 0;
}
