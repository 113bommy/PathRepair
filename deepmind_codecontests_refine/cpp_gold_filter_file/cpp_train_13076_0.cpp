#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  vector<int> st(7);
  int ans = 0;
  while (n--) {
    cin >> s;
    for (int i = 0; i < 7; i++) {
      if (s[i] != '0') st[i]++;
    }
  }
  for (int i = 0; i < 7; i++) {
    ans = max(st[i], ans);
  }
  cout << ans << endl;
}
