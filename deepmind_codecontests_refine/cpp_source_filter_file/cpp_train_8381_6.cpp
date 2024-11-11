#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  long long int ans = 0;
  int n = s.length();
  if ((s[0] - '0') % 4 == 0) ans = 1;
  for (int i = 1; i < n; i++) {
    if ((((s[i - 1] - '0') * 10) + (s[i] - '0')) % 4 == 0) ans += i;
    if ((s[i] - '0') % 4 == 0) ans++;
  }
  printf("%d", ans);
  return 0;
}
