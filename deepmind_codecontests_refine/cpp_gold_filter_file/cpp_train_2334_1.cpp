#include <bits/stdc++.h>
using namespace std;
int k;
char s[5];
int c[9];
int main() {
  scanf("%d", &k);
  for (int i = 0; i < 4; i++) {
    scanf("%s", s);
    for (int j = 0; j < 4; j++)
      if (s[j] >= '1') c[s[j] - '1']++;
  }
  for (int i = 0; i < 9; i++)
    if (c[i] > k * 2) {
      printf("NO");
      return 0;
    }
  printf("YES");
  return 0;
}
