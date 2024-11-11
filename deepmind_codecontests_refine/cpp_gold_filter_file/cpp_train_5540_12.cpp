#include <bits/stdc++.h>
int n;
char s[1024000];
long h[1024000];
int p[1024000];
long pow(long a, long b) {
  if (b <= 0)
    return 1;
  else if (b % 2 == 1)
    return a * pow(a, b - 1);
  else {
    long root = pow(a, b / 2);
    return root * root;
  }
}
void rollHash() {
  h[n - 1] = s[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    h[i] = s[i] + h[i + 1] * 33;
  }
}
long hashSubstr(int i, int j) { return h[i] - h[j + 1] * pow(33, j + 1 - i); }
int prefix() {
  int i, j, aux = -1, aux2 = -1, aux3 = 0;
  for (i = 0; i < n - 1; i++) {
    if (hashSubstr(0, i) == hashSubstr(n - i - 1, n - 1)) {
      aux2 = aux;
      aux = i;
    }
  }
  aux3 = hashSubstr(0, aux);
  for (j = 1; j + aux < n - 1; j++) {
    if (aux3 == hashSubstr(j, aux + j)) return aux;
  }
  if (aux2 == -1) return -1;
  return aux2;
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  rollHash();
  int index = prefix();
  if (index == -1)
    printf("Just a legend\n");
  else {
    char c[n];
    strcpy(c, s);
    c[index + 1] = '\0';
    printf("%s\n", c);
  }
  return 0;
}
