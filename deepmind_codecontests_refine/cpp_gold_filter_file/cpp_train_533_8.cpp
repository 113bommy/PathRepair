#include <bits/stdc++.h>
using namespace std;
int a[300042];
int pos[300042];
vector<pair<int, int> > ans;
int n;
void sswap(int i, int j) {
  if (i == j) return;
  if (abs(i - j) < n / 2) throw runtime_error("Not good");
  ans.push_back({i, j});
  int ai = a[i];
  int aj = a[j];
  pos[ai] = j;
  pos[aj] = i;
  a[i] = aj;
  a[j] = ai;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  if (pos[1] != 1 && pos[1] <= n / 2) sswap(pos[1], n);
  sswap(1, pos[1]);
  for (int i = 2; i <= n; i++) {
    int pocz = pos[i];
    if (pocz == i) continue;
    if (i > n / 2) {
      if (pocz > n / 2) {
        sswap(1, pocz);
        sswap(1, i);
        sswap(1, pocz);
      } else {
        sswap(pocz, n);
        sswap(1, n);
        sswap(1, i);
        sswap(1, n);
      }
    } else {
      if (pocz > n / 2) {
        if (pocz == n) {
          sswap(i, n);
        } else {
          sswap(1, pocz);
          sswap(1, n);
          sswap(i, n);
          sswap(1, pocz);
        }
      } else {
        sswap(pocz, n);
        sswap(i, n);
      }
    }
  }
  cout << ans.size() << "\n";
  for (auto aa : ans) cout << aa.first << " " << aa.second << "\n";
  return 0;
}
