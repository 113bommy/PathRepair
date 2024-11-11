#include <bits/stdc++.h>
const int magicconst = 73743071;
using namespace std;
const int maxn = 100500;
int p[maxn];
bool b[maxn];
vector<vector<int> > c[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (int)(n); ++i) scanf("%d", p + i), p[i]--;
  memset(b, 0, sizeof b);
  for (int i = 0; i < (int)(n); ++i) {
    if (!b[i]) {
      int temp = p[i];
      int cnt = 1;
      while (temp != i) cnt++, b[temp] = 1, temp = p[temp];
      b[i] = 1;
      vector<int> v;
      v.push_back(i);
      temp = p[i];
      while (temp != i) v.push_back(temp), temp = p[temp];
      c[cnt].push_back(v);
    }
  }
  int res = 0;
  int cnt2 = 0, cnt3 = 0;
  for (int i = 0; i < (int)(n); ++i) {
    res += (int)(c[i + 1]).size() * ((i + 1) / 4);
    if ((i + 1) % 4 == 2) cnt2 += (int)(c[i + 1]).size();
    if ((i + 1) % 4 == 3) cnt3 += (int)(c[i + 1]).size();
  }
  if (cnt2 >= cnt3)
    printf("%d\n", res + (cnt2 + cnt3 + 1) / 2);
  else
    printf("%d\n", res + cnt2 + 2 * ((cnt3 - cnt2) / 3) + (cnt3 - cnt2) % 3);
  for (int i = 4; i <= n; ++i) {
    for (int j = 0; j < (int)((int)(c[i]).size()); ++j) {
      int cur = 1;
      while (i - cur > 4) {
        printf("5\n");
        printf("%d ", c[i][j][0] + 1);
        for (int k = 0; k < (int)(4); ++k)
          printf("%d%c", c[i][j][cur + k] + 1, " \n"[k == 4]);
        for (int k = 0; k < (int)(4); ++k) printf("%d ", c[i][j][cur + k] + 1);
        printf("%d\n", c[i][j][0] + 1);
        cur += 4;
      }
      if (i - cur >= 3) {
        printf("%d\n", 1 + i - cur);
        printf("%d ", c[i][j][0] + 1);
        for (int k = 0; k < (int)(i - cur); ++k)
          printf("%d ", c[i][j][cur + k] + 1);
        printf("\n");
        for (int k = 0; k < (int)(i - cur); ++k)
          printf("%d ", c[i][j][cur + k] + 1);
        printf("%d\n", c[i][j][0] + 1);
      } else {
        vector<int> v;
        v.push_back(c[i][j][0]);
        for (int k = 0; k < (int)(i - cur); ++k) v.push_back(c[i][j][cur + k]);
        c[i - cur + 1].push_back(v);
      }
    }
  }
  if (cnt2 <= cnt3) {
    for (int i = 0; i < (int)(cnt2); ++i) {
      printf("5\n");
      printf("%d %d %d %d %d\n", c[2][i][0] + 1, c[2][i][1] + 1, c[3][i][0] + 1,
             c[3][i][1] + 1, c[3][i][2] + 1);
      printf("%d %d %d %d %d\n", c[2][i][1] + 1, c[2][i][0] + 1, c[3][i][1] + 1,
             c[3][i][2] + 1, c[3][i][0] + 1);
    }
    int i = cnt2;
    while (i + 2 < cnt3) {
      printf("5\n");
      printf("%d %d %d %d %d\n", c[3][i][0] + 1, c[3][i][1] + 1, c[3][i][2] + 1,
             c[3][i + 1][0] + 1, c[3][i + 1][1] + 1);
      printf("%d %d %d %d %d\n", c[3][i][1] + 1, c[3][i][2] + 1, c[3][i][0] + 1,
             c[3][i + 1][1] + 1, c[3][i + 1][0] + 1);
      printf("5\n");
      printf("%d %d %d %d %d\n", c[3][i + 2][0] + 1, c[3][i + 2][1] + 1,
             c[3][i + 2][2] + 1, c[3][i + 1][1] + 1, c[3][i + 1][2] + 1);
      printf("%d %d %d %d %d\n", c[3][i + 2][1] + 1, c[3][i + 2][2] + 1,
             c[3][i + 2][0] + 1, c[3][i + 1][2] + 1, c[3][i + 1][1] + 1);
      i += 3;
    }
    while (i < cnt3) {
      printf("3\n");
      printf("%d %d %d\n", c[3][i][0] + 1, c[3][i][1] + 1, c[3][i][2] + 1);
      printf("%d %d %d\n", c[3][i][1] + 1, c[3][i][2] + 1, c[3][i][0] + 1);
      i++;
    }
  } else {
    for (int i = 0; i < (int)(cnt3); ++i) {
      printf("5\n");
      printf("%d %d %d %d %d\n", c[2][i][0] + 1, c[2][i][1] + 1, c[3][i][0] + 1,
             c[3][i][1] + 1, c[3][i][2] + 1);
      printf("%d %d %d %d %d\n", c[2][i][1] + 1, c[2][i][0] + 1, c[3][i][1] + 1,
             c[3][i][2] + 1, c[3][i][0] + 1);
    }
    for (int i = cnt3; i + 1 < cnt2; i += 2) {
      printf("4\n");
      printf("%d %d %d %d\n", c[2][i][0] + 1, c[2][i][1] + 1,
             c[2][i + 1][0] + 1, c[2][i + 1][1] + 1);
      printf("%d %d %d %d\n", c[2][i][1] + 1, c[2][i][0] + 1,
             c[2][i + 1][1] + 1, c[2][i + 1][0] + 1);
    }
    if ((cnt2 - cnt3) & 1) {
      printf("2\n");
      printf("%d %d\n", c[2][cnt2 - 1][0] + 1, c[2][cnt2 - 1][1] + 1);
      printf("%d %d\n", c[2][cnt2 - 1][1] + 1, c[2][cnt2 - 1][0] + 1);
    }
  }
  return 0;
}
