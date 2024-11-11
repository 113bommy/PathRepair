#include <bits/stdc++.h>
using namespace std;
int main() {
  char in[110];
  int r, c;
  scanf("%d%d ", &r, &c);
  for (int i = 0; i < r; i++) {
    fgets(in, c + 3, stdin);
  }
  bool b = false;
  int count = 0;
  for (int i = 0; i < c; i++) {
    if (in[i] == 'B') {
      if (!b) count++;
      b = true;
    } else {
      b = false;
    }
  }
  printf("%d\n");
  return 0;
}
