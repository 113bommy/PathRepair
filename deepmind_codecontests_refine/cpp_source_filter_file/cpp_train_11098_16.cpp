#include <bits/stdc++.h>
using namespace std;
char s[100], s1[5] = {'v', '<', '^', '>'};
int n;
int main() {
  int i, j, k = 0;
  gets(s);
  scanf("%d", &n);
  if (s[0] == s[1]) {
    printf("undefined");
    return 0;
  }
  if (s[0] == '>' && s[2] == '<') {
    printf("undefined");
    return 0;
  }
  if (s[2] == '>' && s[0] == '<') {
    printf("undefined");
    return 0;
  }
  if (s[0] == '^' && s[2] == 'v') {
    printf("undefined");
    return 0;
  }
  if (s[2] == '^' && s[0] == 'v') {
    printf("undefined");
    return 0;
  }
  n = n % 4;
  for (i = 0; i < 4; i++)
    if (s1[i] == s[0]) {
      k = i;
      break;
    }
  k += n;
  k = k % 4;
  if (s[2] == s1[k])
    printf("cw");
  else
    printf("ccw");
  return 0;
}
