#include <bits/stdc++.h>
int main() {
  char str[1000], s1[100] = "January", s2[100] = "February", s3[100] = "March",
                  s4[100] = "April", s5[100] = "May", s6[100] = "June",
                  s7[100] = "July", s8[100] = "August", s9[100] = "September",
                  s10[100] = "Octber", s11[100] = "November",
                  s12[100] = "December";
  int k, a, b, c;
  scanf("%s%d", str, &k);
  if (strcmp(str, s1) == 0) {
    a = (1 + k) % 12;
  } else if (strcmp(str, s2) == 0) {
    a = (2 + k) % 12;
  } else if (strcmp(str, s3) == 0) {
    a = (3 + k) % 12;
  } else if (strcmp(str, s4) == 0) {
    a = (4 + k) % 12;
  } else if (strcmp(str, s5) == 0) {
    a = (5 + k) % 12;
  } else if (strcmp(str, s6) == 0) {
    a = (6 + k) % 12;
  } else if (strcmp(str, s7) == 0) {
    a = (7 + k) % 12;
  } else if (strcmp(str, s8) == 0) {
    a = (8 + k) % 12;
  } else if (strcmp(str, s9) == 0) {
    a = (9 + k) % 12;
  } else if (strcmp(str, s10) == 0) {
    a = (10 + k) % 12;
  } else if (strcmp(str, s11) == 0) {
    a = (11 + k) % 12;
  } else if (strcmp(str, s12) == 0) {
    a = (12 + k) % 12;
  }
  if (a == 1) {
    printf("%s\n", s1);
  } else if (a == 2) {
    printf("%s\n", s2);
  } else if (a == 3) {
    printf("%s\n", s3);
  } else if (a == 4) {
    printf("%s\n", s4);
  } else if (a == 5) {
    printf("%s\n", s5);
  } else if (a == 6) {
    printf("%s\n", s6);
  } else if (a == 7) {
    printf("%s\n", s7);
  } else if (a == 8) {
    printf("%s\n", s8);
  } else if (a == 9) {
    printf("%s\n", s9);
  } else if (a == 10) {
    printf("%s\n", s10);
  } else if (a == 11) {
    printf("%s\n", s11);
  } else if (a == 0) {
    printf("%s\n", s12);
  }
  return 0;
}
