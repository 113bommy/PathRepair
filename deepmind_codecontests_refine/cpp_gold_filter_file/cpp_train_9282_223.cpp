#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  scanf("%d%d%d", &x, &y, &z);
  if (y >= x && z >= x)
    puts("Yes");
  else
    puts("No");
  return 0;
}
