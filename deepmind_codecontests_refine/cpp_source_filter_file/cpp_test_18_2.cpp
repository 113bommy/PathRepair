#include <bits/stdc++.h>
using namespace std;
int const N = 1e6 + 5;
bitset<N> v, viz;
int n, d;
int next(int i) { return (i + n - d) % n; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0x0);
  cout.tie(0x0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> d;
    int ones = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      v[i] = x;
      if (v[i]) ++ones;
      viz[i] = 0;
    }
    if (!ones) {
      cout << "0\n";
      return 0;
    }
    int best = -1;
    for (int i = 0; i < n; ++i) {
      if (v[i]) continue;
      if (!v[next(i)]) continue;
      int curr = next(i);
      int cnt = 1;
      viz[curr] = 1;
      while (v[next(curr)] && !viz[next(curr)]) {
        ++cnt;
        curr = next(curr);
        viz[curr] = 1;
      }
      ones -= cnt;
      best = max(best, cnt);
    }
    if (ones)
      cout << "-1\n";
    else
      cout << best << '\n';
  }
  return 0;
}
