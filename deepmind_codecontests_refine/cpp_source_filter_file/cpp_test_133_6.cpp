#include <bits/stdc++.h>
void polyCrabWord() {
  int n;
  scanf("%d", &n);
  char **p = (char **)calloc(n - 2, sizeof(p));
  for (int i = 0; i < n - 2; i++) {
    p[i] = (char *)calloc(2, sizeof(char));
    scanf("%s", p[i]);
  }
  if (n == 3) {
    printf("a%s\n", p[0]);
  } else {
    char *result = (char *)calloc(n, sizeof(char));
    strcpy(result, p[0]);
    int d = 2;
    for (int i = 1; i < n - 2; i++) {
      if (*(p[i]) == *(p[i - 1] + 1)) {
        *(result + d) = *(p[i] + 1);
        d++;
      } else {
        strcpy(result + d, p[i]);
        d += 2;
      }
    }
    if (strlen(result) < n) {
      strcpy(result + strlen(result), "a");
    }
    printf("%s\n", result);
  }
}
int main() {
  int *p = (int *)malloc(7 * sizeof(int));
  int n = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    polyCrabWord();
  }
  return 0;
}
