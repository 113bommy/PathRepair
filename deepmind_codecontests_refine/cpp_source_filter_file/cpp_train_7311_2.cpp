#include <bits/stdc++.h>
using namespace std;
int cum[200005];
int main() {
  int n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cum[i] = a[i];
    if (i) cum[i] += cum[i - 1];
  }
  set<long long> s;
  long long ans = 0;
  s.insert(0);
  int r = 0;
  for (int i = 0; i < n; i++) {
    while (r < n && !s.count(cum[r])) {
      s.insert(cum[r]);
      r++;
    }
    ans += r - i;
    if (!i)
      s.erase(0);
    else
      s.erase(cum[i - 1]);
  }
  cout << ans;
  return 0;
}
