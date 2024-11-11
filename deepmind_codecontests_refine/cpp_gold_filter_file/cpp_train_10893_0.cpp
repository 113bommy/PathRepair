#include <bits/stdc++.h>
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int s[10] = {0};
    int ja[10] = {0};
    for (int i = 0; i < n; i++) {
      char ch[101];
      scanf("%s", ch);
      int l = strlen(ch);
      ja[ch[0] - 97] = 1;
      for (int i = 0; i < l; i++) {
        int zhi = 1;
        for (int x = 0; x < l - i - 1; x++) {
          zhi = zhi * 10;
        }
        s[ch[i] - 97] = s[ch[i] - 97] + zhi;
      }
    }
    int t;
    for (int i = 0; i < 10; i++) {
      for (int j = i + 1; j < 10; j++) {
        if (s[i] < s[j]) {
          t = s[i];
          s[i] = s[j];
          s[j] = t;
          t = ja[i];
          ja[i] = ja[j];
          ja[j] = t;
        }
      }
    }
    int m = 0, z = 1;
    int max = 0;
    for (int i = 0; i < 10; i++) {
      if (ja[i] == 1 || m == 1) {
        max = max + s[i] * z;
        z = z + 1;
      }
      if (ja[i] == 0 && m != 1) {
        m = 1;
      }
    }
    printf("%d\n", max);
  }
}
