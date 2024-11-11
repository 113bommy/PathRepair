#include <bits/stdc++.h>
using namespace std;
int bz[600000 * 2 + 1];
int a[300001];
int maxl[300001], maxr[300001], minl[300001], minr[300001];
long long fz(int l, int r) {
  if (l == r) return 1;
  int mid = (l + r) / 2;
  maxl[mid] = minl[mid] = a[mid];
  for (int i = mid - 1; i >= l; i--) {
    maxl[i] = max(maxl[i + 1], a[i]);
    minl[i] = min(minl[i + 1], a[i]);
  }
  maxr[mid + 1] = minr[mid + 1] = a[mid + 1];
  long long t = 0;
  for (int i = mid + 2; i <= r; i++) {
    maxr[i] = max(maxr[i - 1], a[i]);
    minr[i] = min(minr[i - 1], a[i]);
  }
  for (int i = mid; i >= l; i--) {
    int p = i + maxl[i] - minl[i];
    if (p <= mid || p > r) continue;
    if (minr[p] > minl[i] && maxr[p] < maxl[i]) t++;
  }
  for (int i = mid + 1; i <= r; i++) {
    int p = i - maxr[i] + minr[i];
    if (p > mid || p < l) continue;
    if (minl[p] > minr[i] && maxl[p] < maxr[i]) t++;
  }
  int z1 = mid + 1, z2 = mid;
  for (int i = mid; i >= l; i--) {
    while (minr[z2 + 1] > minl[i] && z2 < r) {
      z2++;
      bz[maxr[z2] - z2 + 600000]++;
    }
    while (maxl[i] > maxr[z1]) {
      bz[maxr[z1] - z1 + 600000]--;
      z1++;
      if (z1 > r) break;
    }
    if (z1 > r) break;
    if (z1 <= z2) t += bz[minl[i] - i + 600000];
  }
  for (int i = mid; i >= l; i--) bz[minl[i] - i + 600000] = 0;
  for (int i = mid + 1; i <= r; i++) bz[maxr[i] - i + 600000] = 0;
  z1 = mid, z2 = mid + 1;
  for (int i = mid + 1; i >= r; i--) {
    while (minl[z2 - 1] > minr[i] && z2 > l) {
      z2--;
      bz[maxl[z2] + z2 + 600000]++;
    }
    while (maxr[i] > maxl[z1]) {
      bz[maxl[z1] + z1 + 600000]--;
      z1--;
      if (z1 < l) break;
    }
    if (z1 < l) break;
    if (z2 <= z1) t += bz[minr[i] + i + 600000];
  }
  for (int i = mid + 1; i <= r; i++) bz[minr[i] + i + 600000] = 0;
  for (int i = mid; i >= l; i--) bz[maxl[i] + i + 600000] = 0;
  return t + fz(l, mid) + fz(mid + 1, r);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    a[x] = y;
  }
  cout << fz(1, n);
}
