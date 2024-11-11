#include <cstdio>

int N, C;
char s[105];

int main() {
  scanf("%d", &N);
  scanf("%s", s + 1);
  for (int i = 1; i <= N; ++i)
    C += s[i] == 'R' ? 1 : -1;
  puts(C > 0 ? "Yes" : "No");
  return 0;
}