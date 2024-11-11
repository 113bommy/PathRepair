#include <bits/stdc++.h>
using namespace std;
string str;
long long int x, n, a, i, ans;
int main() {
  ans = 0;
  x = (1 << 25) - 1;
  cin >> n;
  getline(cin, str);
  for (i = 0; i < (n - 1); ++i) {
    getline(cin, str);
    if (str[0] == '!') {
      long long int y = 0;
      for (long long int j = 2; j < str.length(); j++) {
        a = str[j] - 'a';
        y = y | (1 << a);
      }
      x = x & y;
    } else if (str[0] == '?' || str[0] == '.') {
      for (long long int j = 2; j < str.length(); j++) {
        a = str[j] - 'a';
        x = x & (~(1 << a));
      }
    }
    if (x && (x & (x - 1)) == 0) {
      break;
    }
  }
  i++;
  while (i < (n - 1)) {
    getline(cin, str);
    if (str[0] == '?' || str[0] == '!') ans++;
    i++;
  }
  getline(cin, str);
  cout << ans << "\n";
  return 0;
}
