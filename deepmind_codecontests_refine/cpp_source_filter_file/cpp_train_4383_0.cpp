#include <bits/stdc++.h>
using namespace std;
int n, a[505], ans = 0;
multiset<int> s;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    if (s.lower_bound(a[i]) == s.begin()) {
      s.erase(--s.end());
    } else {
      s.erase(--s.lower_bound(a[i]));
      ans++;
    }
  }
  cout << ans;
}
