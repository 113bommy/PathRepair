#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000000")
using namespace std;
int chng[11], swp[11], tw[20], n, m, k, arr[1001][1001], nw[6][6];
int mask[6][6];
long long ans = 0;
void bt(int r, int c, int use) {
  if (use > k + 1) return;
  if (c == m) {
    bt(r + 1, 0, use);
    return;
  }
  if (r == n) {
    memset((swp), (-1), sizeof(swp)), memset((chng), (-1), sizeof(chng));
    use--;
    long long ret = 1, tot = k;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (arr[i][j]) {
          if (chng[arr[i][j]] == -1) {
            if (~swp[nw[i][j]]) return;
            swp[nw[i][j]] = arr[i][j];
            chng[arr[i][j]] = nw[i][j];
            tot--, use--;
          }
          if (chng[arr[i][j]] != nw[i][j]) return;
        }
      }
    for (int i = 0; i < use; i++) ret = (ret * (tot - i)) % 1000000007;
    ans = (ans + ret) % 1000000007;
    return;
  }
  int Tmask = 0;
  if (r) Tmask |= mask[r - 1][c];
  if (c) Tmask |= mask[r][c - 1];
  for (int i = 1; i < use + 1; i++)
    if (!(Tmask & tw[i])) {
      nw[r][c] = i;
      mask[r][c] = Tmask | tw[i];
      bt(r, c + 1, max(i + 1, use));
      mask[r][c] = Tmask;
    }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 0; i < 20; i++) tw[i] = 1 << i;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> arr[i][j];
  if (n + m - 1 > k) {
    cout << 0;
    return 0;
  }
  bt(0, 0, 1);
  cout << ans;
  return 0;
}
