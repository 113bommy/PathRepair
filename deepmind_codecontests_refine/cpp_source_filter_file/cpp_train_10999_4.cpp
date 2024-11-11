#include <bits/stdc++.h>
using namespace std;
const long long D = 300007;
const long long Inf = 1000000007;
pair<pair<long long, long long>, long long> a[D];
bool cmp(pair<pair<long long, long long>, long long> a1,
         pair<pair<long long, long long>, long long> a2) {
  return (a1.first.first < a2.first.first) ||
         (a1.first.first == a2.first.first &&
          a1.first.second > a2.first.second);
}
int main() {
  long long n, x;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i].first.first >> a[i].first.second;
    a[i].second = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  long long max_r = 0, max_r_i = 0;
  for (long long i = 1; i <= n; i++) {
    if (a[i].first.second < max_r)
      return cout << a[i].second << " " << max_r_i << endl, 0;
    if (max_r < a[i].first.second) {
      max_r = a[i].first.second;
      max_r_i = a[i].second;
    }
  }
  cout << -1 << " " << -1 << endl;
  ;
  exit(0);
  ;
}
