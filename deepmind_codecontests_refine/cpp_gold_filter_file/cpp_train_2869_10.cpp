#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int i, j, n;
  string s;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> s;
    if (s.size() <= 10) {
      cout << s << endl;
    } else {
      cout << s[0] << s.size() - 2 << s[s.size() - 1] << endl;
    }
  }
  return 0;
}
