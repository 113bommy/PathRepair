#include <bits/stdc++.h>
using namespace std;
int n, c, k;
int a[100005];
int cnt[100005];
set<pair<int, int> > s;
int main(void) {
  cin >> n >> c >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < c; i++) {
    s.insert(make_pair(0, i));
  }
  int ans = 0;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j < n) {
      s.erase(make_pair(-cnt[a[j]], a[j]));
      cnt[a[j]]++;
      s.insert(make_pair(-cnt[a[j]], a[j]));
      j++;
      int big = -(s.begin()->first);
      if (j - i - big <= k) {
        ans = max(ans, big);
      } else {
        break;
      }
    }
    s.erase(make_pair(-cnt[a[i]], a[i]));
    cnt[a[i]]--;
    s.insert(make_pair(-cnt[a[i]], a[i]));
  }
  cout << ans << endl;
  return 0;
}
