#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  long long ans = 0;
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    if (!(s[i] - '0')) ans += i + 1;
  }
  cout << ans << endl;
  return 0;
}
