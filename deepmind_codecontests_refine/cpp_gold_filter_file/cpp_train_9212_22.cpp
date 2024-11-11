#include <bits/stdc++.h>
using namespace std;
int a[10][10];
int rec[10];
int chang[10];
int kuan[10];
char ans[999][999];
int outp;
int main() {
  scanf("%d%d%d%d%d%d", &a[1][0], &a[1][1], &a[2][0], &a[2][1], &a[3][0],
        &a[3][1]);
  for (int r1 = 0; r1 < 2; r1++)
    for (int r2 = 0; r2 < 2; r2++)
      for (int r3 = 0; r3 < 2; r3++) {
        chang[1] = a[1][r1];
        kuan[1] = a[1][1 - r1];
        chang[2] = a[2][r2];
        kuan[2] = a[2][1 - r2];
        chang[3] = a[3][r3];
        kuan[3] = a[3][1 - r3];
        if (chang[1] == chang[2] && chang[2] == chang[3] &&
            kuan[1] + kuan[2] + kuan[3] == chang[1]) {
          outp = chang[1];
          for (int i = 1; i <= kuan[1] + kuan[2] + kuan[3]; i++) {
            if (i <= kuan[1]) {
              for (int j = 1; j <= chang[1]; j++) {
                ans[i][j] = 'A';
              }
              continue;
            }
            if (i <= kuan[2] + kuan[1]) {
              for (int j = 1; j <= chang[2]; j++) {
                ans[i][j] = 'B';
              }
              continue;
            }
            for (int j = 1; j <= chang[3]; j++) {
              ans[i][j] = 'C';
            }
          }
          cout << outp << endl;
          for (int hang = 1; hang <= outp; hang++) {
            for (int lie = 1; lie < outp; lie++) {
              printf("%c", ans[hang][lie]);
            }
            printf("%c\n", ans[hang][outp]);
          }
          return 0;
        }
        for (int i = 1; i <= 3; i++) {
          for (int j = 1; j <= 3; j++) {
            for (int k = 1; k <= 3; k++) {
              if (i != j && j != k && k != i) {
                rec[1] = i;
                rec[2] = j;
                rec[3] = k;
                if (kuan[rec[1]] == kuan[rec[2]] + kuan[rec[3]] &&
                    chang[rec[2]] == chang[rec[3]] &&
                    chang[rec[2]] + chang[rec[1]] == kuan[rec[1]]) {
                  outp = kuan[rec[1]];
                  for (int hang = 1; hang <= kuan[rec[1]]; hang++) {
                    for (int lie = 1; lie <= chang[rec[1]]; lie++) {
                      ans[hang][lie] = 'A' + rec[1] - 1;
                    }
                  }
                  for (int hang = 1; hang <= kuan[rec[2]]; hang++) {
                    for (int lie = chang[rec[1]] + 1;
                         lie <= chang[rec[1]] + chang[rec[2]]; lie++) {
                      ans[hang][lie] = 'A' + rec[2] - 1;
                    }
                  }
                  for (int hang = kuan[rec[2]] + 1;
                       hang <= kuan[rec[2]] + kuan[rec[3]]; hang++) {
                    for (int lie = chang[rec[1]] + 1;
                         lie <= chang[rec[1]] + chang[rec[3]]; lie++) {
                      ans[hang][lie] = 'A' + rec[3] - 1;
                    }
                  }
                  cout << outp << endl;
                  for (int hang = 1; hang <= outp; hang++) {
                    for (int lie = 1; lie < outp; lie++) {
                      printf("%c", ans[hang][lie]);
                    }
                    printf("%c\n", ans[hang][outp]);
                  }
                  return 0;
                }
              }
            }
          }
        }
      }
  puts("-1");
  return 0;
}
