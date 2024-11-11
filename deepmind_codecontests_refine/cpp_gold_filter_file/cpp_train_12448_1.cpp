#include <bits/stdc++.h>
using namespace std;
const int sz = 1e6 + 100;
bitset<sz> b;
int p[sz], len[sz];
bool used[sz];
int main() {
  ios_base::sync_with_stdio(false);
  int n, k, sum = 0, cnt = 0, i;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  b[0] = 1;
  for (i = 0; i < n; i++)
    if (!used[i]) {
      int v = i, cursum = 0;
      while (!used[v]) {
        cursum++;
        used[v] = true;
        v = p[v];
      }
      len[cursum]++;
      sum += cursum >> 1;
      cnt += cursum & 1;
    }
  for (i = 1; i <= n; i++)
    if (len[i] != 0) {
      int j = 1;
      while (len[i] != 0) {
        j = min(len[i], j);
        int cur = j * i;
        b |= b << cur;
        len[i] -= j;
        j <<= 1;
      }
    }
  int ans = k;
  if (!b[k]) ans++;
  cout << ans << " ";
  ans = 2 * min(k, sum);
  k -= min(k, sum);
  ans += min(k, cnt);
  cout << ans << endl;
  return 0;
}
