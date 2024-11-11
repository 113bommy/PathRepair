#include <bits/stdc++.h>
using namespace std;
int abs(int x) {
  if (x < 0) return -x;
  return x;
}
int a[100010], b[100010], c[100010];
multiset<int> s;
multiset<int>::iterator it;
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c[a[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    s.insert(i - c[b[i]]);
  }
  for (int i = 0; i < n; i++) {
    it = s.upper_bound(i);
    int ans = 9999999;
    if (it != s.end()) {
      ans = min(ans, *it - i);
    }
    if (it != s.begin()) {
      ans = min(ans, i - (*it));
    }
    cout << ans << endl;
    int val = i - c[b[i]];
    s.erase(s.find(val));
    s.insert(val + n);
  }
  return 0;
}
