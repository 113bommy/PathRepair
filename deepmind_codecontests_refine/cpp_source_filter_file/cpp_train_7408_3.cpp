#include <bits/stdc++.h>
FILE *in = stdin;
FILE *out = stdout;
long long a, b;
int main() {
  int i, j, k;
  fscanf(in, "%d", &a);
  if (a % 2 == 0) {
    b = 1;
    for (i = 0; i < a / 2; i++) {
      b *= 2;
    }
    fprintf(out, "%lld", b);
  } else {
    fprintf(out, "%lld", 0);
  }
  return 0;
}
