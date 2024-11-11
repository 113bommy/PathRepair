#include <bits/stdc++.h>
using namespace std;
char s[1000010];
vector<int> res;
bool f = false;
inline void doMagic(int r, int l) {
  if (r == l) {
    res.push_back(l);
    f = f || (r == 0);
  } else {
    res.push_back((l + 1));
    res.push_back(-r);
    for (int i = r; i <= l; i++)
      if (s[i] == '0') res.push_back(-i);
  }
}
int main() {
  res.reserve(500010);
  scanf("%s", s);
  int l = strlen(s);
  reverse(s, s + l);
  s[l] = '0';
  s[l + 1] = '0';
  s[l + 2] = 0;
  vector<pair<int, int> > tmp;
  for (int i = 0, state = 1, r; i < l + 2; i++) switch (state) {
      case 1:
        if (s[i] == '0') {
          state = 1;
          break;
        }
        if (s[i] == '1') {
          r = i;
          state = 4;
          break;
        }
      case 2:
        if (s[i] == '0') {
          state = 3;
          break;
        }
        if (s[i] == '1') {
          state = 2;
          break;
        }
      case 3:
        if (s[i] == '0') {
          doMagic(r, i - 2);
          state = 1;
          break;
        }
        if (s[i] == '1') {
          state = 2;
          break;
        }
      case 4:
        if (s[i] == '0') {
          doMagic(r, r);
          state = 1;
          break;
        }
        if (s[i] == '1') {
          state = 2;
          break;
        }
    }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++)
    printf("%c2^%d\n", (res[i] > 0 || res[i] == 0 && f ? '+' : '-'),
           abs(res[i]));
exit:
  return (0);
}
