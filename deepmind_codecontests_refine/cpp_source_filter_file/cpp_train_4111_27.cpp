#include <bits/stdc++.h>
using namespace std;
int read() {
  int w = 1, res = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') res = res * 10 + ch - '0', ch = getchar();
  return w * res;
}
int n, mons[300100], maxx[300010], minn[300010], rec[600010];
long long ans = 0;
void merge(int l, int r) {
  if (l == r) {
    ans++;
    return;
  }
  int mid = (l + r) >> 1;
  merge(l, mid);
  merge(mid + 1, r);
  maxx[mid] = minn[mid] = mons[mid];
  maxx[mid + 1] = minn[mid + 1] = mons[mid + 1];
  for (int i = mid - 1; i >= l; i--) {
    maxx[i] = max(maxx[i + 1], mons[i]);
    minn[i] = min(minn[i + 1], mons[i]);
  }
  for (int i = mid + 2; i <= r; i++) {
    maxx[i] = max(maxx[i - 1], mons[i]);
    minn[i] = min(minn[i - 1], mons[i]);
  }
  for (int i = mid; i >= l; i--) {
    int j = maxx[i] - minn[i] + i;
    if (j <= r && j > mid && maxx[j] < maxx[i] && minn[i] < minn[j]) ans++;
  }
  for (int i = mid + 1; i <= r; i++) {
    int j = maxx[i] + minn[i];
    if (j <= mid && j >= l && maxx[j] < maxx[i] && minn[i] < minn[j]) ans++;
  }
  int j = mid + 1, k = mid + 1;
  for (int i = mid; i >= l; i--) {
    while (j <= r && minn[j] > minn[i]) {
      rec[maxx[j] - j + n]++;
      j++;
    }
    while (k < j && maxx[k] < maxx[i]) {
      rec[maxx[k] - k + n]--;
      k++;
    }
    ans += 1ll * rec[minn[i] - i + n];
  }
  while (k < j) {
    rec[maxx[k] - k + n]--;
    k++;
  }
  j = mid, k = mid;
  for (int i = mid + 1; i <= r; i++) {
    while (j >= l && minn[j] > minn[i]) {
      rec[maxx[j] + j]++;
      j--;
    }
    while (k > j && maxx[k] < maxx[i]) {
      rec[maxx[k] + k]--;
      k--;
    }
    ans += 1ll * rec[minn[i] + i];
  }
  while (k > j) {
    rec[maxx[k] + k]--;
    k--;
  }
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    mons[x] = y;
  }
  merge(1, n);
  printf("%d", ans);
  return 0;
}
