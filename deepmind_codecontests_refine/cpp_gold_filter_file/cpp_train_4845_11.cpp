#include <bits/stdc++.h>
int main() {
  int N;
  char a[20];
  scanf("%d", &N);
  while (N--) {
    scanf("%s", a);
    int t = strlen(a) - 4;
    int s = 0;
    if (t == 1) {
      if (a[4] == '9')
        printf("1989\n");
      else
        printf("199%c\n", a[4]);
    } else if (t == 2) {
      if (a[4] == '9' && a[5] == '9')
        printf("1999\n");
      else
        printf("20%c%c\n", a[4], a[5]);
    } else if (t == 3) {
      s = (a[4] - '0') * 100 + (a[5] - '0') * 10 + (a[6] - '0');
      if (s > 98)
        printf("2%c%c%c\n", a[4], a[5], a[6]);
      else
        printf("3%c%c%c\n", a[4], a[5], a[6]);
    } else if (t == 4) {
      int k = 1;
      for (int i = t + 3; i >= 4; i--) {
        s += (a[i] - '0') * k;
        k *= 10;
      }
      if (s >= 3099) {
        for (int i = 4; i < t + 4; i++) printf("%c", a[i]);
        printf("\n");
      } else {
        printf("1");
        for (int i = 4; i < t + 4; i++) printf("%c", a[i]);
        printf("\n");
      }
    } else if (t == 5) {
      int k = 1;
      for (int i = t + 3; i >= 4; i--) {
        s += (a[i] - '0') * k;
        k *= 10;
      }
      if (s >= 13099) {
        for (int i = 4; i < t + 4; i++) printf("%c", a[i]);
        printf("\n");
      } else {
        printf("1");
        for (int i = 4; i < t + 4; i++) printf("%c", a[i]);
        printf("\n");
      }
    } else if (t == 6) {
      int k = 1;
      for (int i = t + 3; i >= 4; i--) {
        s += (a[i] - '0') * k;
        k *= 10;
      }
      if (s >= 113099) {
        for (int i = 4; i < t + 4; i++) printf("%c", a[i]);
        printf("\n");
      } else {
        printf("1");
        for (int i = 4; i < t + 4; i++) printf("%c", a[i]);
        printf("\n");
      }
    } else if (t == 7) {
      int k = 1;
      for (int i = t + 3; i >= 4; i--) {
        s += (a[i] - '0') * k;
        k *= 10;
      }
      if (s >= 1113099) {
        for (int i = 4; i < t + 4; i++) printf("%c", a[i]);
        printf("\n");
      } else {
        printf("1");
        for (int i = 4; i < t + 4; i++) printf("%c", a[i]);
        printf("\n");
      }
    } else if (t == 8) {
      int k = 1;
      for (int i = t + 3; i >= 4; i--) {
        s += (a[i] - '0') * k;
        k *= 10;
      }
      if (s >= 11113099) {
        for (int i = 4; i < t + 4; i++) printf("%c", a[i]);
        printf("\n");
      } else {
        printf("1");
        for (int i = 4; i < t + 4; i++) printf("%c", a[i]);
        printf("\n");
      }
    } else if (t == 9) {
      int k = 1;
      for (int i = t + 3; i >= 4; i--) {
        s += (a[i] - '0') * k;
        k *= 10;
      }
      if (s >= 111113099) {
        for (int i = 4; i < t + 4; i++) printf("%c", a[i]);
        printf("\n");
      } else {
        printf("1");
        for (int i = 4; i < t + 4; i++) printf("%c", a[i]);
        printf("\n");
      }
    }
  }
}
