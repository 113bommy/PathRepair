#include <bits/stdc++.h>
using namespace std;
int ans[] = {1, 1, 2, 2, 2, 4, 5, 6, 8, 14, 30};
string p[] = {"600000", "510000", "411000", "420000", "330000", "321000",
              "311100", "222000", "221100", "211110", "111111"};
char s[10] = "ROYGBV";
int num[10];
int main() {
  char ss[10];
  while (scanf("%s", ss) == 1) {
    memset(num, 0, sizeof(num));
    for (int i = 0; i < 6; i++)
      for (int j = 0; j < 6; j++)
        if (ss[i] == s[j]) num[j]++;
    for (int i = 0; i < 6; i++)
      for (int j = i + 1; j < 6; j++)
        if (num[i] < num[j]) {
          int t = num[i];
          num[i] = num[j];
          num[j] = t;
        }
    string q = "000000";
    for (int i = 0; i < 6; i++) q[i] += num[i];
    for (int i = 0; i < 11; i++)
      if (q == p[i]) {
        printf("%d\n", ans[i]);
      }
  }
  return 0;
}
