#include <bits/stdc++.h>
using namespace std;
pair<int, int> Max[3005][3005];
struct ans {
  int a, b, c;
  int i, j, k;
  ans(int _a, int _b, int _c, int _i, int _j, int _k) {
    a = _a;
    b = _b;
    c = _c;
    i = _i;
    j = _j;
    k = _k;
  }
};
bool operator<(const ans &a, const ans &b) {
  if (a.a != b.a)
    return a.a < b.a;
  else if (a.b != b.b)
    return a.b < b.b;
  else
    return a.c < b.c;
}
int main() {
  int n;
  scanf("%d", &n);
  pair<int, int> a[3005];
  memset(Max, -1, sizeof(Max));
  for (int i = 0; i < n; i++) {
    int first;
    scanf("%d", &first);
    a[i] = make_pair((first), (i));
  }
  sort(a, a + n);
  reverse(a, a + n);
  a[n] = make_pair((0), (n));
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      Max[i][j - 1] =
          max(Max[i][j - 2], make_pair((a[j - 1].first - a[j].first), (j)));
    }
  }
  ans aa = ans{-1, -1, -1, 0, 0, 0};
  for (int i = 1; i <= n; i++) {
    for (int j = (i + 1) / 2; j <= i * 2 && i + j <= n; j++) {
      int l = max((i + 1) / 2, (j + 1) / 2), r = min(i * 2, j * 2);
      l += i + j;
      r += i + j;
      l--;
      r--;
      if (l >= n) continue;
      if (r >= n) r = n - 1;
      aa = max(aa, ans(a[i - 1].first - a[i].first,
                       a[i + j - 1].first - a[i + j].first, Max[l][r].first, i,
                       i + j, Max[l][r].second));
    }
  }
  int ans[3005];
  memset(ans, -1, sizeof(ans));
  for (int i = 0; i < aa.i; i++) ans[a[i].second] = 1;
  for (int i = aa.i; i < aa.j; i++) ans[a[i].second] = 2;
  for (int i = aa.j; i < aa.k; i++) ans[a[i].second] = 3;
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  printf("\n");
}
