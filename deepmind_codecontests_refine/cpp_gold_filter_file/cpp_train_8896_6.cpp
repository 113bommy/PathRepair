#include <bits/stdc++.h>
using namespace std;
int n, ans;
string s;
int main() {
  cin >> n >> s;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      s[i + 1] ^= 1;
      ans++;
    }
  }
  cout << min(ans, n - ans);
  return 0;
}
