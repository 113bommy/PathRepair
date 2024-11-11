#include <bits/stdc++.h>
using namespace std;
int dir_x[] = {1, 0, -1, 0, -1, -1, +1, +1};
int dir_y[] = {0, 1, 0, -1, -1, +1, -1, +1};
int main() {
  long long n, k, pos = -1;
  string str;
  cin >> n >> k >> str;
  long long len = str.size();
  for (long long i = 0; i < len - 1; i++) {
    if (str[i] == '4' && str[i + 1] == '7') {
      if (i > 0 && str[i - 1] == '4' && i % 2 != 0) {
        str[i] = '7';
        k--;
        pos = i;
        break;
      }
      if (i % 2 != 0)
        str[i] = '7';
      else
        str[i + 1] = '4';
      k--;
    }
  }
  if (pos >= 0 && pos < len) {
    if (k % 2 != 0)
      str[pos] = '4';
    else
      str[pos] = '7';
  }
  cout << str << "\n";
  return 0;
}
