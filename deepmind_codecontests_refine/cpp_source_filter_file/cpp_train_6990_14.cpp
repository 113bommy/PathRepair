#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) {
  if (a > b)
    return a;
  else
    return b;
}
long long min(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) {
  return (max(a, b) / gcd(a, b)) * min(a, b);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  long long n, m;
  cin >> n >> m;
  vector<vector<pair<long long, long long>>> v;
  for (long long i = 0; i < n; i++) {
    vector<pair<long long, long long>> y;
    for (long long j = 0; j < m; j++) {
      int x;
      cin >> x;
      pair<long long, long long> k = make_pair(x, j + 1);
      y.push_back(k);
    }
    v.push_back(y);
  }
  for (long long i = 0; i < n; i++) sort(v[i].begin(), v[i].end());
  int x = 0;
  for (long long i = 0; i < n; i++) x ^= v[i][0].first;
  if (x > 0) {
    cout << "TAK1" << endl;
    for (long long i = 0; i < n; i++) cout << v[i][0].second << " ";
    return 0;
  }
  for (long long i = 0; i < n; i++) {
    x ^= v[i][0].first;
    x ^= v[i][m - 1].first;
    if (x > 0) {
      cout << "TAK" << endl;
      for (long long j = 0; j <= i - 1; j++) cout << v[j][0].second << " ";
      cout << v[i][m - 1].second << " ";
      for (long long j = i + 1; j <= n - 1; j++) cout << v[j][0].second << " ";
      return 0;
    }
    x ^= v[i][0].first;
    x ^= v[i][m - 1].first;
  }
  cout << "NIE";
  return 0;
}
