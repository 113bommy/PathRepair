#include <bits/stdc++.h>
using namespace std;
int boje[30];
int main() {
  for (int i = (1); i <= (24); ++i) scanf("%d", &boje[i]);
  if (boje[1] == boje[3] && boje[3] == boje[6] && boje[6] == boje[8] &&
      boje[2] == boje[4] && boje[4] == boje[22] && boje[22] == boje[24] &&
      boje[21] == boje[23] && boje[23] == boje[9] && boje[9] == boje[11] &&
      boje[5] == boje[7] && boje[7] == boje[10] && boje[10] == boje[12] &&
      boje[13] == boje[14] && boje[14] == boje[15] && boje[15] == boje[16] &&
      boje[17] == boje[18] && boje[18] == boje[19] && boje[19] == boje[20]) {
    printf("YES\n");
    return 0;
  } else if (boje[1] == boje[2] && boje[2] == boje[14] &&
             boje[14] == boje[16] && boje[3] == boje[4] &&
             boje[4] == boje[18] && boje[18] == boje[20] &&
             boje[17] == boje[19] && boje[19] == boje[12] &&
             boje[12] == boje[11] && boje[9] == boje[10] &&
             boje[10] == boje[13] && boje[13] == boje[15] &&
             boje[5] == boje[6] && boje[6] == boje[7] && boje[7] == boje[8] &&
             boje[21] == boje[22] && boje[22] == boje[23] &&
             boje[23] == boje[24]) {
    printf("YES\n");
    return 0;
  } else if (boje[2] == boje[4] && boje[4] == boje[5] && boje[5] == boje[7] &&
             boje[6] == boje[8] && boje[8] == boje[9] && boje[9] == boje[11] &&
             boje[10] == boje[12] && boje[12] == boje[22] &&
             boje[22] == boje[24] && boje[1] == boje[3] &&
             boje[3] == boje[21] && boje[21] == boje[23] &&
             boje[13] == boje[14] && boje[14] == boje[15] &&
             boje[15] == boje[16] && boje[17] == boje[18] &&
             boje[18] == boje[19] && boje[19] == boje[20]) {
    printf("YES\n");
    return 0;
  } else if (boje[1] == boje[2] && boje[2] == boje[17] &&
             boje[17] == boje[19] && boje[9] == boje[10] &&
             boje[10] == boje[18] && boje[18] == boje[20] &&
             boje[11] == boje[12] && boje[12] == boje[14] &&
             boje[14] == boje[16] && boje[13] == boje[15] &&
             boje[15] == boje[4] && boje[4] == boje[3] && boje[5] == boje[6] &&
             boje[6] == boje[7] && boje[7] == boje[8] && boje[21] == boje[22] &&
             boje[22] == boje[23] && boje[23] == boje[24]) {
    printf("YES\n");
    return 0;
  } else if (boje[5] == boje[6] && boje[6] == boje[19] &&
             boje[19] == boje[20] && boje[17] == boje[18] &&
             boje[18] == boje[23] && boje[23] == boje[24] &&
             boje[21] == boje[22] && boje[22] == boje[15] &&
             boje[15] == boje[16] && boje[13] == boje[14] &&
             boje[14] == boje[7] && boje[7] == boje[8] && boje[1] == boje[2] &&
             boje[2] == boje[3] && boje[3] == boje[4] && boje[9] == boje[10] &&
             boje[10] == boje[11] && boje[11] == boje[12]) {
    printf("YES\n");
    return 0;
  } else if (boje[19] == boje[20] && boje[20] == boje[21] &&
             boje[21] == boje[22] && boje[23] == boje[24] &&
             boje[24] == boje[13] && boje[13] == boje[14] &&
             boje[15] == boje[16] && boje[16] == boje[5] &&
             boje[5] == boje[6] && boje[7] == boje[8] && boje[8] == boje[17] &&
             boje[17] == boje[18] && boje[1] == boje[2] && boje[2] == boje[3] &&
             boje[3] == boje[4] && boje[9] == boje[10] &&
             boje[10] == boje[11] && boje[11] == boje[12]) {
    printf("YES\n");
    return 0;
  }
  printf("NO\n");
  return 0;
}
