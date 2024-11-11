#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  for (int i = 0; i < n - 2; i++) {
    if (s[i] == 'x' && s[i + 1] == 'x') {
      int j = i + 2;
      while (j < n && s[j] == 'x') {
        ans++;
        j++;
      }
      i = j;
    }
  }
  cout << ans << '\n';
  return 0;
}
