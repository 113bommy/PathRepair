#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int a[n], b[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  sort(a, a + n);
  sort(b, b + n);
  int index1 = n - 1;
  int index2 = n - 1;
  long long int ans1 = 0;
  long long int ans2 = 0;
  int turn = 1;
  while (index1 >= 0 || index2 >= 0) {
    if (turn == 1) {
      if (index1 < 0) {
        index2--;
      } else {
        if (index2 < 0) {
          ans1 += a[index1--];
        } else {
          if (a[index1] >= b[index2]) {
            ans1 += a[index1--];
          } else {
            index2--;
          }
        }
      }
      turn = 2;
    } else {
      if (index2 < 0) {
        index1--;
      } else {
        if (index1 < 0) {
          ans2 += b[index2--];
        } else {
          if (b[index2] >= a[index1]) {
            ans2 += b[index2--];
          } else {
            index1--;
          }
        }
      }
      turn = 1;
    }
  }
  printf("%lld\n", ans1 - ans2);
}
