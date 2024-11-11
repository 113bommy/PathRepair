#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long mn(long long a, long long b) {
  if (a < b) return a;
  return b;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  long long a[n + 5];
  vector<pair<long long, long long> > p;
  long long cur_point = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cur_point += a[i] / 10;
    if (a[i] == 100) p.push_back(make_pair(0, i));
    p.push_back(make_pair(10 - a[i] % 10, i));
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < n; i++) {
    if (k >= p[i].first and p[i].first > 0) {
      k -= p[i].first;
      cur_point++;
    }
  }
  if (k > 0) {
    for (int i = 0; i < n; i++) a[i] = (a[i] / 10) * 10 + 10 * (a[i] % 10 > 0);
    for (int i = 0; i < n; i++) {
      long long tt = min(k / 10 * 10, 100 - a[i]);
      k -= tt;
      cur_point += tt / 10;
    }
  }
  cout << cur_point;
}
