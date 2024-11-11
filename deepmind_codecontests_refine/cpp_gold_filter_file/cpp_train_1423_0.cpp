#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n + 1), b(n + 1);
  map<long long, long long> mp;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long in = 1;
  for (int i = 1; i <= n; i++) {
    long long temp = abs(a[i]);
    for (int j = 2; j <= sqrt(temp); j++) {
      long long temp2 = j * j;
      while (temp % (temp2) == 0) temp /= temp2;
    }
    a[i] = (a[i] < 0 ? (-1 * temp) : temp);
    if (mp[a[i]] == 0) {
      b[i] = -1;
    } else {
      b[i] = mp[a[i]];
    }
    mp[a[i]] = i;
  }
  vector<long long> ans(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    long long c = 0;
    for (int j = i; j <= n; j++) {
      if (b[j] < i && a[j] != 0) {
        c++;
      }
      long long p = ((c == 0) ? 1 : c);
      ans[p]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
