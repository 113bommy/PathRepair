#include <bits/stdc++.h>
using namespace std;
int n, a, b;
int main() {
  scanf("%d%d%d", &n, &a, &b);
  a--;
  int ans = (a + b + n) % n;
  printf("%d\n", ++ans);
  return 0;
}
