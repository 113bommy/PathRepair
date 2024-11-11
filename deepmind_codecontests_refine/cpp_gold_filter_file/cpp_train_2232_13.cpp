#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[5];
  long long ans = 0;
  string s;
  cin >> a[1] >> a[2] >> a[3] >> a[4] >> s;
  for (int i = 0; i < s.size(); i++) ans += a[s[i] - '0'];
  cout << ans << endl;
  return 0;
}
