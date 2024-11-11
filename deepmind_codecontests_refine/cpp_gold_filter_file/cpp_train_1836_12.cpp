#include <bits/stdc++.h>
int classificacao(int p1, int p2, int p3) {
  int s2, s3;
  s2 = s3 = 0;
  while (p1 != p2) {
    s2++;
    p1++;
    if (p1 > 11) p1 = 0;
  }
  while (p2 != p3) {
    s3++;
    p2++;
    if (p2 > 11) p2 = 0;
  }
  if (s2 == 4 && s3 == 3) return 1;
  if (s2 == 3 && s3 == 4) return -1;
  return 0;
}
int main() {
  char vec[][3] = {"C",  "C#", "D",  "D#", "E", "F",
                   "F#", "G",  "G#", "A",  "B", "H"};
  char a[3], b[3], c[3];
  int p1, p2, p3;
  p1 = p2 = p3 = 0;
  scanf("%s %s %s", a, b, c);
  while (strcmp(vec[p1], a) != 0) {
    p1++;
    if (p1 > 11) {
      printf("strange\n");
      return 0;
    }
  }
  p2 = p1;
  while (strcmp(vec[p2], b) != 0) {
    p2++;
    if (p2 > 11) {
      p2 = 0;
    } else if (p2 == p1) {
      printf("strange\n");
      return 0;
    }
  }
  p3 = p2;
  while (strcmp(vec[p3], c) != 0) {
    p3++;
    if (p3 > 11) {
      p3 = 0;
    } else if (p3 == p2) {
      printf("strange\n");
      return 0;
    }
  }
  if (classificacao(p1, p2, p3) == 1) {
    printf("major\n");
  } else if (classificacao(p1, p2, p3) == -1) {
    printf("minor\n");
  } else if (classificacao(p2, p1, p3) == 1) {
    printf("major\n");
  } else if (classificacao(p2, p1, p3) == -1) {
    printf("minor\n");
  } else if (classificacao(p1, p3, p2) == 1) {
    printf("major\n");
  } else if (classificacao(p1, p3, p2) == -1) {
    printf("minor\n");
  } else if (classificacao(p2, p3, p1) == 1) {
    printf("major\n");
  } else if (classificacao(p2, p3, p1) == -1) {
    printf("minor\n");
  } else if (classificacao(p3, p2, p1) == 1) {
    printf("major\n");
  } else if (classificacao(p3, p2, p1) == -1) {
    printf("minor\n");
  } else if (classificacao(p3, p1, p2) == 1) {
    printf("major\n");
  } else if (classificacao(p3, p1, p2) == -1) {
    printf("minor\n");
  } else {
    printf("strange\n");
  }
  return 0;
}
