#include <bits/stdc++.h>
using namespace std;
string a;
bool is[200];
int main() {
  is['a'] = is['u'] = is['o'] = is['e'] = is['i'] = 1;
  cin >> a;
  int ans = 0;
  for (int i = 0; i < a.size(); i++) {
    if (is[a[i]] || ((a[i] >= '0' && a[i] <= '9' && (a[i] - '0') % 2 == 1)))
      ans++;
  }
  cout << ans << "\n";
  return 0;
}
