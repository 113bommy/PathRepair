#include <bits/stdc++.h>
using namespace std;
struct point {
  long long x, y;
};
long long s[200010], ans, a[200010], mx, g[200010];
point sta[200010], p[200010];
int top, n;
point operator-(point a, point b) { return (point){a.x - b.x, a.y - b.y}; }
bool cmp(point a, point b) {
  if (a.x != b.x)
    return a.x < b.x;
  else
    return a.y < b.y;
}
long long cross(point a, point b) { return a.x * b.y - a.y * b.x; }
void solve(int T) {
  sort(p + 1, p + n + 1, cmp);
  top = 0;
  for (int i = 1; i <= n; i++) {
    while (top >= 2 && cross(sta[top] - sta[top - 1], p[i] - sta[top - 1]) >= 0)
      top--;
    sta[++top] = p[i];
  }
  for (int i = 1; i <= n; i++) {
    int lef = 1, righ = top, ch;
    while (righ - lef > 3) {
      int tl = lef + (righ - lef) / 3, tr = righ - (righ - lef) / 3;
      if (sta[tl].x * i + sta[tl].y > sta[tr].x * i + sta[tr].y)
        righ = tl;
      else
        lef = tr;
    }
    ch = lef;
    for (int j = lef + 1; j <= righ; j++)
      if (sta[j].x * i + sta[j].y > sta[ch].x * i + sta[ch].y) ch = j;
    if (T == 1)
      mx = max(mx, sta[ch].x * i + sta[ch].y - s[i]);
    else
      mx = max(mx, sta[ch].x * i + sta[ch].y - s[i - 1]);
  }
}
int main() {
  mx = -2147483647;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &a[i]);
    ans += a[i] * i;
    s[i] = s[i - 1] + a[i];
    p[i] = (point){a[i], s[i] - a[i] * i};
  }
  solve(1);
  for (int i = 1; i <= n; i++) p[i] = (point){a[i], s[i] - a[i] * (i + 1)};
  solve(2);
  printf("%I64d\n", ans + mx);
  return 0;
}
