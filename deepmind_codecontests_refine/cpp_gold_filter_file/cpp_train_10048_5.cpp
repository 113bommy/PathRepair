#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void smin(T &a, T b) {
  if (a > b) a = b;
}
int n;
int first[100010], second[100010], nn;
int min1[100010], min2[100010], max1[100010], max2[100010];
int id[100010];
int cmp(int u, int v) {
  if (first[u] != first[v]) return first[u] < first[v];
  return second[u] < second[v];
}
int can(long long mid) {
  for (int i = 0, j = 0; i < n; i++)
    if (first[id[i]] <= 0) {
      while (j < n && ((long long)(first[id[i]] - first[id[j]]) *
                       (first[id[i]] - first[id[j]])) <= mid)
        j++;
      int miny = min(min1[i], min2[j]), maxy = max(max1[i], max2[j]);
      if (miny > maxy) return 1;
      if (((long long)(maxy - miny) * (maxy - miny)) <= mid &&
          max(((long long)(first[id[i]]) * (first[id[i]])),
              ((long long)(first[id[j - 1]]) * (first[id[j - 1]]))) +
                  max(((long long)(maxy) * (maxy)),
                      ((long long)(miny) * (miny))) <=
              mid)
        return 1;
    }
  return 0;
}
long long solve() {
  for (int i = 0; i < n; i++) id[i] = i;
  sort(id, id + n, cmp);
  min1[0] = 0x3f3f3f3f;
  max1[0] = -0x3f3f3f3f;
  for (int i = 1; i < n; i++) {
    min1[i] = min(min1[i - 1], second[id[i - 1]]);
    max1[i] = max(max1[i - 1], second[id[i - 1]]);
  }
  min2[n] = 0x3f3f3f3f, max2[n] = -0x3f3f3f3f;
  for (int i = n - 1; i >= 0; i--) {
    min2[i] = min(min2[i + 1], second[id[i]]);
    max2[i] = max(max2[i + 1], second[id[i]]);
  }
  long long st = -1, ed = 1e18, mid;
  while (ed - st > 1) {
    mid = (st + ed) >> 1;
    if (can(mid))
      ed = mid;
    else
      st = mid;
  }
  return ed;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d%d", first + i, second + i);
  long long ans = solve();
  for (int i = 0; i < n; i++) first[i] = -first[i];
  smin(ans, solve());
  for (int i = 0; i < n; i++) second[i] = -second[i];
  smin(ans, solve());
  for (int i = 0; i < n; i++) first[i] = -first[i];
  smin(ans, solve());
  for (int i = 0; i < n; i++) second[i] = -second[i];
  for (int i = 0; i < n; i++) swap(first[i], second[i]);
  smin(ans, solve());
  for (int i = 0; i < n; i++) first[i] = -first[i];
  smin(ans, solve());
  for (int i = 0; i < n; i++) second[i] = -second[i];
  smin(ans, solve());
  for (int i = 0; i < n; i++) first[i] = -first[i];
  smin(ans, solve());
  cout << ans << endl;
  return 0;
}
