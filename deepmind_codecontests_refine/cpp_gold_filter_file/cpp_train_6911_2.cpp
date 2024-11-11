#include <bits/stdc++.h>
using namespace std;
const int LOG = 30;
int cnt[LOG];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> need(m);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < LOG; j++) {
      if ((1 << j) & x) cnt[j]++;
    }
  }
  for (int& i : need) cin >> i;
  sort(need.begin(), need.end());
  int ans = 0, j;
  for (int i : need) {
    for (j = i; j < LOG; j++) {
      if (cnt[j]) break;
    }
    if (j == LOG) break;
    for (; j > i; j--) cnt[j]--, cnt[j - 1] += 2;
    cnt[i]--;
    ans++;
  }
  cout << ans << endl;
}
