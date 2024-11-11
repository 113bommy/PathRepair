#include <bits/stdc++.h>
using namespace std;
const int MAXLEN = 500005;
char s[MAXLEN] = {}, t[MAXLEN] = {};
int ans[MAXLEN] = {};
int fail[MAXLEN] = {};
int main() {
  scanf("%s", s);
  scanf("%s", t);
  if (strlen(t) > strlen(s)) {
    printf("01\n");
    return 0;
  }
  int i = 1, j = 0;
  while (i < (int)strlen(t)) {
    if (t[i] == t[j]) {
      fail[i] = j + 1;
      i++;
      j++;
    } else if (j > 0) {
      j = fail[j - 1];
    } else {
      fail[i] = 0;
      i++;
    }
  }
  int cnt0 = 0, cnt1 = 0;
  for (i = 0; i < (int)strlen(s); i++) {
    if (s[i] == '0') cnt0++;
    if (s[i] == '1') cnt1++;
  }
  i = 0;
  j = 0;
  while (cnt0 > 0 && cnt1 > 0) {
    if (i >= (int)strlen(t)) i = fail[i - 1];
    if (t[i] == '0') {
      ans[j] = 0;
      j++;
      i++;
      cnt0--;
    } else if (t[i] == '1') {
      ans[j] = 1;
      j++;
      i++;
      cnt1--;
    }
  }
  if (!cnt0)
    while (cnt1 > 0) {
      ans[j] = 1;
      cnt1--;
      j++;
    }
  if (!cnt1)
    while (cnt0 > 0) {
      ans[j] = 0;
      cnt0--;
      j++;
    }
  for (i = 0; i < j; i++) printf("%d", ans[i]);
  printf("\n");
}
