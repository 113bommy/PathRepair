#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int tmp, pos = 1;
  long long res = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d", &tmp);
    if (tmp >= pos)
      res += (tmp - pos);
    else
      res += (n - pos + tmp);
    pos = tmp;
  }
  printf("%d\n", res);
}
