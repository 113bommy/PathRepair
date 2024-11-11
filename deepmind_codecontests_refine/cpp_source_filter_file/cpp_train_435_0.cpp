#include <bits/stdc++.h>
using namespace std;
const int len = 1e5 + 5;
const int PI = acos(-1.0);
int main() {
  int n;
  string s, t;
  for (cin >> n; n--;) {
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
      int cur = i;
      for (int j = i + 1; j < s.size(); j++) {
        if (s[j] < s[cur]) cur = j;
      }
      if (s[cur] != s[i]) {
        swap(s[cur], s[i]);
        break;
      }
    }
    if (s < t)
      cout << s << endl;
    else
      cout << "---" << endl;
  }
}
