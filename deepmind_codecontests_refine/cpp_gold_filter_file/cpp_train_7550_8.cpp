#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  cin >> n;
  string s;
  cin >> s;
  int has[26] = {0};
  for (int i = 0; i < n; ++i) has[s[i] - 97]++;
  int cnt0 = 0;
  for (int i = 0; i < 26; ++i) {
    if (has[i] > 1) {
      ans += has[i] - 1;
    } else if (has[i] == 0)
      ++cnt0;
  }
  if (cnt0 >= ans)
    cout << ans << endl;
  else
    cout << -1 << endl;
}
