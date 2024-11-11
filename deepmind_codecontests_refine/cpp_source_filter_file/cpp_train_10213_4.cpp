#include <bits/stdc++.h>
using namespace std;
map<int, vector<long long>> mp;
long long a[200010];
int main() {
  long long n, k;
  long long res = 0;
  scanf("%lld%lld", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    long long m = a[i];
    int c = 0;
    while (m > 0) {
      m /= 10;
      c++;
    }
    mp[c].push_back(a[i] % k);
  }
  for (auto c : mp) {
    sort(mp[c.first].begin(), mp[c.first].end());
  }
  for (int i = 0; i < n; i++) {
    long long m = a[i], r;
    int c = 0;
    while (m > 0) {
      m /= 10;
      c++;
    }
    m = a[i];
    for (int j = 1; j <= 10; j++) {
      m *= 10;
      r = m % k;
      if (mp.find(j) != mp.end()) {
        long long cnt = upper_bound(mp[j].begin(), mp[j].end(), (k - r) % k) -
                        lower_bound(mp[j].begin(), mp[j].end(), (k - r) % k);
        if (c == j && cnt > 0 && (k - r) % k == a[i] % k) {
          cnt--;
        }
        res += cnt;
      }
    }
  }
  printf("%lld", res);
}
