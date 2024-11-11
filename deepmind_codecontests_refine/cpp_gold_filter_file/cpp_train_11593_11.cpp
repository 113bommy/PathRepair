#include <bits/stdc++.h>
using namespace std;
int mm[4][4], mt[4], cm[4][4];
char s1[50], s2[50], ss[4][50], c, cs[4][50];
void sort() {
  for (int i = 0; i < 3; ++i)
    if (mm[i][0] < mm[i + 1][0] ||
        (mm[i][0] == mm[i + 1][0] &&
         (mm[i][1] - mm[i][2]) < (mm[i + 1][1] - mm[i + 1][2])) ||
        (mm[i][0] == mm[i + 1][0] &&
         (mm[i][1] - mm[i][2]) == (mm[i + 1][1] - mm[i + 1][2]) &&
         mm[i][1] < mm[i + 1][1]) ||
        (mm[i][0] == mm[i + 1][0] &&
         (mm[i][1] - mm[i][2]) == (mm[i + 1][1] - mm[i + 1][2]) &&
         mm[i][1] == mm[i + 1][1] && strcmp(ss[i], ss[i + 1]) > 0)) {
      memcpy(mt, mm[i], sizeof(mt));
      memcpy(mm[i], mm[i + 1], sizeof(mt));
      memcpy(mm[i + 1], mt, sizeof(mt));
      strcpy(s1, ss[i]);
      strcpy(ss[i], ss[i + 1]);
      strcpy(ss[i + 1], s1);
      if (i) i -= 2;
    }
}
int main() {
  int l = 0, i, j, a, b;
  memset(mm, 0, sizeof(mm));
  for (i = 0; i < 5; ++i) {
    cin >> s1 >> s2 >> a >> c >> b;
    for (j = 0; j < l; ++j)
      if (strcmp(ss[j], s1) == 0) break;
    if (j == l) {
      strcpy(ss[l], s1);
      ++l;
    }
    mm[j][1] += a;
    mm[j][2] += b;
    mm[j][0] += (a > b ? 3 : (a == b ? 1 : 0));
    mm[j][3]++;
    for (j = 0; j < l; ++j)
      if (strcmp(ss[j], s2) == 0) break;
    if (j == l) {
      strcpy(ss[l], s2);
      ++l;
    }
    mm[j][1] += b;
    mm[j][2] += a;
    mm[j][0] += (b > a ? 3 : (a == b ? 1 : 0));
    mm[j][3]++;
  }
  memcpy(cm, mm, sizeof(mm));
  memcpy(cs, ss, sizeof(ss));
  int t1, t2;
  for (i = 0; i < 4; ++i) {
    if (mm[i][3] == 2 && strcmp(ss[i], "BERLAND") == 0) t1 = i;
    if (mm[i][3] == 2 && strcmp(ss[i], "BERLAND") != 0) t2 = i;
  }
  int r1, r2;
  for (r2 = 1; r2 < 30; ++r2) {
    for (r1 = r2; r1 < 30; ++r1) {
      memcpy(mm, cm, sizeof(mm));
      memcpy(ss, cs, sizeof(ss));
      mm[t1][0] += 3;
      mm[t1][1] += r1;
      mm[t1][2] += r1 - r2;
      mm[t2][1] += r1 - r2;
      mm[t2][2] += r1;
      sort();
      for (i = 0; i < 4; ++i)
        if (strcmp(ss[i], "BERLAND") == 0) break;
      if (i < 2) break;
    }
    if (r1 < 30) break;
  }
  if (r2 == 30) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  cout << r1 << ":" << r1 - r2;
  return 0;
}
