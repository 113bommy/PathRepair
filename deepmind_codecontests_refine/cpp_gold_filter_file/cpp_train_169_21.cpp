#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  string ans;
  cin >> s;
  map<string, int> m;
  int maz = 0;
  for (int i = 0; i < n - 1; i++) {
    string t = s.substr(i, 2);
    m[t]++;
    if (m[t] > maz) {
      maz = m[t];
      ans = t;
    }
  }
  cout << ans;
  return 0;
}
