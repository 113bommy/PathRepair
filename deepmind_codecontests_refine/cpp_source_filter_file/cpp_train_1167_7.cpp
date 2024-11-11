#include <bits/stdc++.h>
using namespace std;
struct point {
  int x, y;
};
bool cmp(point A, point B) {
  if (A.x != B.x) return A.x < B.x;
  return A.x < B.y;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    struct point ar[1003];
    for (int i = 0; i < n; i++) {
      scanf("%d %d", &ar[i].x, &ar[i].y);
    }
    sort(ar, ar + n, cmp);
    int r, u, f = 1;
    string res = "";
    r = ar[0].x;
    u = ar[0].y;
    for (int j = 0; j < r; j++) res += 'R';
    for (int j = 0; j < u; j++) res += 'U';
    for (int i = 1; i < n; i++) {
      r = ar[i].x - ar[i - 1].x;
      u = ar[i].y - ar[i - 1].y;
      if (r < 0 or u < 0) {
        f = 0;
        break;
      }
      for (int j = 0; j < r; j++) res += 'R';
      for (int j = 0; j < u; j++) res += 'U';
    }
    if (f) {
      printf("YES\n");
      cout << res << '\n';
    } else
      printf("NO\n");
  }
  return 0;
}
