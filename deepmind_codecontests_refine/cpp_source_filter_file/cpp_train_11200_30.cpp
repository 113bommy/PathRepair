#include <bits/stdc++.h>
int main() {
  char s[20], s1[] = "Tetrahedron", s2[] = "Cube", s3[] = "Octahedron",
              s4[] = "Dodecahedron", s5[] = "Icosahedron";
  int n, i, sum = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", s);
    if (strcmp(s, s1) == 0) sum = sum + 4;
    if (strcmp(s, s2) == 0) sum = sum + 6;
    if (strcmp(s, s3) == 0) sum = sum + 8;
    if (strcmp(s, s4) == 0) sum = sum + 12;
    if (strcmp(s, s5) == 0) sum = sum + 16;
  }
  printf("%d", sum);
}
