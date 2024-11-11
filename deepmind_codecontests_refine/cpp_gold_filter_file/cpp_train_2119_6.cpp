#include <bits/stdc++.h>
using namespace std;
struct GAY {
  int index;
  int memory;
};
GAY gay[100000];
int __cdecl cmp(const void *a, const void *b) {
  return (*(GAY *)a).memory - (*(GAY *)b).memory;
}
int main() {
  int cnt, mem, a, b;
  scanf("%d%d%d%d", &cnt, &mem, &a, &b);
  for (int i = 0; i < cnt; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    gay[i].index = i + 1;
    gay[i].memory = x * a + y * b;
  }
  qsort(gay, cnt, sizeof(GAY), cmp);
  int i = 0;
  for (i = 0; i < cnt; i++) {
    if (mem >= gay[i].memory) {
      mem -= gay[i].memory;
    } else {
      i--;
      printf("%d\n", i + 1);
      for (int j = 0; j <= i; j++) printf("%d ", gay[j].index);
      printf("\n");
      return 0;
    }
  }
  printf("%d\n", i);
  for (int j = 0; j < i; j++) printf("%d ", gay[j].index);
  printf("\n");
  return 0;
}
