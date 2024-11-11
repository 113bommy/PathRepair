#include <bits/stdc++.h>
using namespace std;
int ret[20000];
int main() {
  int a;
  ret[1] = 1;
  ret[2] = 13;
  for (int i = 3; i <= 18257; i++) ret[i] = ret[i - 1] + 6 * (i + 1);
  scanf("%d", &a);
  printf("%d\n", ret[a]);
  return 0;
}
