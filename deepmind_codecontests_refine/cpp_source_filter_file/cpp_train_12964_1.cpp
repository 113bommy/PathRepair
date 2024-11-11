#include <bits/stdc++.h>
using namespace std;
const int maxn = 2E5 + 20;
int n, a[maxn], len[4], tot, cur, l[4];
int acc[maxn];
bool bo[maxn];
int Judge(int i) {
  if (i < 1 || i > n) return 1;
  int f1, f2;
  f1 = f2 = 1;
  if (i & 1) {
    if (i != 1 && a[i] >= a[i - 1]) f1 = 0;
    if (i != n && a[i] >= a[i + 1]) f1 = 0;
    return f1 && f2;
  } else {
    if (i != 1 && a[i] <= a[i - 1]) f1 = 0;
    if (i != n && a[i] <= a[i + 1]) f1 = 0;
    return f1 && f2;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) acc[i] = 1;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) {
    int t = Judge(i);
    if (!t) {
      ++tot;
      acc[i] = 0;
      bo[i] = 1;
      if (tot > 6) {
        cout << 0;
        return 0;
      }
    }
    acc[i] += acc[i - 1];
  }
  int ans = 0;
  for (int i = 1; i < n; i++)
    if (bo[i] || (i > 1 && bo[i - 1]) || (i < n && bo[i + 1])) {
      for (int j = 1; j <= n; j++)
        if (i != j) {
          if (bo[i] && bo[j] && i > j) continue;
          int x = min(i, j), y = max(i, j);
          if (x > 2 && acc[x - 2] < x - 2) continue;
          if (y < n - 1 && acc[n] - acc[y + 1] < n - y - 1) continue;
          if (y - x - 1 > 2 && acc[y - 2] - acc[x + 1] < y - x - 3) continue;
          swap(a[y], a[x]);
          int add = 1;
          for (int l = x - 1; l <= x + 1; l++)
            if (!Judge(l)) add = 0;
          for (int l = y - 1; l <= y + 1; l++)
            if (!Judge(l)) add = 0;
          ans += add;
          swap(a[y], a[x]);
        }
    }
  cout << ans;
  return 0;
}
