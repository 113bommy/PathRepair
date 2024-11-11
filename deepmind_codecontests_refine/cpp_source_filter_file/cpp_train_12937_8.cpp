#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long ncr(long long n, long long r) {
  long long p = 1, k = 1;
  if (n - r < r) r = n - r;
  if (r != 0) {
    while (r != 0) {
      p *= n;
      k *= r;
      long long temp = gcd(p, k);
      p /= temp;
      k /= temp;
      n--;
      r--;
    }
  } else
    p = 1;
  return p;
}
long long pm(long long x, long long n) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1)
      result = ((result % 1000000007) * (x % 1000000007)) % 1000000007;
    x = ((x % 1000000007) * (x % 1000000007)) % 1000000007;
    n /= 2;
  }
  return result;
}
long long p(long long x, long long n) {
  long long result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = result * x;
    x = x * x;
    n /= 2;
  }
  return result;
}
long long factorial[300000 + 1];
void fact(long long n) {
  factorial[0] = 1;
  factorial[1] = 1;
  for (int i = 2; i < n + 1; i++)
    factorial[i] = (i * factorial[i - 1] % 1000000007) % 1000000007;
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(std::numeric_limits<double>::max_digits10);
  ;
  long long n, i, j, x, y, z = 0, p = 0, q;
  cin >> n;
  long long a[n], b[3];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  map<long long, long long> m;
  set<pair<long long, long long>> s;
  for (i = 0; i < n; i++) m[a[i]]++;
  for (auto i : m) s.insert(make_pair(i.second, i.first));
  vector<pair<pair<long long, long long>, long long>> v;
  while (s.size() >= 3) {
    pair<long long, long long> p1 = *s.begin();
    s.erase(s.find(p1));
    pair<long long, long long> p2 = *s.begin();
    s.erase(s.find(p2));
    pair<long long, long long> p3 = *s.begin();
    s.erase(s.find(p3));
    b[0] = p1.second;
    b[1] = p2.second;
    b[2] = p3.second;
    sort(b, b + 3);
    v.push_back(make_pair(make_pair(b[2], b[1]), b[0]));
    p1.first--;
    p2.first--;
    p3.first--;
    if (p1.first) s.insert(p1);
    if (p2.first) s.insert(p2);
    if (p3.first) s.insert(p3);
  }
  cout << v.size() << "\n";
  for (i = 0; i < v.size(); i++)
    cout << v[i].first.first << " " << v[i].first.second << " " << v[i].second
         << "\n";
  return 0;
}
