#include <bits/stdc++.h>
using namespace std;
int n, m, f[100001], ans = 0;
int maxe = 1000000000;
struct bian {
  int x, y, w;
};
struct bian b[1000001];
bool cmp(bian A, bian B) { return A.w < B.w; }
int findd(int k) {
  if (f[k] == k) return k;
  return f[k] = findd(f[k]);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d %d", &b[i].x, &b[i].y, &b[i].w);
  }
  if (m == n - 1) {
    printf("%d", maxe);
    return 0;
  }
  int temp1 = b[1].x, temp2 = b[1].y;
  sort(b + 2, b + 1 + m, cmp);
  int sum = 1;
  bool flag = 0;
  int l = 0, r = maxe;
  while (l < r) {
    int mid = (l + r) / 2;
    for (int i = 1; i <= n; i++) {
      f[i] = i;
    }
    int sum = 0;
    bool flag = 0;
    for (int i = 2; sum < n - 1; i++) {
      if (mid <= b[i].w) {
        int t1 = findd(b[1].x), t2 = findd(b[1].y);
        if (t1 != t2) {
          flag = 1;
        } else
          flag = 0;
        break;
      }
      int t1 = findd(b[i].x), t2 = findd(b[i].y);
      if (t1 != t2) {
        sum++;
        f[t1] = t2;
      }
    }
    if (flag) {
      ans = max(ans, mid);
      l = mid + 1;
    } else
      r = mid;
  }
  cout << ans;
  return 0;
}
