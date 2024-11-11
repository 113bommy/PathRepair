#include <bits/stdc++.h>
using namespace std;
string s;
int n, cfirst[100000], csecond[100000], cthird[100000];
long long ans;
int main() {
  cin >> s;
  n = s.length();
  int cur = 0;
  for (int i = 0; i < (int)(n); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      ++cur;
    } else if ((s[i] >= '0' && s[i] <= '9') || (s[i] == '_')) {
    } else
      cur = 0;
    cfirst[i] = cur;
  }
  cur = -1;
  for (int i = 0; i < (int)(n); i++) {
    if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
    } else {
      cur = i;
    }
    csecond[i] = cur;
  }
  cur = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] >= 'a' && s[i] <= 'z')
      ++cur;
    else
      cur = 0;
    cthird[i] = cur;
  }
  int wasat = -1;
  for (int i = 0; i < (int)(n - 1); i++)
    if (s[i] == '@')
      wasat = i;
    else if (s[i] == '.') {
      if (wasat != -1 && csecond[i - 1] == wasat && wasat && i > wasat + 1)
        ans += (long long)cfirst[wasat - 1] * cthird[i + 1];
      wasat = -1;
    }
  cout << ans << endl;
  return 0;
}
