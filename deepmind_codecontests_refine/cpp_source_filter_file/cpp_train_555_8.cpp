#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int num;
int a[N][N];
int main() {
  scanf("%d", &num);
  for (int i(1); i <= (100); ++i) {
    int s = 0;
    for (int j = 1; j <= i && s <= num; ++j) {
      num -= s;
      ++s;
      a[i][j] = a[j][i] = 1;
    }
  }
  puts("100");
  for (int i(1); i <= (100); ++i) {
    for (int j(1); j <= (100); ++j) putchar(a[i][j] + 48);
    putchar(10);
  }
  return 0;
}
