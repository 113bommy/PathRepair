#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
void print(vector<long long> &v) {
  for (long long i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << '\n';
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b != 0) {
    if (b & 1) {
      res *= a;
    }
    a = (a * a);
    b = (b / 2);
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    long long n, i;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    for (i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    multiset<long long, greater<long long>> s;
    for (i = 0; i < n; i++) s.insert(v[i].second);
    long long sum = 0;
    for (i = 0; i < n; i++) sum += v[i].first;
    for (i = 0; i < n; i++) {
      s.erase(v[i].second);
      sum -= v[i].first;
      cout << sum * (*s.begin()) << " ";
      s.insert(v[i].second);
      sum += v[i].first;
    }
  }
  return 0;
}
