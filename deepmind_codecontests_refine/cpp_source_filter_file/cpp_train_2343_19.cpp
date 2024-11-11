#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int MAX = 1000005;
int cnt[MAX];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (int i = (0); i < (n); ++i) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int ans = 0;
  for (int i = (0); i < (1000004); ++i) {
    if (cnt[i] != 0) cnt[i + 1] = (cnt[i + 1] + cnt[i] / 2);
    if (cnt[i] & 1) ans++;
  }
  cout << ans << '\n';
  return 0;
}
