#include <bits/stdc++.h>
using namespace std;
int main() {
  char line[100000];
  char out[100000];
  scanf("%s", line);
  int size = 1;
  char max = 0;
  out[0] = line[strlen(line) - 1];
  for (int I = strlen(line) - 2; I >= 0; I--) {
    if (line[I] >= out[size - 1]) {
      out[size] = line[I];
      size++;
    }
  }
  out[size] = 0;
  reverse(out, out + size);
  printf("%s\n", out);
  return 0;
}
