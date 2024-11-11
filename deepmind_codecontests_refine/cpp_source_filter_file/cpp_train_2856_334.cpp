#include <bits/stdc++.h>
using namespace std;
char ans[20] = "0000011111001010";
char ans2[20] = "1111100000110101";
int main() {
  int n;
  scanf("%d", &n);
  printf("%c\n", ans2[n - 1]);
  return 0;
}
