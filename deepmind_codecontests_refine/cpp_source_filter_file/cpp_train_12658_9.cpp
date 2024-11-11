#include <bits/stdc++.h>
using namespace std;
int pos[200002];
int Next[200002];
int lst[200002];
int a[200002];
int f[200002];
set<pair<int, int> > all;
int ans, now, i, k, n;
int main() {
  cin >> n >> k;
  for (i = 1; i <= n; i++) cin >> a[i], pos[a[i]] = n + 1;
  for (i = n; i >= 1; i--) {
    Next[i] = pos[a[i]];
    pos[a[i]] = i;
  }
  now = 0;
  i = 1;
  while (i <= n && now < k) {
    if (!f[a[i]]) {
      f[a[i]] = 1;
      now++;
      all.insert(make_pair(Next[i], a[i]));
      lst[a[i]] = Next[i];
    } else {
      all.erase(make_pair(lst[a[i]], a[i]));
      lst[a[i]] = Next[i];
      all.insert(make_pair(Next[i], a[i]));
    }
    i++;
  }
  ans = now;
  while (i <= n) {
    if (f[a[i]]) {
      all.erase(make_pair(lst[a[i]], a[i]));
      lst[a[i]] = Next[i];
      all.insert(make_pair(Next[i], a[i]));
      i++;
      continue;
    } else {
      int x = (*all.rbegin()).second;
      f[x] = 0;
      all.erase(make_pair(lst[x], x));
      ans++;
      f[a[i]] = 1;
      all.insert(make_pair(Next[i], a[i]));
      lst[a[i]] = Next[i];
    }
    i++;
  }
  cout << ans << endl;
}
