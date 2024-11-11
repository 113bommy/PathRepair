#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> n >> s;
  sort(s.begin(), s.end());
  int v = 0;
  for (int i = 0; i < s.size(); ++i) v += s[i] - '0';
  int ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    if (v >= n) break;
    v += '9' - s[i];
    ++ans;
  }
  cout << ans << endl;
  return 0;
}
