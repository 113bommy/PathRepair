#include <bits/stdc++.h>
using namespace std;
const long long M = 3162280;
vector<long long> v;
vector<pair<long long, long long> > ans;
long long sz, n, m, pos;
const clock_t begin_time = clock();
long long p2(long long x) {
  long long y = sqrt(x);
  for (long long i = y - 1; i <= y + 1; i++)
    if (i * i == x) return y;
  return false;
}
bool fnd(long long x) {
  long long p = pos;
  long long i;
  for (i = pos; i <= sz; i++) {
    if (float(clock() - begin_time) / CLOCKS_PER_SEC > 1.95) return false;
    long long j = p2(i * i + x);
    if (j) {
      pos = j;
      ans.push_back({i, j});
      return true;
    }
  }
  return false;
}
int32_t main() {
  cin >> n;
  for (long long i = 1; i <= n / 2; i++) {
    long long x;
    scanf("%lld", &x);
    v.push_back(x);
  }
  sz = 2e9;
  pos = 1;
  for (auto x : v)
    if (!fnd(x)) return cout << "No" << endl, 0;
  long long bef = 0;
  cout << "Yes" << endl;
  for (auto p : ans) {
    printf("%lld %lld ", p.first * p.first - bef * bef,
           p.second * p.second - p.first * p.first);
    bef = p.second;
  }
  return 0;
}
