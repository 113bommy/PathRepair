#include <bits/stdc++.h>
int main() {
  char s[81], s0[11], s1[11], s2[11], s3[11], s4[11], s5[11], s6[11], s7[11],
      s8[11], s9[11];
  int k = 0, f0, f1, f2, f3, f4, f5, f6, f7, f8, f9, l, j, i;
  scanf("%s", &s);
  scanf("%s", &s0);
  scanf("%s", &s1);
  scanf("%s", &s2);
  scanf("%s", &s3);
  scanf("%s", &s4);
  scanf("%s", &s5);
  scanf("%s", &s6);
  scanf("%s", &s7);
  scanf("%s", &s8);
  scanf("%s", &s9);
  for (l = 0; l < 8; l++) {
    f0 = 1;
    f1 = 1;
    f2 = 1;
    f3 = 1;
    f4 = 1;
    f5 = 1;
    f6 = 1;
    f7 = 1;
    f8 = 1;
    f9 = 1;
    i = 0;
    for (j = k; j < k + 10; j++) {
      if (s0[i] != s[j]) f0 = 0;
      if (s1[i] != s[j]) f1 = 0;
      if (s2[i] != s[j]) f2 = 0;
      if (s3[i] != s[j]) f3 = 0;
      if (s4[i] != s[j]) f4 = 0;
      if (s5[i] != s[j]) f5 = 0;
      if (s6[i] != s[j]) f6 = 0;
      if (s7[i] != s[j]) f7 = 0;
      if (s8[i] != s[j]) f8 = 0;
      if (s9[i] != s[j]) f9 = 0;
      i++;
    }
    if (f0 == 1) printf("0");
    if (f1 == 1) printf("1");
    if (f2 == 1) printf("2");
    if (f3 == 1) printf("3");
    if (f4 == 1) printf("4");
    if (f5 == 1) printf("5");
    if (f6 == 1) printf("6");
    if (f7 == 1) printf("7");
    if (f8 == 1) printf("8");
    if (f9 == 1) printf("9");
  }
  k += 10;
  return 0;
}
