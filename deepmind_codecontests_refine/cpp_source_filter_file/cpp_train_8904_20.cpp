#include <bits/stdc++.h>
using namespace std;
char buff[(int)2e6 + 17];
const long long inf = (long long)1e9 + 7ll;
const int maxn = (int)1e6 + 17;
int q;
bool read() {
  if (scanf("%d", &q) != 1) return false;
  return true;
}
void solve() {
  for (int tt = 0; tt < q; ++tt) {
    int h, w;
    scanf("%d %d", &h, &w);
    vector<vector<int> > pic(h);
    for (int i = 0; i < h; ++i) {
      pic[i].resize(w);
      for (int j = 0; j < w; ++j) scanf("%d", &pic[i][j]);
    }
    int m = h / 2, cnt = 0;
    for (int j = 0; j < w; ++j) cnt += abs(pic[m][j] - pic[m + 1][j]);
    if (cnt > 21 * w)
      printf("YES\n");
    else
      printf("NO\n");
  }
}
int main() {
  while (read()) solve();
  return 0;
}
