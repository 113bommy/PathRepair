#include <bits/stdc++.h>
int main(int argc, char* argv[]) {
  int q, nc = 0;
  scanf("%d", &q);
  bool flag;
  char old_nms[1000][21], new_nms[1000][21];
  for (int i = 0; i < q; i++) {
    char olds[21], news[21];
    scanf("%s %s", olds, news);
    flag = true;
    for (int j = 0; j < nc; j++)
      if (strcmp(new_nms[j], olds) == 0) {
        strcpy(new_nms[j], news);
        flag = false;
        break;
      }
    if (flag) {
      strcpy(old_nms[nc], olds);
      strcpy(new_nms[nc], news);
      nc++;
    }
  }
  printf("%d\n", nc);
  for (int i = 0; i < nc; i++) printf("%s %s\n", old_nms[i], new_nms[i]);
  return 0;
}
