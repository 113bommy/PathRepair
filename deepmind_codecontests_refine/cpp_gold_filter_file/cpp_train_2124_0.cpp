#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  if (n % 2) {
    cout << -1;
    return 0;
  }
  for (int h = 0; h < n; h++) {
    for (int row = 0; row < n; row++) {
      for (int col = 0; col < n / 2; col++) {
        if ((h + row / 2 + col) % 2) {
          printf("bb");
        } else {
          printf("ww");
        }
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
