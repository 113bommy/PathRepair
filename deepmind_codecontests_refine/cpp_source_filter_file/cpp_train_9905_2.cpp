#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  int a[5050][2];
  int t1, t2, t3, t4;
  cin >> n;
  char c;
  getchar();
  for (int i = 1; i <= n; i++) {
    scanf("%c", &c);
    if (c == '1')
      a[i][0] = 1;
    else
      a[i][0] = 0;
  }
  getchar();
  for (int i = 1; i <= n; i++) {
    scanf("%c", &c);
    if (c == '1')
      a[i][1] = 1;
    else
      a[i][1] = 0;
    if (a[i][0] == 0 && a[i][1] == 0) s1++;
    if (a[i][0] == 0 && a[i][1] == 1) s2++;
    if (a[i][0] == 1 && a[i][1] == 0) s3++;
    if (a[i][0] == 1 && a[i][1] == 1) s4++;
  }
  int i, j;
  bool pd = false;
  for (i = 0; i <= s2; i++) {
    if (pd == true) break;
    for (j = 0; j <= s3; j++) {
      if ((s2 - i + j + s4) % 2 == 1) continue;
      if (abs(s2 - i - j) > s4) {
        continue;
      }
      if (s2 - i > j) {
        t1 = i + j + s2 - i - j + (s4 - (s2 - i - j)) / 2;
        t2 = s2 - i + s3 - j + (s4 - (s2 - i - j)) / 2;
        if (t1 <= n / 2 && t2 <= n / 2) {
          t1 = n / 2 - t1;
          t2 = i;
          t3 = j;
          t4 = (s4 + (s2 - i - j)) / 2;
          for (int k = 1; k <= n; k++) {
            if (t1 != 0 && a[k][0] == 0 && a[k][1] == 0) {
              printf("%d ", k);
              t1--;
            }
            if (t2 != 0 && a[k][0] == 0 && a[k][1] == 1) {
              printf("%d ", k);
              t2--;
            }
            if (t3 != 0 && a[k][0] == 1 && a[k][1] == 0) {
              printf("%d ", k);
              t3--;
            }
            if (t4 != 0 && a[k][0] == 1 && a[k][1] == 1) {
              printf("%d ", k);
              t4--;
            }
          }
          pd = true;
          break;
        }
      }
      if (s2 - i < j) {
        t1 = i + j + (s4 - (j - s2 + i)) / 2;
        t2 = s2 - i + s3 - j + (s4 + (j - s2 + i)) / 2;
        if (t1 <= n / 2 && t2 <= n / 2) {
          t1 = n / 2 - t1;
          t2 = i;
          t3 = j;
          t4 = (s4 - (j - s2 + i)) / 2;
          for (int i = 1; i <= n; i++) {
            if (t1 != 0 && a[i][0] == 0 && a[i][1] == 0) {
              printf("%d ", i);
              t1--;
            }
            if (t2 != 0 && a[i][0] == 0 && a[i][1] == 1) {
              printf("%d ", i);
              t2--;
            }
            if (t3 != 0 && a[i][0] == 1 && a[i][1] == 0) {
              printf("%d ", i);
              t3--;
            }
            if (t4 != 0 && a[i][0] == 1 && a[i][1] == 1) {
              printf("%d ", i);
              t4--;
            }
          }
          pd = true;
          break;
        }
      }
      if (i == j) {
        t1 = i + j + (s4) / 2;
        t2 = s2 - i + s3 - j + (s4) / 2;
        if (t1 <= n / 2 && t2 <= n / 2) {
          t1 = n / 2 - t1;
          t2 = i;
          t3 = j;
          t4 = (s4) / 2;
          for (int i = 1; i <= n; i++) {
            if (t1 != 0 && a[i][0] == 0 && a[i][1] == 0) {
              printf("%d ", i);
              t1--;
            }
            if (t2 != 0 && a[i][0] == 0 && a[i][1] == 1) {
              printf("%d ", i);
              t2--;
            }
            if (t3 != 0 && a[i][0] == 1 && a[i][1] == 0) {
              printf("%d ", i);
              t3--;
            }
            if (t4 != 0 && a[i][0] == 1 && a[i][1] == 1) {
              printf("%d ", i);
              t4--;
            }
          }
          pd = true;
          break;
        }
      }
    }
  }
  if (pd == false) cout << -1 << endl;
  return 0;
}
