#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const long long int mod = 1e9 + 7;
vector<long long int> s;
long long int sum(long long int l, long long int r) {
  if (l == 0) return s[r];
  return s[r] - s[l - 1];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int TT = clock();
  long long int n;
  cin >> n;
  vector<long long int> a(n);
  vector<long long int> pos;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) pos.push_back(i);
  }
  s = a;
  for (long long int i = 1; i < n; i++) s[i] += s[i - 1];
  vector<long long int> seen(n + 1, -1), last(n), next(n);
  last[0] = 0;
  next[n - 1] = n - 1;
  seen[a[0]] = 0;
  for (long long int i = 1; i < n; i++) {
    last[i] = max(last[i - 1], seen[a[i]] + 1);
    seen[a[i]] = i;
  }
  seen.assign(n + 1, n);
  seen[a[n - 1]] = n - 1;
  for (long long int i = n - 2; i >= 0; i--) {
    next[i] = min(next[i + 1], seen[a[i]] - 1);
    seen[a[i]] = i;
  }
  long long int ans = 0;
  for (long long int i = 0; i < pos.size(); i++) {
    long long int p = pos[i], lp = 0, np = n - 1;
    if (i > 0) lp = pos[i - 1] + 1;
    if (i < pos.size() - 1) np = pos[i + 1] - 1;
    ans++;
    long long int s = 0, mx = 1;
    for (long long int j = p - 1; j >= lp; j--) {
      mx = max(mx, a[j]);
      long long int r = j + mx - 1;
      if (r >= n) continue;
      if (next[j] < r) continue;
      if (mx * (mx + 1) / 2 == sum(j, r)) ans++;
    }
    mx = 1;
    for (long long int j = p + 1; j <= np; j++) {
      mx = max(mx, a[j]);
      long long int l = j - mx + 1;
      if (l < 0) continue;
      if (next[l] > j) continue;
      if (mx * (mx + 1) / 2 == sum(l, j)) ans++;
    }
  }
  cout << ans;
  cerr << "\n\nTIME: " << (long double)(clock() - TT) / CLOCKS_PER_SEC
       << " sec\n";
  TT = clock();
  return 0;
}
