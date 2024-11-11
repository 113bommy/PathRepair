#include <bits/stdc++.h>
using namespace std;
char s[2][2000005], len;
int m[2000005][2];
int main() {
  scanf("%s", s[0]);
  strcpy(s[1], s[0]);
  len = strlen(s[0]);
  int firstone = len - 1;
  while (1) {
    if (s[0][firstone] == '1')
      break;
    else
      firstone--;
  }
  for (int i = 0, _e(firstone); i < _e; i++)
    s[1][i] = s[0][i] == '1' ? '0' : '1';
  len++;
  for (int i(len - 1), _e(1); i >= _e; i--)
    s[0][i] = s[0][i - 1], s[1][i] = s[1][i - 1];
  s[0][0] = s[1][0] = '0';
  m[len][0] = m[len][1] = 0;
  for (int p(len - 1), _e(0); p >= _e; p--)
    for (int bit = 0, _e(2); bit < _e; bit++) {
      if (s[bit][p] == '1') {
        m[p][bit] = 1 + m[p + 1][bit];
      } else {
        m[p][bit] = m[p + 1][bit];
        m[p][bit] = min(m[p][bit], 1 + m[p + 1][1 - bit]);
      }
    }
  int ans = m[0][0];
  cout << ans << endl;
  int p = 0, bit = 0;
  while (p < len) {
    if (s[bit][p] == '1') {
      if (!bit)
        printf("+");
      else
        printf("-");
      printf("2^%d\n", len - p - 1);
      ++p;
    } else {
      if (m[p][bit] == m[p + 1][bit])
        ++p;
      else {
        if (!bit)
          printf("+");
        else
          printf("-");
        printf("2^%d\n", len - p - 1);
        ++p, bit = 1 - bit;
      }
    }
  }
  return 0;
}
