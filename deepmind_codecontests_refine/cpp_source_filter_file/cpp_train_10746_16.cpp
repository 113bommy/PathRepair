#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 4e5 + 10;
struct nn {
  int x;
  int b;
} aa[N];
int sum[2][N];
int ans;
bool cmp(nn x, nn y) { return x.b < y.b; }
int main() {
  std::ios::sync_with_stdio(0);
  while (cin >> n) {
    for (int i = (1); i < (n + 1); i++) cin >> aa[i].x;
    aa[n + 1].b = 1e8;
    ans = 0;
    for (int _ = (0); _ < (20); _++) {
      int tt = (1 << _) - 1;
      for (int i = (1); i < (n + 1); i++) aa[i].b = aa[i].x & tt;
      sort(aa + 1, aa + 1 + n, cmp);
      sum[0][0] = sum[1][0] = 0;
      for (int i = (1); i < (n + 1); i++) {
        sum[1][i] = sum[1][i - 1];
        if (aa[i].x >> _ & 1) sum[1][i]++;
        sum[0][i] = i - sum[1][i];
      }
      sum[1][n + 1] = sum[1][n];
      sum[0][n + 1] = sum[0][n];
      long long kk = 0;
      for (int i = (1); i < (n + 1); i++) {
        int l, r;
        l = 1;
        r = n + 1;
        while (l != r) {
          int mid = (l + r) >> 1;
          if (aa[i].b + aa[mid].b > tt)
            r = mid;
          else
            l = mid + 1;
        }
        int dd = aa[i].x >> _ & 1;
        if (dd) {
          kk += sum[0][l - 1];
          kk += sum[1][n] - sum[1][l - 1];
          if (i >= l) kk--;
        } else {
          kk += sum[1][l - 1];
          kk += sum[0][n] - sum[0][l - 1];
          if (i >= l) kk--;
        }
      }
      kk /= 2;
      ans += (kk & 1) << _;
    }
    cout << ans << '\n';
  }
  return 0;
}
