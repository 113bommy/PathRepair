#include <bits/stdc++.h>
using namespace std;
long long first[200001], last[200001], freq[200001];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, q;
  cin >> n >> q;
  for (long long i = 0; i < 200001; i++) last[i] = first[i] = -1;
  vector<long long> v(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
    freq[v[i]]++;
  }
  for (long long i = 0; i < n; i++) last[v[i]] = i;
  for (long long i = n - 1; i >= 0; i--) first[v[i]] = i;
  vector<pair<long long, long long> > arr;
  for (long long i = 1; i <= 200000; i++) {
    if (last[i] != -1) arr.push_back({first[i], last[i]});
  }
  sort(arr.begin(), arr.end());
  long long l = arr[0].first;
  long long r = arr[0].second;
  long long mx = freq[v[l]];
  long long ans = 0;
  for (long long i = 1; i < arr.size(); i++) {
    long long cl = arr[i].first;
    long long cr = arr[i].second;
    if (cl > r) {
      ans += (r - l + 1) - mx;
      l = cl;
      r = cr;
      mx = freq[v[l]];
      continue;
    }
    mx = max(mx, freq[v[cl]]);
    l = min(l, cl);
    r = max(r, cr);
  }
  cout << ans + (r - l + 1) - mx;
}
