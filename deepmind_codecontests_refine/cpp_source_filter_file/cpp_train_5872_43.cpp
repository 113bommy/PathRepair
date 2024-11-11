#include <bits/stdc++.h>
using namespace std;
int n;
char S[105], T[105];
int main() {
  int i;
  scanf("%d", &n);
  for (i = 0; i < n / 2; i++) S[i] = '>';
  for (i = n / 2; i < n - 1; i++) S[i] = ((i - n / 2) & 1) ? '>' : '.';
  S[n - 1] = 'v';
  for (i = 0; i < n; i++) {
    T[i] = S[i];
    if (T[i] == '>') T[i] = '<';
    if (T[i] == 'v') T[i] = '^';
  }
  reverse(T, T + n);
  for (i = 1; i <= n; i++) printf("%s\n", i & 1 ? S : T);
  printf("1 1");
  return 0;
}
