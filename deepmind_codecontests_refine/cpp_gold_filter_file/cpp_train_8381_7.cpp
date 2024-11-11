#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  s = '0' + s;
  long long cnt = 0;
  for (int i = 1; i < s.length(); i++) {
    if ((s[i] - '0') % 4 == 0) {
      cnt++;
    }
    if (i != 1) {
      int num = (s[i - 1] - '0') * 10 + s[i] - '0';
      if (num % 4 == 0) {
        cnt += i - 1;
      }
    }
  }
  cout << cnt << "\n";
  return 0;
}
