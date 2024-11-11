#include <bits/stdc++.h>
int w;
char s[3][int(1e5 + 23)];
int main(int argn, char **args) {
  std::scanf("%s%s", s[0], s[1]);
  for (int i(0); s[0][i]; ++i)
    s[2][i] = (s[0][i] == s[1][i] ? s[0][i] : s[w ^= 1][i]);
  std::printf("%s\n", w ? "impossible" : s[2]);
  return (0);
}
