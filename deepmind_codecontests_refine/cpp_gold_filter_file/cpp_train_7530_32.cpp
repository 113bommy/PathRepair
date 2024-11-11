#include <bits/stdc++.h>
using namespace std;
int letter[26];
char ch[100050];
int main() {
  scanf("%s", ch);
  int maxn = 0;
  int end = -1;
  int l = strlen(ch);
  while (end < l - 1) {
    maxn = end + 1;
    int cnt = 0;
    for (int i = end + 1; i < l; i++) {
      if (ch[i] > ch[maxn]) {
        maxn = i;
        end = i;
        cnt = 0;
        cnt++;
      } else if (ch[i] == ch[maxn]) {
        cnt++;
        end = i;
      }
    }
    letter[ch[maxn] - 'a'] = cnt;
  }
  for (int i = 25; i >= 0; i--) {
    if (letter[i]) {
      for (int j = 0; j < letter[i]; j++) {
        printf("%c", 'a' + i);
      }
    }
  }
  printf("\n");
  return 0;
}
