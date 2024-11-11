#include <bits/stdc++.h>
using namespace std;
const int nax = 2e6 + 5;
int cnt[nax], n, ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0, w; i < n; i++) cin >> w, ++cnt[w];
  for (int i = 0; i < nax - 1; i++) {
    if (cnt[i] % 2) ans++, cnt[i]--;
    cnt[i + 1] += cnt[i] / 2;
  }
  cout << ans << endl;
}
