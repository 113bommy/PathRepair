#include <bits/stdc++.h>
char temp[200];
char huruf[200][200];
int main() {
  int kasus, cnt;
  scanf("%d", &kasus);
  for (int i = 0; i < kasus; i++) {
    scanf("%s", temp);
    for (int j = 0; j <= cnt; j++) {
      if (j == cnt) {
        strcpy(huruf[j], temp);
        cnt++;
        printf("NO\n");
        break;
      }
      if (strcmp(huruf[j], temp) == 0) {
        printf("YES\n");
        break;
      }
    }
  }
}
