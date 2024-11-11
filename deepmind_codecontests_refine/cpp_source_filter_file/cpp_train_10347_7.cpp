#include <bits/stdc++.h>
using namespace std;
char a[2000005];
char b[2000005];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int first = 0;
    int second = 0;
    int pos = 0;
    scanf("%s", a);
    scanf("%s", b);
    for (int i = 0; i < n * 2; i++) {
      if (a[i] == '1') first++;
      if (b[i] == '1') second++;
      if (a[i] == '1' && b[i] == '1') pos++;
    }
    if (pos % 2 + first > second)
      printf("First\n");
    else if (pos % 2 + first > second - 1)
      printf("Draw\n");
    else
      printf("Second\n");
  }
  return 0;
}
