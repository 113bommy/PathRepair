#include <bits/stdc++.h>
using namespace std;
int charcount[26];
int res[26];
int n, tempcount, tnum;
char c;
int main() {
  for (int i = 0; i < 1024; ++i) {
    scanf("%c", &c);
    if (!(c - 'a' >= 0) && (c - 'a' < 26)) {
      break;
    }
    ++charcount[c - 'a'];
  }
  scanf("%d", &n);
  for (int i = 0; i < 26; ++i)
    if (charcount[i] != 0) ++tnum;
  if (tnum > n) return printf("-1"), 0;
  for (int i = 1; i < 1001; ++i) {
    tempcount = 0;
    for (int j = 0; j < 26; ++j) {
      tempcount += res[j] = (charcount[j] + i - 1) / i;
    }
    if (tempcount <= n) {
      printf("%d\n", i);
      for (int j = 0; j < 26; ++j)
        for (int k = 0; k < res[j]; ++k) printf("%c", j + 'a');
      for (int j = tempcount; j < n; ++j) printf("a");
      printf("\n");
      return 0;
    }
  }
}
