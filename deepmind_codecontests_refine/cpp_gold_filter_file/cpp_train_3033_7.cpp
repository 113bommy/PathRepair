#include <bits/stdc++.h>
using namespace std;
int a[500005], res[500005], ind[500005], l[500005], r[500005], bas[20], pos[20];
bool comp(int i, int j) { return r[i] < r[j]; }
void solve() {
  int n, q;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> l[i] >> r[i];
    ind[i] = i;
  }
  sort(ind + 1, ind + q + 1, comp);
  int cur = 1;
  for (int qc = 1; qc <= q; qc++) {
    int i = ind[qc];
    while (cur <= r[i]) {
      int x = a[cur], p = cur;
      for (int j = 19; j >= 0; j--) {
        if (!(x & (1 << j))) continue;
        if (!bas[j]) {
          bas[j] = x;
          pos[j] = p;
          break;
        }
        if (pos[j] < p) {
          swap(bas[j], x);
          swap(pos[j], p);
        }
        x ^= bas[j];
      }
      cur++;
    }
    for (int j = 19; j >= 0; j--)
      if (pos[j] >= l[i]) res[i] = max(res[i], res[i] ^ bas[j]);
  }
  for (int i = 1; i <= q; i++) cout << res[i] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int qc = 1;
  for (int i = 1; i <= qc; i++) solve();
}
