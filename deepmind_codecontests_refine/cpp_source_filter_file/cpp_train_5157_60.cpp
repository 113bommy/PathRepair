#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long powM(long long x, long long y, long long m) {
  if (y == 0) return 1;
  long long p = powM(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  for (long long i = 0; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({a, b});
  }
  int cnt = 0;
  for (long long i = 2; i <= n - 2; i++) {
    if (v[i].first > v[i - 1].first) {
      if (v[i + 1].second > v[i].second) cnt++;
    } else if (v[i].first < v[i - 1].first) {
      if (v[i + 1].second < v[i].second) cnt++;
    }
    if (v[i].second > v[i - 1].second) {
      if (v[i + 1].first < v[i].first) cnt++;
    } else if (v[i].second < v[i - 1].second) {
      if (v[i + 1].first > v[i].first) cnt++;
    }
  }
  cout << cnt << '\n';
  return 0;
}
