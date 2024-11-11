#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long ans = 1, cnt, d, newCnt = 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
    --a[i];
  }
  d = a[0] / k;
  for (int i = 1; i < m; ++i) {
    if ((a[i] - cnt) / k != d) {
      cnt = newCnt;
      d = (a[i] - cnt) / k;
      ++ans;
    }
    ++newCnt;
  }
  cout << ans;
  return 0;
}
