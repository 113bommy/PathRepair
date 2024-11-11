#include <bits/stdc++.h>
using namespace std;
map<int, long long> mp;
long long a[200007], k, q;
int main() {
  int n, k;
  while (cin >> n >> k) {
    mp.clear();
    int top = 0;
    for (int i = 0; i < n; i++) {
      cin >> q;
      if (mp[q] == 0) a[top++] = q;
      mp[q]++;
    }
    sort(a, a + top);
    for (int j = 0; j < k; j++) {
      cin >> q;
      if (q & 1) {
        cout << -1 << endl;
        continue;
      }
      int count = 0;
      for (int i = top - 1; i >= 0; i--) {
        int x = q / a[i];
        if (mp[a[i]] >= x) {
          q -= x * a[i];
          count += x;
        } else {
          int x = mp[a[i]];
          q -= x * a[i];
          count += x;
        }
        if (q == 0) break;
      }
      if (q == 0)
        cout << count << endl;
      else
        cout << -1 << endl;
    }
  }
  return 0;
}
