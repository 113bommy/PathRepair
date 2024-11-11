#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int ans = 0, cnt = 0;
  for (int i = 0; i < ((int)s.size()); i++) {
    if (s[i] == 'F' && cnt)
      ans = max(cnt, ans + 1);
    else if (s[i] == 'M')
      cnt++;
  }
  cout << ans << endl;
  return 0;
}
