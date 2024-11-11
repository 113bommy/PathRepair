#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  long long cnt_4 = 0, cnt_7 = 0, i;
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    if (s[i] == '4') cnt_4++;
    if (s[i] == '7') cnt_7++;
  }
  if (cnt_4 == 0 && cnt_7 == 0) {
    cout << "-1" << endl;
    return;
  }
  if (cnt_4 < cnt_7) {
    cout << "7" << endl;
  } else {
    cout << "4" << endl;
  }
}
int32_t main() {
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
