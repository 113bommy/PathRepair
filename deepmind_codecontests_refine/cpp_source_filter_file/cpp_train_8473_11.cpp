#include <bits/stdc++.h>
using namespace std;
int num[100005], n;
int main() {
  while (scanf("%d", &n) != EOF) {
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0, s6 = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &num[i]);
      if (num[i] == 1)
        s1++;
      else if (num[i] == 2)
        s2++;
      else if (num[i] == 3)
        s3++;
      else if (num[i] == 4)
        s4++;
      else if (num[i] == 6)
        s6++;
    }
    if (s1 != n / 3 || (s2 + s3) != n / 3 || ((s6 - s3 + s4) != s2) || s3 != s6)
      printf("-1\n");
    else {
      for (int i = 0; i < s4; i++) {
        printf("1 2 4\n");
      }
      s6 = s6 - s3;
      for (int i = 0; i < s6; i++) printf("1 2 6\n");
      for (int i = 0; i < s3; i++) printf("1 3 6\n");
    }
  }
  return 0;
}
