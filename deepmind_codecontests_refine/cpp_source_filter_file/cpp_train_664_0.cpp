#include <bits/stdc++.h>
int main() {
  int n, i, j, len = 0;
  char sms[100005], message[400005], word[100005];
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%s", word);
    message[len] = '<';
    message[len + 1] = '3';
    len += 2;
    for (j = 0; j < strlen(word); j++) {
      message[len] = word[j];
      len++;
    }
  }
  message[len] = '<';
  message[len + 1] = '3';
  len += 2;
  scanf("%s", sms);
  j = 0;
  for (i = 0; i <= len;) {
    if (j == strlen(sms)) {
      printf("no");
      return 0;
    }
    if (sms[j] != message[i]) {
      j++;
      continue;
    }
    j++;
    i++;
  }
  printf("yes");
  return 0;
}
