#include <bits/stdc++.h>
const int MX = (1 << 12), INF = 2000000000;
using namespace std;
int a[MX], need[MX], must[MX], now[MX], add[MX], ans;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int len(1 << (n + 1));
  need[1] = INF;
  for (int i(2); i < len; ++i) {
    cin >> a[i];
    need[i] = INF;
  }
  for (int i(len - 1); i > 1; --i)
    must[i >> 1] = max(must[i >> 1], must[i] + a[i]);
  for (int i(1); i < (len >> 1); ++i)
    now[i << 1] = now[i] + a[i << 1],
             now[(i << 1) | 1] = now[i] + a[(i << 1) | 1];
  for (int i(len >> 1); i < len; ++i) need[i] = must[1] - now[i];
  for (int i(len - 1); i > 1; --i) need[i >> 1] = min(need[i >> 1], need[i]);
  for (int i(1); i < len; ++i) {
    ans += need[i] - add[i];
    add[i << 1] = add[(i << 1) | 1] = need[i] + add[i];
  }
  cout << ans;
}
