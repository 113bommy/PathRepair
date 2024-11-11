#include <bits/stdc++.h>
using namespace std;
int n, m;
int A[200006];
pair<int, int> poi[200006];
int pmx[200006], pmn[200006], smx[200006], smn[200006];
bool chk(int l) {
  int las = 1;
  for (int i = (1), iend = (n); i <= iend; ++i) {
    while (poi[i].first - poi[las].first > l) ++las;
    int mx = max(pmx[las - 1], smx[i + 1]), mn = min(pmn[las - 1], smn[i + 1]);
    if (mx - mn <= l) return true;
  }
  return false;
}
void solve() {
  cin >> n;
  for (int i = (1), iend = (n); i <= iend; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = x + y, y = y + y - x;
    poi[i] = make_pair(x, y);
  }
  sort(poi + 1, poi + 1 + n);
  pmx[0] = -0x7f7f7f7f, pmn[0] = 0x7f7f7f7f;
  for (int i = (1), iend = (n); i <= iend; ++i)
    pmx[i] = max(pmx[i - 1], poi[i].second),
    pmn[i] = min(pmn[i - 1], poi[i].second);
  smx[n + 1] = -0x7f7f7f7f, smn[n + 1] = 0x7f7f7f7f;
  for (int i = (n), iend = (1); i >= iend; --i)
    smx[i] = max(smx[i + 1], poi[i].second),
    smn[i] = min(smn[i + 1], poi[i].second);
  long long l = 1, r = 2e9;
  while (l <= r) {
    long long mid = l + r >> 1;
    if (chk(mid))
      r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%.8lf\n", 1. * l / 2);
}
signed main() { solve(); }
