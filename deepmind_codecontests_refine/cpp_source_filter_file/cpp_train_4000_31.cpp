#include <bits/stdc++.h>
using namespace std;
int arr[100000];
bool cmp(int a, int b) { return a > b; }
int main(void) {
  int n, m;
  int i;
  int gs = 1, d1 = 1, d2 = 2;
  ;
  scanf("%d%d", &n, &m);
  for (i = 2; i < 2000000; i++) {
    if (i % 2) {
      gs += d1;
      d1 += 3;
    } else {
      gs += d2;
      d2 += 1;
    }
    if (gs > n) {
      n = i - 1;
      break;
    }
  }
  for (i = 0; i < m; i++) scanf("%d%d", &gs, arr + i);
  sort(arr, arr + m, cmp);
  gs = 0;
  for (i = 0; i < n && i < m; i++) gs += arr[i];
  printf("%d", gs);
  return 0;
}
