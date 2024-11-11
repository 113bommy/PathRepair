#include <bits/stdc++.h>
using namespace std;
void io() {
  freopen("./testcases/input.txt", "r", stdin);
  freopen("./testcases/output.txt", "w", stdout);
  freopen("./testcases/debug.txt", "w", stderr);
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long testcases;
  cin >> testcases;
  while (testcases--) {
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < (long long)n; i++) cin >> a[i];
    ;
    map<long long, long long> mp;
    for (long long i = 0; i < n; i++) {
      mp[a[i]]++;
    }
    vector<pair<long long, long long> > ans;
    sort(a.begin(), a.end());
    for (long long i = 0; i < n; i++) {
      for (long long j = i + 1; j < n; j++) {
        if (!mp[(a[j]) % a[i]]) ans.push_back({a[i], a[j]});
        if (ans.size() >= n / 2) {
          goto z;
        }
      }
    }
  z:
    for (pair<long long, long long> x : ans)
      cout << x.first << ' ' << x.second << endl;
  }
}
