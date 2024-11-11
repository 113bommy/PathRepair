#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 1;
const int NEO = 3e5;
int n, u, v, a[MAX], Fmax[2][MAX], Fmin[2][MAX];
int cnt[(NEO << 1) + 1];
long long res;
long long Try(int lef, int rig) {
  if (lef == rig) return 1;
  int mid = (lef + rig) >> 1;
  long long res = Try(lef, mid) + Try(mid + 1, rig);
  Fmin[0][mid] = Fmax[0][mid] = a[mid];
  for (int i = mid - 1; i >= lef; --i) {
    Fmin[0][i] = min(a[i], Fmin[0][i + 1]);
    Fmax[0][i] = max(a[i], Fmax[0][i + 1]);
  }
  Fmin[1][mid + 1] = Fmax[1][mid + 1] = a[mid + 1];
  for (int i = mid + 2; i <= rig; ++i) {
    Fmin[1][i] = min(a[i], Fmin[1][i - 1]);
    Fmax[1][i] = max(a[i], Fmax[1][i - 1]);
  }
  for (int i = lef; i <= mid; ++i) {
    int length = Fmax[0][i] - Fmin[0][i] + 1 - (mid - i + 1);
    if (length > 0 && mid + length <= rig &&
        Fmax[1][mid + length] < Fmax[0][i] &&
        Fmin[1][mid + length] > Fmin[0][i])
      ++res;
  }
  for (int i = mid + 1; i <= rig; ++i) {
    int length = Fmax[1][i] - Fmin[1][i] + 1 - (i - mid);
    if (length > 0 && mid + 1 - length >= lef &&
        Fmax[0][mid + 1 - length] < Fmax[1][i] &&
        Fmin[0][mid + 1 - length] > Fmin[1][i])
      ++res;
  }
  int j = rig, k = rig;
  for (int i = lef; i <= mid; ++i) {
    while (j > mid && Fmin[1][j] < Fmin[0][i]) {
      --cnt[Fmax[1][j] - j + NEO];
      --j;
    }
    while (k > mid && Fmax[1][k] > Fmax[0][i]) {
      ++cnt[Fmax[1][k] - k + NEO];
      --k;
    }
    if (cnt[Fmin[0][i] - i + NEO] > 0) res += cnt[Fmin[0][i] - i + NEO];
  }
  for (int i = mid + 1; i <= rig; ++i) cnt[Fmax[1][i] - i + NEO] = 0;
  j = lef;
  k = lef;
  for (int i = rig; i > mid; --i) {
    while (j <= mid && Fmin[0][j] < Fmin[1][i]) {
      --cnt[Fmax[0][j] + j];
      ++j;
    }
    while (k <= mid && Fmax[0][k] > Fmax[1][i]) {
      ++cnt[Fmax[0][k] + k];
      ++k;
    }
    if (cnt[Fmin[1][i] + i] > 0) res += cnt[Fmin[1][i] + i];
  }
  for (int i = lef; i <= mid; ++i) cnt[Fmax[0][i] + i] = 0;
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> u >> v;
    a[u] = v;
  }
  cout << Try(1, n);
  return 0;
}
