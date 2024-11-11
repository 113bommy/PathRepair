#include <bits/stdc++.h>
using namespace std;
map<long long, long long> m;
map<long long, long long>::iterator it;
long long ans[200500];
int main() {
  long long n, i, x, y, pr = -1, cur = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x >> y;
    m[x]++;
    m[y + 1]--;
  }
  for (it = m.begin(); it != m.end(); it++) {
    if (it->second < 0) {
      ans[cur] += (it->first - pr);
    } else {
      if (cur != 0) {
        ans[cur] += (it->first - pr);
      }
    }
    cur += it->second;
    pr = it->first;
  }
  for (i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
}
