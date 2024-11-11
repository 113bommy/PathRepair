#include <bits/stdc++.h>
using namespace std;
void setup() {}
const long long N = 1e5 + 5;
long long n, a[N], cnt[11];
signed main() {
  setup();
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  long long res = 1;
  for (long long i = 1; i <= n; i++) {
    cnt[a[i]]++;
    map<long long, long long> f;
    for (long long j = 1; j <= 10; j++) {
      if (cnt[j]) f[cnt[j]]++;
    }
    if (f.size() > 2) {
      continue;
    }
    if (f.size() == 1) {
      auto it = *f.begin();
      if (it.first == 1 || it.second == 1) {
        res = i;
      }
      continue;
    } else {
      long long freq[2], num[2];
      long long idx = 0;
      for (auto it : f) {
        freq[idx] = it.first;
        num[idx] = it.second;
        idx++;
      }
      if (freq[0] == 1 && num[0] == 1) {
        res = i;
      } else if (freq[0] == freq[1] - 1 && num[1] == 1) {
        res = i;
      }
    }
  }
  cout << res;
}
