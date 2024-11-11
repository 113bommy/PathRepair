#include <bits/stdc++.h>
using namespace std;
const int N = 200002;
int n;
pair<int, int> a[N];
long long s[N];
bool solve(int m) {
  int bl = 0, br = n;
  while (bl < br) {
    int bm = (bl + br) / 2;
    if (a[bm].first <= m)
      bl = bm + 1;
    else
      br = bm;
  }
  if (br == n) return true;
  if (s[br] > m)
    return false;
  else
    return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int T;
  cin >> T;
  for (int tt = 0; tt < T; ++tt) {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i].first;
    for (int i = 0; i < n; ++i) cin >> a[i].second;
    sort(a, a + n);
    for (int i = n - 1; i >= 0; --i) {
      if (i == n - 1)
        s[i] = a[i].second;
      else
        s[i] = s[i + 1] + a[i].second;
    }
    int bl = 0, br = (int)1e9 + 1e8;
    while (bl < br) {
      int bm = (bl + br) / 2;
      if (!solve(bm))
        bl = bm + 1;
      else
        br = bm;
    }
    cout << br << endl;
  }
}
