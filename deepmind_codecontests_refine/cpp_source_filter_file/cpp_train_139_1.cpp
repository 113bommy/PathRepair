#include <bits/stdc++.h>
using namespace std;
void solve() {
  int i, j, n, ct = 0;
  cin >> n;
  int h[n], g[n];
  for (i = 0; i < n; i++) cin >> h[i] >> g[i];
  sort(h, h + n);
  sort(g, g + n);
  i = 0;
  j = 0;
  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (h[i] == g[j]) ct++;
    }
  }
  cout << ct;
}
int main() {
  auto start = chrono::high_resolution_clock::now();
  ios_base::sync_with_stdio(false);
  int t = 1;
  while (t--) solve();
  auto stop = chrono::high_resolution_clock::now();
  auto durn = chrono::duration_cast<chrono::microseconds>(stop - start);
}
