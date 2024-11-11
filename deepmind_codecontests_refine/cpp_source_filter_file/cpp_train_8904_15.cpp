#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie();
  cout.tie();
  int long long q, w, h;
  cin >> q;
  while (q--) {
    cin >> h >> w;
    vector<vector<int long long> > a(h, vector<int long long>(w, 0));
    for (long long i = 0; i < h; i++)
      for (long long j = 0; j < w; j++) cin >> a[i][j];
    int long long ans = 0;
    for (long long i = 0; i < w; i++) {
      ans = max(abs(a[h / 2][i] - a[h / 2 + 1][i]), ans);
    }
    if (ans > 120)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
