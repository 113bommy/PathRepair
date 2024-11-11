#include <bits/stdc++.h>
using namespace std;
int L, b, f;
int n;
int pos[100], pos2[100];
bool park[100000];
int req, len;
int now;
int main() {
  int i, j;
  scanf("%d%d%d", &L, &b, &f);
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d%d", &req, &len);
    if (req == 1) {
      now = 0;
      if (len > L) {
        printf("-1\n");
        continue;
      }
      for (j = 0; j < min(len + f, L); j++)
        if (park[j]) now++;
      if (now == 0) {
        pos[i] = 0;
        pos2[i] = len;
        printf("0\n");
        for (j = 0; j < len; j++) park[j] = 1;
        continue;
      }
      for (j; j < min(len + b + f, L); j++)
        if (park[j]) now++;
      while (j < L && now > 0) {
        if (park[j - len - b - f]) now--;
        if (park[j++]) now++;
      }
      if (now > 0) {
        now = 0;
        if (L - 1 - len - b >= 0) {
          for (j = L - 1; j > L - 1 - len - b; j--)
            if (park[j]) now++;
          if (now == 0) {
            while (!park[j]) j--;
            pos[i] = j + b + 1;
            pos2[i] = j + b + len + 1;
            printf("%d\n", j + b + 1);
            for (j = pos[i]; j < pos2[i]; j++) park[j] = 1;
            continue;
          }
        }
        printf("-1\n");
        continue;
      }
      pos[i] = j - len - f;
      pos2[i] = j - f;
      printf("%d\n", j - len - f);
      for (j = pos[i]; j < pos2[i]; j++) park[j] = 1;
    } else {
      for (j = pos[len - 1]; j < pos2[len - 1]; j++) park[j] = 0;
    }
  }
  return 0;
}
