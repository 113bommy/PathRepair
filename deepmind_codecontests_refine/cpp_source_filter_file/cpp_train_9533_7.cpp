#include <bits/stdc++.h>
char *X[1111111], S[1111111], c;
unsigned Xa[1111111], Xi[1111111], D[1111111], Si;
void add(unsigned d) {
  unsigned i;
  for (i = -1; (c = S[++i]); X[d][Xi[d]++] = c)
    if (Xi[d] == Xa[d]) {
      if (!Xa[d])
        X[d] = (char *)calloc(Xa[d] = 1, sizeof(char));
      else
        X[d] = (char *)realloc(X[d], (Xa[d] <<= 1) * sizeof(char));
    }
  return;
}
int main() {
  unsigned d, dm;
  for (d = dm = 0;;) {
    for (Si = 0; (c = S[Si++] = getchar()) != ',';)
      if (c < ' ') goto done;
    S[Si] = '\0';
    S[Si - 1] = ' ';
    if (dm < d) dm = d;
    add(d);
    --D[d++];
    scanf("%u,", D + d);
    while (!D[d] && d) --d;
  }
done:;
  printf("%u\n", dm + 1);
  for (d = -1; ++d <= dm;) {
    X[d][Xi[d] - 1] = '\n';
    printf("%s", X[d]);
  }
  return 0;
}
