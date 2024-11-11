#include <bits/stdc++.h>
using namespace std;
long long in[100005][2], ans[100005][2], tmp;
int main() {
  long long n, i;
  map<long long, long long> mp;
  while (cin >> n) {
    mp.clear();
    for (i = 0; i < n; i++) {
      cin >> in[i][0] >> in[i][1];
      ans[i][0] = (n * (n - 1)) / n;
      ans[i][1] = 0;
      if (mp.count(in[i][0]) == 1) {
        mp[in[i][0]]++;
      } else {
        mp[in[i][0]] = 1;
      }
    }
    for (i = 0; i < n; i++) {
      tmp = mp[in[i][1]];
      ans[i][0] += tmp;
      ans[i][1] += (n - tmp) - 1;
      cout << ans[i][0] << " " << ans[i][1] << "\n";
    }
  }
  return 0;
}
