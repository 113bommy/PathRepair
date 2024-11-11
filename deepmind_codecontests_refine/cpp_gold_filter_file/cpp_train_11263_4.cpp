#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (i == 0 && s[i] != '1' && n > 1 && k != 0) {
      s[i] = '1';
      k--;
    } else if (i != 0 && s[i] != '0' && k != 0) {
      s[i] = '0';
      k--;
    } else if (i == 0 && s[i] != '0' && n == 1 && k != 0) {
      s[i] = '0';
      k--;
    }
  }
  cout << s;
  return 0;
}
