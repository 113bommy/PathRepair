#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);
map<long long, long long> m1;
long long CeilIndex(std::vector<long long>& v, long long l, long long r,
                    long long key) {
  while (r - l > 1) {
    long long m = l + (r - l) / 2;
    if (v[m] >= key)
      r = m;
    else
      l = m;
  }
  return r;
}
long long LongestIncreasingSubsequenceLength(std::vector<long long>& v) {
  if (v.size() == 0) return 0;
  std::vector<long long> tail(v.size(), 0);
  long long length = 1;
  tail[0] = v[0];
  for (size_t i = 1; i < v.size(); i++) {
    if (v[i] < tail[0])
      tail[0] = v[i];
    else if (v[i] > tail[length - 1])
      tail[length++] = v[i];
    else
      tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
  }
  return length;
}
long long powm(long long a, long long b, long long m) {
  if (b == 0) return 1;
  long long t = powm(a, b / 2, m);
  if (b % 2) return a * t % m * t % m;
  return t * t % m;
}
long long modinv1(long long b, long long m) { return powm(b, m - 2, m); }
bool comp(const pair<long long, long long>& p1,
          const pair<long long, long long>& p2) {
  if (p1.second == p2.second) return (p1.first < p2.first);
  return (p1.second < p2.second);
}
long long modinv(long long n, long long m) {
  long long i = 0;
  for (i = 1; i < m; ++i)
    if ((n * i) % m == 1) return i;
}
void DJ() {
  long long n, i;
  cin >> n;
  long long ind = n / 4;
  long long _4 = -1, _7 = -1, s = n;
  for (i = 0; i < n / 7 + 1; ++i) {
    if ((n - i * 7) % 4 == 0) {
      if (s > i + (n - i * 7) / 4) {
        _4 = i;
        _7 = (n - i * 7) / 4;
      }
    }
  }
  if (_4 == -1)
    cout << -1;
  else {
    for (i = 0; i < _4; ++i) cout << 4;
    for (i = 0; i < _7; ++i) cout << 7;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) DJ();
  return 0;
}
