#include <bits/stdc++.h>
inline int getInt() {
  int s;
  scanf("%d", &s);
  return s;
}
using namespace std;
int main() {
  int ans[5] = {2, 2, 1, -1, -1};
  int n = getInt();
  printf("%d\n", ans[n - 1]);
  return 0;
}
