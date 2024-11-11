#include <bits/stdc++.h>
using namespace std;
char s[301010];
int xx[] = {0, 1, 0, -1};
int yy[] = {1, 0, -1, 0};
int main() {
  long long int l, r, mid;
  long long int n, i, j, t, q;
  long long int x1, y1;
  long long int x2, y2;
  scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
  scanf("%lld", &n);
  scanf("%s", s);
  long long int Mx = -1, sm;
  long long int tx, ty;
  l = 0, r = 100000000000000;
  Mx = r;
  while (l <= r) {
    tx = x1, ty = y1;
    mid = (l + r) / 2;
    for (i = 0; s[i]; i++) {
      if (s[i] == 'U') {
        ty += mid / n + ((mid % n) > i);
      } else if (s[i] == 'D') {
        ty -= mid / n + ((mid % n) > i);
      } else if (s[i] == 'L') {
        tx -= mid / n + ((mid % n) > i);
      } else {
        tx += mid / n + ((mid % n) > i);
      }
    }
    sm = abs(tx - x2) + abs(ty - y2);
    if (sm > mid) {
      l = mid + 1;
    } else {
      Mx = min(Mx, mid);
      r = mid - 1;
    }
  }
  printf("%lld\n", Mx == 100000000000000 ? -1 : Mx);
}
