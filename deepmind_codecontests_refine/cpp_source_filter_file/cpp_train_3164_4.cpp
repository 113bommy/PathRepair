#include <bits/stdc++.h>
using namespace std;
int h, w, k;
char hori[1000][1001];
char vert[1000][1001];
int tmp[1000][1000];
int ans[1000][1000];
void easy() {
  int satisfied = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++) {
      satisfied += hori[i][j] == 'E';
      satisfied += vert[i][j] == 'E';
    }
  if (satisfied * 4 < (2 * w * h - w - h) * 3) {
    puts("NO");
  } else {
    puts("YES");
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w - 1; j++) printf("1 ");
      printf("1\n");
    }
  }
}
void fill() {
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w - 1; j++)
      ans[i][j + 1] = hori[i][j] == 'E' ? ans[i][j] : !ans[i][j];
    if (i > 0) {
      int satisfied = 0;
      for (int j = 0; j < w; j++)
        satisfied += (ans[i][j] == ans[i - 1][j]) == (vert[i - 1][j] == 'E');
      if (satisfied < w - satisfied)
        for (int j = 0; j < w; j++) ans[i][j] = !ans[i][j];
    }
  }
}
void hard() {
  puts("YES");
  if (w >= h) {
    fill();
  } else {
    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++) swap(hori[i][j], vert[j][i]);
    swap(w, h);
    fill();
    for (int i = 0; i < w; i++)
      for (int j = 0; j < i; j++) swap(ans[i][j], ans[j][i]);
    swap(w, h);
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w - 1; j++) printf("%d ", ans[i][j] + 1);
    printf("%d\n", ans[i][w - 1] + 1);
  }
}
int main() {
  scanf("%d%d%d", &h, &w, &k);
  for (int i = 0; i < h - 1; i++) {
    scanf("%s", hori[i]);
    scanf("%s", vert[i]);
  }
  scanf("%s", hori[h - 1]);
  if (k == 1)
    easy();
  else
    hard();
}
