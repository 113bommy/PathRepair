#include <bits/stdc++.h>
using namespace std;
struct seg {
  int l, r;
} p[200090];
bool cmp(seg a, seg b) { return a.r < b.r; }
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, w;
    scanf("%d%d", &x, &w);
    p[i].l = x - w;
    p[i].r = x + w;
  }
  sort(p, p + n, cmp);
  int R = -2000000009;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (p[i].l >= R) {
      ans++;
      R = max(R, p[i].r);
    }
  }
  cout << ans << endl;
}
