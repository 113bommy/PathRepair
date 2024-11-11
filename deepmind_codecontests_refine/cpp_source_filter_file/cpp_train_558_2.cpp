#include <bits/stdc++.h>
using namespace std;
long zero;
long type[] = {-1, -1, -1, -1, -1, -1, -1};
bool sign[5][5];
vector<long> ryo;
vector<long> toprint;
int main() {
  long i, j, k, x, result, s;
  char c[105];
  bool have;
  scanf("%ld", &k);
  zero = 0;
  memset(sign, false, sizeof sign);
  sign[1][2] = true;
  sign[1][3] = true;
  sign[1][4] = true;
  sign[2][4] = true;
  sign[2][1] = true;
  sign[3][1] = true;
  sign[4][1] = true;
  sign[4][2] = true;
  for (i = 1; i <= k; i++) {
    scanf("%ld", &x);
    if (x == 0) {
      zero++;
      continue;
    }
    sprintf(c, "%ld", x);
    if (strlen(c) == 3)
      type[1] = x;
    else if (strlen(c) == 1)
      type[4] = x;
    else if (x % 10 == 0)
      type[2] = x;
    else
      type[3] = x;
  }
  if (k == 1)
    printf("0\n");
  else {
    result = 0;
    for (s = 1; s < 16; s++) {
      while (ryo.size() > 0) ryo.pop_back();
      have = false;
      for (j = 0; j < 4; j++) {
        if ((s & (1 << j)) != 0) {
          if (type[j + 1] == -1) {
            have = true;
            break;
          } else
            ryo.push_back(j + 1);
        }
      }
      if (have == true)
        continue;
      else {
        if (ryo.size() == 1) {
          if (result == 0) {
            while (toprint.size() > 0) {
              toprint.pop_back();
            }
            toprint.push_back(type[ryo[0]]);
            result = 1;
          }
          continue;
        }
        for (i = 0; i < ryo.size() - 1; i++)
          for (j = i + 1; j < ryo.size(); j++) {
            if (sign[ryo[i]][ryo[j]] == false) {
              have = true;
              break;
            }
          }
        if (have == true)
          continue;
        else {
          if (ryo.size() > result) {
            result = ryo.size();
            while (toprint.size() > 0) {
              toprint.pop_back();
            }
            for (i = 0; i < ryo.size(); i++) toprint.push_back(type[ryo[i]]);
          }
        }
      }
    }
    printf("%ld\n", toprint.size() + zero);
    if (toprint.size() > 0) {
      printf("%ld", toprint[0]);
      for (i = 1; i < toprint.size(); i++) printf(" %ld", toprint[i]);
    }
    for (i = 1; i <= zero; i++) printf(" 0");
    printf("\n");
  }
}
