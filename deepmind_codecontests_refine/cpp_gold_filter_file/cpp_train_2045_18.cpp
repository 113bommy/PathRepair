#include <bits/stdc++.h>
using namespace std;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
int per[100100];
bool vis[100100];
int od5[100100][2][5];
int od4[100100][2][4];
int od3[100100][2][3];
int od2[100100][2][2];
int am[6];
int ct[5];
void add(int len, int *sa1, int *sa2) {
  for (int i = (0); i < (len); i++) sa1[i] = ct[i];
  for (int i = (0); i < (len); i++) sa2[i] = ct[(i + 1) % len];
}
void printAr(int *pr, int len) {
  for (int i = (0); i < (len); i++) {
    if (i) printf(" ");
    printf("%d", pr[i] + 1);
  }
  printf("\n");
}
int main() {
  int N;
  scanf("%d", &N);
  for (int i = (0); i < (N); i++) scanf("%d", per + i);
  for (int i = (0); i < (N); i++) --per[i];
  memset(vis, false, sizeof(vis));
  int res = 0, pos = 0;
  memset(am, 0, sizeof(am));
  for (int i = (0); i < (N); i++) {
    if (vis[i]) continue;
    if (per[i] == i) continue;
    vis[i] = true;
    int cp = i;
    int cam = 1;
    ct[0] = i;
    while (true) {
      int pcp = cp;
      cp = per[cp];
      if (vis[cp]) break;
      vis[cp] = true;
      if (cam == 5) {
        add(5, od5[am[5]][0], od5[am[5]][1]);
        am[5]++;
        cam = 1;
      }
      ct[cam++] = cp;
    }
    switch (cam) {
      case 2:
        add(2, od2[am[2]][0], od2[am[2]][1]);
        am[2]++;
        break;
      case 3:
        add(3, od3[am[3]][0], od3[am[3]][1]);
        am[3]++;
        break;
      case 4:
        add(4, od4[am[4]][0], od4[am[4]][1]);
        am[4]++;
        break;
      case 5:
        add(5, od5[am[5]][0], od5[am[5]][1]);
        am[5]++;
        break;
    }
  }
do22:
  while (am[2] > 0 && am[3] > 0) {
    --am[2];
    --am[3];
    for (int i = (0); i < (2); i++)
      for (int j = (0); j < (2); j++) od5[am[5]][i][j] = od2[am[2]][i][j];
    for (int i = (0); i < (2); i++)
      for (int j = (0); j < (3); j++) od5[am[5]][i][j + 2] = od3[am[3]][i][j];
    am[5]++;
  }
  while (am[2] > 1) {
    --am[2];
    for (int i = (0); i < (2); i++)
      for (int j = (0); j < (2); j++) od4[am[4]][i][j] = od2[am[2]][i][j];
    --am[2];
    for (int i = (0); i < (2); i++)
      for (int j = (0); j < (2); j++) od4[am[4]][i][j + 2] = od2[am[2]][i][j];
    ++am[4];
  }
  while (am[3] > 2) {
    --am[3];
    for (int i = (0); i < (2); i++) od2[am[2]][0][i] = od3[am[3]][0][i];
    for (int i = (0); i < (2); i++) od2[am[2]][1][i] = od2[am[2]][0][i ^ 1];
    ++am[2];
    for (int i = (0); i < (2); i++) od2[am[2]][0][i] = od3[am[3]][0][i + 1];
    for (int i = (0); i < (2); i++) od2[am[2]][1][i] = od2[am[2]][0][i ^ 1];
    ++am[2];
    goto do22;
  }
  int sum = 0;
  for (int i = (2); i < (6); i++) sum += am[i];
  printf("%d\n", sum);
  for (int i = int(6) - 1; i >= (2); i--)
    for (int j = (0); j < (am[i]); j++) {
      printf("%d\n", i);
      switch (i) {
        case 2:
          printAr(od2[j][0], 2);
          printAr(od2[j][1], 2);
          break;
        case 3:
          printAr(od3[j][0], 3);
          printAr(od3[j][1], 3);
          break;
        case 4:
          printAr(od4[j][0], 4);
          printAr(od4[j][1], 4);
          break;
        case 5:
          printAr(od5[j][0], 5);
          printAr(od5[j][1], 5);
          break;
      }
    }
  return 0;
}
