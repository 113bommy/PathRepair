#include <bits/stdc++.h>
using namespace std;
inline long long rd() {
  long long x = 0;
  bool neg = false;
  char c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') neg = true, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  if (neg) x = -x;
  return x;
}
inline void write(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
}
const long long N = 2e5;
long long n, m, k, q, b[N + 2], L[N + 2], R[N + 2], have[N + 2], val[N + 2];
pair<long long, long long> a[N + 2];
void input() {
  n = rd();
  m = rd();
  k = rd();
  q = rd();
  for (long long _b = k, i = 1; i <= _b; ++i)
    a[i].first = rd(), a[i].second = rd();
  for (long long _b = q, i = 1; i <= _b; ++i) b[i] = rd();
}
vector<pair<long long, long long> > tmp;
long long tox(long long first, long long second, long long k) {
  return abs(k - second) + abs(second - first);
}
long long toy(long long first, long long second, long long k) {
  return abs(k - first) + abs(first - second);
}
void solve() {
  sort(a + 1, a + k + 1);
  for (long long _b = q, i = 1; i <= _b; ++i) L[b[i]] = b[i], R[b[i]] = b[i];
  for (long long _b = m, i = 1; i <= _b; ++i)
    if (!L[i]) L[i] = L[i - 1];
  for (long long _b = 1, i = m; i >= _b; --i)
    if (!R[i]) R[i] = R[i + 1];
  tmp.push_back({1, 0});
  if (a[1].first != 1) {
    tmp.clear();
    tmp.push_back({R[1], R[1] - 1 + a[1].first - 1});
  }
  long long l = 1;
  while (l <= k) {
    long long r = l;
    while (r + 1 <= k && a[r + 1].first == a[l].first) ++r;
    long long first = a[l].second;
    long long second = a[r].second;
    long long btx = 1e15, bty = 1e15;
    for (auto c : tmp) {
      btx = min(btx, c.second + tox(first, second, c.first));
      bty = min(bty, c.second + toy(first, second, c.first));
    }
    if (r == k) {
      cout << min(btx, bty);
      exit(0);
    }
    tmp.clear();
    if (L[first])
      tmp.push_back({L[first], abs(L[first] - first) + btx + a[r + 1].first -
                                   a[r].first});
    if (R[first])
      tmp.push_back({R[first], abs(R[first] - first) + btx + a[r + 1].first -
                                   a[r].first});
    if (L[second])
      tmp.push_back({L[second], abs(L[second] - second) + bty + a[r + 1].first -
                                    a[r].first});
    if (R[second])
      tmp.push_back({R[second], abs(R[second] - second) + bty + a[r + 1].first -
                                    a[r].first});
    ++l;
  }
  exit(1);
}
int main() {
  input();
  solve();
  return 0;
}
