#include <bits/stdc++.h>
using namespace std;
const long long inf = LONG_MAX;
const long long arr = 1000000;
bool comp(pair<long long, long long> a, pair<long long, long long> b) {
  if (a.first == b.first)
    return a.second < b.second;
  else
    return a.first < b.first;
}
int main(void) {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ans = 0;
  long long t = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      ans = max(ans, t);
      t = 1;
    } else
      t++;
  }
  ans = max(ans, t);
  cout << ans << '\n';
  return 0;
}
