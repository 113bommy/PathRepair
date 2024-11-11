#include <bits/stdc++.h>
using namespace std;
bool zero(pair<long long, long long> a) { return !a.first && !a.second; }
bool mod(long long a, long long b) {
  if (!b)
    return a == 0;
  else
    return a % b == 0;
}
bool judge1(pair<long long, long long> a, pair<long long, long long> b) {
  if (!mod(b.first, a.first) || !mod(b.second, a.second)) return false;
  long long k1 = -1, k2 = -1;
  if (a.first) k1 = b.first / a.first;
  if (a.second) k2 = b.second / a.second;
  if (k1 != -1 && k2 != -1)
    return k1 == k2;
  else
    return true;
}
bool judge(pair<long long, long long> a, pair<long long, long long> b,
           pair<long long, long long> c) {
  if (zero(c)) return true;
  if (zero(a)) swap(a, b);
  if (zero(b)) {
    if (zero(a)) return false;
    return judge1(c, a);
  }
  long long tmp = b.first * a.second - a.first * b.second;
  long long tmp1 = c.first * a.second - c.second * a.first;
  long long tmp2 = c.first * b.second - c.second * b.first;
  if (tmp == 0) {
    return judge1(c, a) || judge1(c, b);
  }
  return (tmp2 % tmp == 0 && tmp1 % tmp == 0);
}
pair<long long, long long> rotate(pair<long long, long long> a) {
  return make_pair(a.second, -a.first);
}
bool solve(pair<long long, long long> a, pair<long long, long long> b,
           pair<long long, long long> c) {
  pair<long long, long long> cc = rotate(c);
  for (int i = 0; i < 3; i++) {
    if (judge(c, cc, make_pair(b.first - a.first, b.second - a.second)))
      return true;
    a = rotate(a);
  }
  return false;
}
int main() {
  pair<long long, long long> a, b, c;
  cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second;
  if (solve(a, b, c))
    puts("YES");
  else
    puts("NO");
  return 0;
}
