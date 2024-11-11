#include <bits/stdc++.h>
const int MAXN = 5050;
const int MAX = 30;
int a[MAX], cou[MAX][2];
char s[MAXN], t[MAXN];
bool judge(int k) {
  for (int i = 0; i < 26; i++) {
    a[i] = cou[i][0];
  }
  for (int i = 0; i < k; i++) {
    a[t[i] - 'a']--;
    if (a[t[i] - 'a'] < 0) {
      return false;
    }
  }
  return true;
}
int main() {
  scanf("%s", &s);
  scanf("%s", &t);
  int lens = strlen(s);
  int lent = strlen(t);
  memset(cou, 0, sizeof(cou));
  for (int i = 0; i < lens; i++) {
    cou[s[i] - 'a'][0]++;
  }
  for (int i = 0; i < lent; i++) {
    cou[t[i] - 'a'][1]++;
  }
  int len = lent < lens ? lent : lens;
  int ret = 0;
  bool flag = false;
  for (int i = len; i >= 0; i--) {
    if (judge(i)) {
      if (i == lent) {
        if (lens > lent) {
          flag = true;
          ret = i;
          break;
        }
      } else {
        for (int j = 0; j < 26; j++) {
          if ((a[j]) && (j + 'a' > t[i])) {
            flag = true;
            break;
          }
        }
        if (flag) {
          ret = i;
          break;
        }
      }
    }
  }
  if (!flag) {
    printf("-1\n");
  } else {
    for (int i = 0; i < ret; i++) {
      printf("%c", t[i]);
      cou[t[i] - 'a'][0]--;
    }
    for (int i = 0; i < 26; i++) {
      if ((i + 'a' > t[ret]) && (cou[i][0] > 0)) {
        printf("%c", i + 'a');
        cou[i][0]--;
        break;
      }
    }
    for (int i = 0; i < 26; i++) {
      for (int j = 1; j <= cou[i][0]; j++) {
        printf("%c", i + 'a');
      }
    }
    printf("\n");
  }
  return 0;
}
