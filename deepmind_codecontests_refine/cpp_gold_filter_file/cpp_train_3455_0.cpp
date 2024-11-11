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
  for (int i = 0; i < s.length(); i++) {
    if (s[i] > '0' && k > 0 && (i != 0 || s.length() == 1)) {
      k--;
      s[i] = '0';
    } else if (s[i] > '1' && k > 0 && i == 0) {
      k--;
      s[i] = '1';
    }
  }
  cout << s << endl;
  return 0;
}
