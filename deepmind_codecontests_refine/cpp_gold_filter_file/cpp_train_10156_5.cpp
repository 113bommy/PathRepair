#include <bits/stdc++.h>
using namespace std;
int main() {
  long i, j, z, state = 0;
  char s[1000000];
  gets(s);
  long size;
  size = strlen(s);
  for (i = 0; i < size; i++) {
    if (s[i] == 'a' && state == 0)
      ;
    if (s[i] == 'a' && state != 0) break;
    if (s[i] != 'a') s[i] -= 1, state++;
  }
  if (state == 0) {
    for (i = 0; i < size; i++)
      if (s[i] == 'a') state++;
    if (state == size) s[size - 1] = 'z';
  }
  printf("%s", s);
}
