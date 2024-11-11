#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int n;
char s1[N], s2[N];
int len, Next[N];
void getnext(char s[]) {
  Next[0] = -1;
  int j = -1, i = 0;
  while (i < n) {
    if (j == -1 || s[i] == s[j]) {
      i++;
      j++;
      Next[i] = j;
    } else
      j = Next[j];
  }
}
int kmp(char s1[], char s2[]) {
  int i = 0, j = 0;
  while (i < n) {
    if (j == -1 || s1[i] == s2[j]) {
      i++;
      j++;
    } else {
      j = Next[j];
    }
  }
  if (j > 0) return 1;
  return 0;
}
int main() {
  scanf("%d", &n);
  scanf("%s%s", s1, s2);
  n--;
  for (int i = 0; i < n; i++) {
    if (s1[i] == 'E')
      s1[i] = 'W';
    else if (s1[i] == 'W')
      s1[i] = 'E';
    else if (s1[i] == 'N')
      s1[i] = 'S';
    else if (s1[i] == 'S')
      s1[i] = 'N';
  }
  reverse(s1, s1 + n);
  getnext(s1);
  if (kmp(s1, s2))
    puts("NO");
  else
    puts("YES");
}
