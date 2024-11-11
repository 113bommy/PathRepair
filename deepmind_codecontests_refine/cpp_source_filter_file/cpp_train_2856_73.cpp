#include <bits/stdc++.h>
using namespace std;
int res[22] = {0, 1, 0, 0, 0, 0, 0, 0, 1};
int main() {
  res[9] = 1;
  res[10] = 1;
  res[11] = 0;
  res[12] = 0;
  res[13] = 1;
  res[14] = 0;
  res[15] = 1;
  res[16] = 0;
  int n;
  scanf("%d", &n);
  printf("%d\n", res[n]);
}
