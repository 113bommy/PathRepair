#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
char s[maxn];
int main() {
  cin >> s;
  int i = 0, len = strlen(s), m_num = 0, start, ans = 0;
  while (s[i] == 'M') i++;
  for (; i < len; i++) {
    if (s[i] == 'M')
      m_num++;
    else
      ans = max(ans + 1, m_num);
  }
  printf("%d\n", ans);
  return 0;
}
