#include <bits/stdc++.h>
using namespace std;
const double eps = 0.000000001;
const int MOD = 1000000009;
const int N = 100005;
int main() {
  string s;
  cin >> s;
  bool f = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0' && !f) {
      f = true;
      continue;
    }
    if (s.size() == i - 1 && !f) continue;
    cout << s[i];
  }
  cout << endl;
  return 0;
}
