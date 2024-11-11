#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int cnt[100];
string ans, t;
int main() {
  int T, n, k;
  cin >> T;
  while (T--) {
    cin >> n >> k;
    t.clear();
    cin >> t;
    memset(cnt, 0, sizeof(cnt));
    sort(t.begin(), t.end());
    ans.clear();
    for (int i = 0; i < n; i++) cnt[t[i] - 'a']++;
    int it = 0;
    while (cnt[it] == 0) it++;
    if (n == k) {
      printf("%c\n", t[n - 1]);
      return 0;
    }
    if (cnt[it] < k) {
      it++;
      while (cnt[it] == 0) it++;
      printf("%c\n", t[k - 1]);
    } else {
      ans += (char)(it + 'a');
      cnt[it] -= k;
      while (cnt[it] == 0) it++;
      if (cnt[it] != n - k) {
        for (int i = k; i < n; i++) ans += t[i];
        cout << ans << endl;
        continue;
      } else {
        for (int i = 1; i <= (n - k - 1) / k + 1; i++) ans += (char)(it + 'a');
        cout << ans << endl;
        continue;
      }
    }
  }
  return 0;
}
