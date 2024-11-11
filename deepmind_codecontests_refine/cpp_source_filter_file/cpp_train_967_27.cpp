#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int imax = 0;
char str[N];
void fun(char *temp) {
  memset(str, 0, sizeof(str));
  int len = strlen(temp), cnt = 0;
  bool flag = 0;
  for (int i = 0; i < len; i++) {
    if (flag)
      str[cnt++] = temp[i];
    else if (temp[i] != '0') {
      flag = 1;
      str[cnt++] = temp[i];
    }
  }
  if (!flag) str[0] = '0';
}
bool judge(int base, char *str1, char *str2) {
  int len1 = strlen(str1), len2 = strlen(str2), hour = 0;
  for (int i = 0; i < len1; i++) {
    if (isdigit(str1[i]))
      hour = hour * base + str1[i] - '0';
    else
      hour = hour * imax + str1[i] - 'A' + 10;
  }
  if (hour >= 24) return 0;
  int min = 0;
  for (int i = 0; i < len2; i++) {
    if (isdigit(str2[i]))
      min = min * base + str2[i] - '0';
    else
      min = min * imax + str2[i] - 'A' + 10;
  }
  if (min >= 60) return 0;
  return 1;
}
int prejudge(char *str1, char *str2) {
  int len1 = strlen(str1), len2 = strlen(str2);
  if (len1 == 1 && len2 == 1) {
    if (str1[0] >= 'O')
      return 0;
    else
      return -1;
  } else {
    bool flag = judge(imax, str1, str2);
    if (flag == 0)
      return 0;
    else
      return 1;
  }
}
int main() {
  char sstr[N];
  while (scanf("%s", sstr) != EOF) {
    imax = 0;
    int len = strlen(sstr);
    for (int i = 0; i < len; i++) {
      if (isdigit(sstr[i]))
        imax = max(imax, sstr[i] - '0');
      else if (isalpha(sstr[i]))
        imax = max(imax, sstr[i] - 'A' + 10);
    }
    imax++;
    char temp1[N], temp2[N], str1[N] = {0}, str2[N] = {0};
    sscanf(sstr, "%[^:]:%s", temp1, temp2);
    fun(temp1);
    strcpy(str1, str);
    fun(temp2);
    strcpy(str2, str);
    int flag = prejudge(str1, str2);
    if (flag <= 0) {
      printf("%d\n", flag);
      continue;
    }
    for (int i = imax; i <= 60; i++) {
      if (judge(i, str1, str2)) {
        flag = 1;
        printf("%d ", i);
      }
    }
    puts("");
  }
  return 0;
}
