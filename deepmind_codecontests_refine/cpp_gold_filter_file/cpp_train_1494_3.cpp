#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  map<long long, vector<long long>> mymap;
  for (long long i = (0); i < (n); i++) {
    long long j;
    cin >> j;
    mymap[j].push_back(i);
  }
  long long ans = 1;
  for (auto x : mymap) {
    long long l = 1, s = x.second.size(), now = 0;
    for (long long r = (1); r < (s); r++) {
      now += x.second[r] - x.second[r - 1] - 1;
      while (l <= r && now > k) now -= x.second[l] - x.second[l - 1] - 1, l++;
      ans = max(ans, r - l + 2);
    }
  }
  cout << ans;
  return 0;
}
