#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[5], k[5] = {1, 1, 2, 7, 4}, min;
  for (int i = 0; i < 5; i++) {
    scanf("%d", &a[i]);
  }
  min = 100000;
  for (int i = 0; i < 5; i++) {
    if (a[i] / k[i] < min) {
      min = a[i] / k[i];
    }
  }
  printf("%d", min);
}
