#include <bits/stdc++.h>
using namespace std;
mt19937 rng32(chrono::steady_clock::now().time_since_epoch().count());
long long modExpo(long long x, long long n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return modExpo((x * x) % 998244353, n / 2);
  else
    return (x * modExpo((x * x) % 998244353, (n - 1) / 2)) % 998244353;
}
long long modInverse(long long n) { return modExpo(n, 1000000007 - 2); }
long long n, m, k, ar[100010];
pair<long long, long long> hull[100010];
string s, s1;
bool is_left(pair<long long, long long> p1, pair<long long, long long> p2,
             pair<long long, long long> p3) {
  long long t = (p2.first - p1.first) * (p3.second - p2.second) -
                (p2.second - p1.second) * (p3.first - p2.first);
  if (t >= 0)
    return true;
  else
    return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int ti = 1;
  while (ti--) {
    vector<pair<long long, long long> > v;
    cin >> n;
    for (long long i = 0; i < n; i++) {
      long long x, y;
      cin >> x >> y;
      y = y - x * x;
      v.push_back(make_pair(x, y));
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
      while (ans > 1 && is_left(hull[ans - 1], hull[ans], v[i])) ans--;
      hull[++ans] = v[i];
    }
    long long cnt = 0;
    for (long long i = 2; i < ans + 1; i++)
      if (hull[i].first != hull[i - 1].first) cnt++;
    cout << cnt;
  }
  return 0;
}
