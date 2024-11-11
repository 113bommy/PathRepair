#include <bits/stdc++.h>
using namespace std;
int n, k;
set<int> cur;
int a[400001];
int last[400001];
int l[400001];
int main() {
  set<int> s;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    if (last[a[i]] == 0)
      l[i] = n;
    else
      l[i] = last[a[i]];
    last[a[i]] = i;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s.count(-i) > 0) {
      s.erase(-i);
      s.insert(-l[i]);
      continue;
    }
    if (s.size() == k) {
      s.erase(s.begin());
    }
    s.insert(-l[i]);
    ans++;
  }
  cout << ans;
  return 0;
}
