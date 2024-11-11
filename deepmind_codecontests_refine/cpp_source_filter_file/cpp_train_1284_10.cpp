#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:267435456")
using namespace std;
int n, k, t, i, j, c, x, y, zz;
int z[22][22];
long long h[200005];
bool cmp(long long a, long long b) { return a < b; }
void go(int sum, int cur, bool um[22], bool uw[22]) {
  if (c > 200000) return;
  if (cur > n) return;
  for (int j = cur; j <= n; j++) {
    if (c > 200000) return;
    if (!um[j]) {
      um[j] = true;
      for (int i = 1; i <= n; i++) {
        if (c > 200000) return;
        if (!uw[i] && z[j][i] > 0) {
          uw[i] = true;
          h[c++] = sum + z[j][i];
          go(sum + z[j][i], cur + 1, um, uw);
          uw[i] = false;
        }
      }
      um[j] = false;
    }
  }
}
int main() {
  cin >> n >> k >> t;
  for (i = 0; i < k; i++) {
    cin >> x >> y >> zz;
    z[x][y] = zz;
  }
  bool um[22], uw[22];
  memset(uw, 0, sizeof(uw));
  memset(um, 0, sizeof(um));
  h[c++] = 0;
  go(0, 1, um, uw);
  sort(h + 1, h + c + 1, cmp);
  cout << h[t];
  return 0;
}
