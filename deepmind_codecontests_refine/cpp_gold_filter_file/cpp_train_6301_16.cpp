#include <bits/stdc++.h>
using namespace std;
string second;
int first = 0, n;
int nxt(int x) {
  int z = x + 1;
  while (z < n) {
    if (second[z] == '0') {
      break;
    }
    z++;
  }
  return z;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int k;
  cin >> n >> k;
  cin >> second;
  int l = 0, r = 0;
  int ans = n;
  int ch = 0, first = 0;
  l = nxt(-1);
  r = l;
  for (int i = 0; i < k; i++) r = nxt(r);
  while (r < n) {
    while (max(first - l, r - first) > max(nxt(first) - l, r - nxt(first))) {
      first = nxt(first);
    }
    ans = min(ans, max(first - l, r - first));
    l = nxt(l);
    r = nxt(r);
  }
  cout << ans;
}
