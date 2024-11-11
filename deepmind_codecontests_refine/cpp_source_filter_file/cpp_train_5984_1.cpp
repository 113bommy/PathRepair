#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long ans = 0;
  int a[256 + 1] = {};
  for (int i = 0; i <= s.size() - 1; i += 1) a[s[i]]++;
  for (int i = 0; i <= 256; i += 1) ans += a[i] * a[i];
  cout << ans;
}
