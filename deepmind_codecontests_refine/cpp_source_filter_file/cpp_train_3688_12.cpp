#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  vector<int> d(n);
  for (int i = 0; i < (int)(n - 1); ++i) scanf("%d", &d[i]);
  int a, b;
  scanf("%d%d", &a, &b);
  int res = 0;
  for (int i = a - 1; i < b; i++) res += d[i];
  printf("%d\n", res);
  return 0;
}
