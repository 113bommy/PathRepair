#include <bits/stdc++.h>
using namespace std;
char s[1000010];
int res[500010];
bool f = false;
int cnt = 0;
int main() {
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
          res[cnt++] = i - 1;
          res[cnt++] = -r;
          state = 1;
          break;
        }
        if (s[i] == '1') {
          res[cnt++] = -(i - 1);
          state = 2;
          break;
        }
      case 4:
        if (s[i] == '0') {
          res[cnt++] = r;
          f = f || (r == 0);
          state = 1;
          break;
        }
        if (s[i] == '1') {
          state = 2;
          break;
        }
    }
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++)
    printf("%c2^%d\n", (res[i] > 0 || res[i] == 0 && f ? '+' : '-'),
           abs(res[i]));
exit:
  return (0);
}
