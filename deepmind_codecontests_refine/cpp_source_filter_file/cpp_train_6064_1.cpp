#include <bits/stdc++.h>
using namespace std;
void loadData(void);
void proc(void);
void printRes(void);
int n;
int a[100000];
int main(int argc, char** argv) {
  loadData();
  proc();
  printRes();
  return 0;
}
void proc(void) {
  sort(a, a + n);
  return;
}
void loadData(void) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  return;
}
void printRes(void) {
  if (n == 1 && a[0] == 1) {
    printf("2\n");
  } else {
    printf("1");
    for (int i = 1; i < n; i++) {
      if (i == n - 1 && a[i - 1] == 1) {
        printf(" 2");
      } else {
        printf(" %d", a[i - 1]);
      }
    }
    printf("\n");
  }
  return;
}
