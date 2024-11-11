#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int maxn = 2e5 + 5;
bool vis[2][maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  memset(vis, 0, sizeof(vis));
  int n, q, l, r;
  int s = 0;
  cout << n << q;
  while (q--) {
    cin >> l >> r;
    l--;
    if (vis[l][r]) {
      if (vis[l ^ 1][r - 1]) {
        s--;
      }
      if (vis[l ^ 1][r]) {
        s--;
      }
      if (vis[l ^ 1][r + 1]) {
        s--;
      }
    } else {
      if (vis[l ^ 1][r - 1]) {
        s++;
      }
      if (vis[l ^ 1][r]) {
        s++;
      }
      if (vis[l ^ 1][r + 1]) {
        s++;
      }
    }
    vis[l][r] ^= 1;
    if (s != 0) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
    }
  }
  return 0;
}
