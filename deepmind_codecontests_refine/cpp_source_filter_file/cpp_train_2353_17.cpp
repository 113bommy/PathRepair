#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k, q;
  cin >> n >> k >> q;
  int maxN = 2e5 + 5;
  vector<int> marcas(maxN);
  for (int i = 0; i < n; ++i) {
    int l, r;
    cin >> l >> r;
    marcas[l]++;
    marcas[r + 1]--;
  }
  vector<int> prefix(maxN);
  int sum = 0;
  for (int i = 0; i < maxN; ++i) {
    sum += marcas[i];
    prefix[i] = sum;
  }
  vector<int> graters(maxN);
  for (int i = 1; i < maxN; ++i) {
    if (prefix[i] >= 2) {
      graters[i] = 1;
    }
  }
  vector<int> ans(maxN);
  for (int i = 1; i < maxN; ++i) {
    ans[i] = ans[i - 1] + graters[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << ans[r] - ans[l - 1] << endl;
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
