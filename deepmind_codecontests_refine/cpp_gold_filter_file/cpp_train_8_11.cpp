#include <bits/stdc++.h>
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
char S[110];
int main() {
  int n = gi(), s = 0;
  scanf("%s", S + 1);
  for (int i = 1; i <= n; ++i)
    if (S[i] == '8') ++s;
  printf("%d\n", std::min(s, n / 11));
  return 0;
}
