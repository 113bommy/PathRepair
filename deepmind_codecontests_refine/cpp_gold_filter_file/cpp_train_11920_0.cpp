#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r = 0, x, y, act = 1;
  scanf("%d", &n);
  vector<int> v(n);
  for (int i = (0), _i = (n); i < _i; ++i) scanf("%d", &v[i]);
  for (int i = (0), _i = (n); i < _i; ++i) {
    if (v[i] != act) {
      int act2 = v[i];
      y = i;
      x = act;
      r++;
      while (y < n) {
        if (v[y] != act2) break;
        y++;
        act2--;
        act++;
      }
      i = y;
    }
    act++;
  }
  if (r == 1)
    printf("%d %d\n", x, y);
  else
    printf("0 0\n");
}
