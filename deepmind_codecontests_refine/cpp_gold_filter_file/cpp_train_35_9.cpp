#include <bits/stdc++.h>
using namespace std;
inline int to_int(string s) {
  int x = 0;
  for (int i = 0; i < (int)s.size(); ++i) x *= 10, x += s[i] - '0';
  return x;
}
char s[100005];
map<string, int> mp;
string tmp, mx;
int d, mn, y, mxx = -1, n,
              m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(int argc, char **argv) {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n - 9; ++i) {
    if (isdigit(s[i]) && isdigit(s[i + 1]) && s[i + 2] == '-' &&
        isdigit(s[i + 3]) && isdigit(s[i + 4]) && s[i + 5] == '-' &&
        isdigit(s[i + 6]) && isdigit(s[i + 7]) && isdigit(s[i + 8]) &&
        isdigit(s[i + 9])) {
      tmp = "";
      for (int j = i; j < i + 10; ++j) tmp += s[j];
      d = (s[i] - '0') * 10 + (s[i + 1] - '0');
      mn = (s[i + 3] - '0') * 10 + (s[i + 4] - '0');
      y = (s[i + 6] - '0') * 1000 + (s[i + 7] - '0') * 100 +
          (s[i + 8] - '0') * 10 + (s[i + 9] - '0');
      if (y >= 2013 && y <= 2015 && mn >= 1 && mn <= 12 && d <= m[mn] &&
          d >= 1) {
        ++mp[tmp];
        if (mp[tmp] > mxx) {
          mxx = mp[tmp];
          mx = tmp;
        }
      }
    }
  }
  printf("%s", mx.c_str());
  return 0;
}
