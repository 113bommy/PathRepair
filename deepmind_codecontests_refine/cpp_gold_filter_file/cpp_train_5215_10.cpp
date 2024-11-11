#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, M = 1e6 + 2, OO = 0x3f3f3f3f;
char s[N];
int main() {
  scanf("%s", s);
  int len = strlen(s);
  int c = 0, sum = 0;
  int len_str = 0;
  for (int i = 0; i < len; ++i) {
    ++len_str;
    sum += (s[i] - '0');
    if ((s[i] - '0') % 3 == 0 || sum % 3 == 0 || len_str == 3) {
      ++c;
      sum = 0;
      len_str = 0;
    }
  }
  printf("%d\n", c);
  return 0;
}
