#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int cnt[maxn], num[200010], n, k, d;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, res, tmp;
  cin >> t;
  while (t--) {
    memset(cnt, 0, (k + 1) * sizeof(int));
    cin >> n >> k >> d;
    for (int i = 0; i < n; i++) cin >> num[i];
    res = 0;
    for (int i = 0; i < d; i++) {
      if (!cnt[num[i]]) res++;
      cnt[num[i]]++;
    }
    tmp = res;
    for (int i = 0; i < n - d; i++) {
      cnt[num[i]]--;
      if (!cnt[num[i]]) tmp--;
      if (!cnt[num[i + d]]) tmp++;
      cnt[num[i + d]]++;
      res = min(res, tmp);
    }
    cout << res << endl;
  }
  return 0;
}
