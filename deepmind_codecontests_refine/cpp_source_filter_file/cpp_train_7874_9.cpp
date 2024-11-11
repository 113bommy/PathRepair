#include <bits/stdc++.h>
using namespace std;
char str[1010];
int ck() {
  if (str[0] == 'g' || str[0] == 'd' || str[0] == 'c' || str[2] == 't')
    return 2;
  if (str[0] == 'a' || str[0] == 'g' || str[0] == 'w' || str[0] == 't') {
    return 1;
  }
  if (str[3] == 'w') return 1;
  return 0;
}
int main() {
  for (int i = 0; i <= 9; ++i) {
    memset(str, 0, sizeof(str));
    printf("%d\n", i);
    cin.getline(str, 20);
    int c = ck();
    if (c == 1) {
      printf("grumpy\n");
      return 0;
    }
    if (c == 2) {
      printf("normal\n");
      return 0;
    }
  }
  puts("normal");
  return 0;
}
