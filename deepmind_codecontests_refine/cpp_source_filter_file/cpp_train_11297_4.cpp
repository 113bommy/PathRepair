#include <bits/stdc++.h>
void removeSp(char *desc, char *src) {
  while (*src) {
    if (*src >= 'a' && *src <= 'z') {
      *desc = *src;
      desc++;
    } else if (*src >= 'A' && *src <= 'Z') {
      *desc = 'a' + (*src - 'A');
      desc++;
    }
    src++;
  }
  *desc = 0;
}
void getAns(char (*ans)[1000], char (*teach)[200]) {
  strcat(ans[0], teach[0]);
  strcat(ans[0], teach[1]);
  strcat(ans[0], teach[2]);
  strcat(ans[1], teach[0]);
  strcat(ans[1], teach[2]);
  strcat(ans[1], teach[1]);
  strcat(ans[2], teach[1]);
  strcat(ans[2], teach[0]);
  strcat(ans[2], teach[2]);
  strcat(ans[3], teach[1]);
  strcat(ans[3], teach[2]);
  strcat(ans[3], teach[0]);
  strcat(ans[4], teach[2]);
  strcat(ans[4], teach[0]);
  strcat(ans[4], teach[1]);
  strcat(ans[5], teach[2]);
  strcat(ans[5], teach[1]);
  strcat(ans[5], teach[0]);
}
int main(void) {
  int n = 0, i = 0;
  int len = 0;
  char isAc = 0;
  char inp[1000] = {
      0,
  };
  char stu[1000] = {
      0,
  };
  char teach[3][200] = {{
      0,
  }};
  char ans[6][1000] = {{
      0,
  }};
  for (i = 0; i < 3; i++) {
    scanf("%s", inp);
    removeSp(teach[i], inp);
  }
  getAns(ans, teach);
  len = strlen(ans[0]);
  scanf("%d", &n);
  while (n--) {
    scanf("%s", inp);
    removeSp(stu, inp);
    if (len != strlen(stu)) {
      printf("WA\n");
    } else {
      isAc = 0;
      for (i = 0; i < 6; i++) {
        if (strcmp(stu, ans[i]) == 0) {
          isAc = 1;
          break;
        }
      }
      if (isAc) {
        printf("AAC\n");
      } else {
        printf("WA\n");
      }
    }
  }
  return 0;
}
