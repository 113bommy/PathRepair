#include <bits/stdc++.h>
using namespace std;
long long powe(long long n, long long m) {
  if (m == 0) return 1;
  long long t = powe(n, m / 2);
  if (m % 2 == 0) return (t * t);
  return (((t * t)) * n);
}
long long mpowe(long long n, long long m, long long MOD) {
  if (m == 0) return 1;
  long long t = mpowe(n, m / 2, MOD);
  t %= MOD;
  if (m % 2 == 0) return (t * t) % MOD;
  return (((t * t) % MOD) * n) % MOD;
}
long long logtwo(long long n) {
  if (n == 1) return 0;
  if (n == 0) return -1;
  return logtwo(n / 2) + 1;
}
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
  if (a.first.first / 1100 == b.first.first / 1100) {
    return a.first.second < b.first.second;
  } else {
    return a.first.first < b.first.first;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  std::vector<pair<pair<int, int>, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].first.first >> v[i].first.second;
    v[i].second = i + 1;
  }
  sort(v.begin(), v.end(), compare);
  for (int i = 0; i < n; i++) {
    cout << v[i].second << " ";
  }
}
