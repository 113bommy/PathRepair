#include <bits/stdc++.h>
using namespace std;
void main2(void) {}
void pre() {}
int n, arr[1000005], ki, ka, ans, cnt1;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  ki = 0;
  ka = 0;
  while (ki < n) {
    ka = ki;
    while (arr[ka] != arr[ka + 1] && ka + 1 < n) {
      ka++;
    }
    ans = max(ans, ka - ki);
    cnt1 = 0;
    if (arr[ki] == arr[ka]) {
      for (int j = ki; j < ka; j++) arr[j] = arr[ki];
    } else {
      for (int j = ki; j < ka; j++)
        if (arr[j] == 1) cnt1++;
      if (arr[ki] == 1) {
        for (int j = ki + 1; j < ka; j++) {
          if (cnt1)
            arr[j] = 1, cnt1--;
          else
            arr[j] = 0;
        }
      } else {
        for (int j = ka - 1; j > ki; j--) {
          if (cnt1)
            arr[j] = 1, cnt1--;
          else
            arr[j] = 0;
        }
      }
    }
    ki++;
  }
  printf("%d\n", ans / 2);
  for (int i = 0; i < n; i++) {
    if (i > 0) printf(" ");
    printf("%d", arr[i]);
  }
  printf("\n");
}
