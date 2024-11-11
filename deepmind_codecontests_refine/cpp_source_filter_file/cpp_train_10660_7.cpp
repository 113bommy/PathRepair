#include <bits/stdc++.h>
using namespace std;
const int N = 150011, M = 400;
int a[N], b[N], limit[N], num[N], vis[N];
int blockSum[M], blockMin[M], blockDelta[M];
int n, m, h, k, size;
struct xy {
  int value, index;
};
xy tmp[N];
void inti() {
  cin >> n >> m >> h;
  for (int i = 0; i < m; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> a[i];
}
int findLimitStation(int a) {
  int x = 0, y = m, mid;
  while (x < y) {
    mid = (x + y) >> 1;
    if (a + b[mid] >= h)
      y = mid;
    else
      x = mid + 1;
  }
  return x;
}
int cmp(xy a, xy b) { return (a.value < b.value) ? 1 : 0; }
void Insert(int x) {
  int i, j, st = 0, cnt = 0;
  for (i = 0; i < k; i++) {
    if (x < st + size) break;
    cnt += blockSum[i];
    st += size;
  }
  blockSum[i]++;
  for (j = i + 1; j < k; j++) blockDelta[j]--;
  blockMin[i] = n + 1;
  for (j = st; j < st + size; j++)
    if (vis[j]) {
      cnt += (j < x);
      limit[j] += blockDelta[i] - (j > x);
      blockMin[i] = min(blockMin[i], limit[j]);
    }
  limit[x] -= cnt;
  blockMin[i] = min(blockMin[i], limit[x]);
  blockDelta[i] = 0;
  vis[x] = 1;
}
void Delete(int x) {
  int i, j;
  i = x / size;
  vis[x] = 0;
  blockSum[i]--;
  for (j = i + 1; j < k; j++) blockDelta[j]++;
  blockMin[i] = n + 1;
  for (j = i * size; j < (i + 1) * size; j++)
    if (vis[j]) {
      limit[j] += blockDelta[i] + (j > x);
      blockMin[i] = min(blockMin[i], limit[j]);
    }
  blockDelta[i] = 0;
}
int check() {
  for (int i = 0; i < k; i++)
    if (blockSum[i] > 0)
      if (blockMin[i] + blockDelta[i] < 0) return 0;
  return 1;
}
void work() {
  sort(b, b + m);
  b[m] = h;
  int i;
  for (i = 0; i < n; i++) {
    tmp[i].index = i;
    tmp[i].value = a[i];
  }
  sort(tmp, tmp + n, cmp);
  for (i = 0; i < n; i++) num[tmp[i].index] = i;
  for (i = 0; i < n; i++) limit[i] = m - findLimitStation(tmp[i].value) - 1;
  size = (int)sqrt(n + 0.0);
  k = (n - 1) / size + 1;
  for (i = 0; i < m; i++) Insert(num[i]);
  int ans = check();
  for (i = m; i < n; i++) {
    Delete(num[i - m]);
    Insert(num[i]);
    ans += check();
  }
  cout << ans << endl;
}
int main() {
  inti();
  work();
}
