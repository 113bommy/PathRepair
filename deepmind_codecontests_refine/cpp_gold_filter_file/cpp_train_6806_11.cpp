#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; i += 1) cin >> a[i];
  int chosen = -1;
  for (int bit = 30; bit >= 0; bit -= 1) {
    bool all = true;
    bool some = false;
    for (int i = 0; i < n; i += 1) {
      all &= (((1 << bit) & a[i]) > 0);
      some |= (((1 << bit) & a[i]) > 0);
    }
    if (not all and some) {
      chosen = bit;
      break;
    }
  }
  assert(chosen >= 0);
  vector<int> mark(n, 0);
  for (int i = 0; i < n; i += 1) {
    if ((a[i] & (1 << chosen)) > 0) {
      mark[i] = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i += 1) {
    if (not mark[i]) continue;
    int maxx = 0;
    for (int j = i + 1; j < n and mark[j] == 0; j += 1) {
      maxx = max(maxx, a[j]);
      ans = max(ans, maxx xor a[i]);
    }
    maxx = 0;
    for (int j = i - 1; j >= 0 and mark[j] == 0; j -= 1) {
      maxx = max(maxx, a[j]);
      ans = max(ans, maxx xor a[i]);
    }
  }
  cout << ans << "\n";
}
