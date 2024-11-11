#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  vector<long long> a(n), b(n);
  map<long long, long long> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long in = 1;
  for (int i = 0; i < n; i++) {
    long long temp = abs(a[i]);
    for (int j = 2; j <= sqrt(temp); j++) {
      long long temp2 = j * j;
      while (temp % (temp2) == 0) temp /= temp2;
    }
    a[i] = (a[i] < 0 ? (-1 * temp) : temp);
    if (mp[a[i]] == 0) {
      b[i] = in;
      mp[a[i]] = in;
      in++;
    } else {
      b[i] = mp[a[i]];
    }
  }
  vector<long long> ans(n + 1, 0);
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (a[j] != 0) {
        break;
      } else {
        ans[1]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    long long c = 0;
    vector<long long> vis(n + 1, 0);
    for (int j = i; j < n; j++) {
      if (a[j] == 0) {
        ans[c]++;
        continue;
      }
      if (vis[b[j]] == 0) {
        c++;
      }
      vis[b[j]]++;
      ans[c]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
