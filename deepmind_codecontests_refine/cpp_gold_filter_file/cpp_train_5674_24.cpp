#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int nax = 1000000 + 10;
int cnt[nax];
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int maxi = -1;
    int ans = 0;
    for (int j = 1; j <= n; j++) {
      int num;
      cin >> num;
      if (num > maxi) {
        maxi = num;
        ans = j;
      }
    }
    cnt[ans]++;
  }
  int maxi = -1, ans = 0;
  for (int i = 1; i <= n; i++) {
    if (cnt[i] > maxi) {
      maxi = cnt[i];
      ans = i;
    }
  }
  cout << ans;
  return 0;
}
