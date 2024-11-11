#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n, k, m;
  cin >> n >> k >> m;
  string s[100011];
  long long cost[100011];
  map<string, long long> make_pair;
  for (long long i = 1; i <= n; i++) {
    cin >> s[i];
    make_pair[s[i]] = i;
  }
  long long x, cnt;
  for (long long i = 1; i <= n; i++) cin >> cost[i];
  long long grp[100011];
  long long fin[100011] = {100000000000000000};
  memset(fin, 100000000000000000, sizeof(fin));
  for (long long i = 1; i < n; i++) fin[i] = 100000000000000000;
  for (long long i = 1; i <= k; i++) {
    cin >> cnt;
    for (long long j = 1; j <= cnt; j++) {
      cin >> x;
      grp[x] = i;
      fin[i] = min(fin[i], cost[x]);
    }
  }
  string str;
  long long sum = 0;
  for (long long i = 0; i < m; i++) {
    cin >> str;
    sum += fin[grp[make_pair[str]]];
  }
  cout << sum;
  return 0;
}
