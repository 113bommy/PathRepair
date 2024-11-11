#include <bits/stdc++.h>
using namespace std;
void Add(map<long long, long long> &M, pair<long long, long long> t) {
  if (t.first > 1) {
    if (t.first / 2 == 2)
      M[1] += t.second * 2;
    else
      M[t.first / 2] += t.second;
  }
  if (t.first > 2) {
    if (t.first - 1 - t.first / 2 == 2)
      M[1] += t.second * 2;
    else
      M[t.first - 1 - t.first / 2] += t.second;
  }
}
long long get(long long X, long long x1, long long x2) {
  if (X == 0) return 0;
  if (X == x1 || X == x2) return 1;
  map<long long, long long> M;
  if (X == 2)
    M[1] += 2;
  else
    M[X]++;
  long long res = 0;
  while (1) {
    if ((int)(M).size() == 0) break;
    if ((int)(M).size() > 1) {
      auto it = --M.end();
      pair<long long, long long> a = *it;
      auto jt = it;
      --jt;
      pair<long long, long long> b = *jt;
      if (abs(a.first - b.first) == 1 && (a.first ^ b.first) != 1) {
        if (it->first == x1 || it->first == x2) res += it->second;
        if (jt->first == x1 || jt->first == x2) res += jt->second;
        M.erase(it);
        M.erase(jt);
        Add(M, a);
        Add(M, b);
        continue;
      }
    }
    auto it = --M.end();
    if (it->first == x1 || it->first == x2) res += it->second;
    M.erase(it);
    pair<long long, long long> t = *it;
    Add(M, t);
  }
  return res;
}
long long Do(long long l, long long r, long long x1, long long x2,
             long long y1) {
  if (r - l + 1 == x1 || r - l + 1 == x2) return (l + r) >> 1;
  if (r - l + 1 == 2) {
    return l + y1 - 1;
  }
  long long m = (l + r) >> 1;
  long long a = get(m - l, x1, x2);
  if (a >= y1)
    return Do(l, m - 1, x1, x2, y1);
  else
    return Do(m + 1, r, x1, x2, y1 - a);
}
void solve() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  if (k == 1)
    printf("%d\n", 1);
  else if (k == 2)
    printf("%lld\n", n);
  else if (n <= 4) {
    int q[4][4] = {{1}, {1, 2}, {1, 3, 2}, {1, 4, 2, 3}};
    printf("%d\n", q[n - 1][k - 1]);
  } else {
    map<long long, long long> M;
    M[n - 2] = 1;
    long long nk = k - 2;
    long long x1 = -1, x2 = -1, y1 = -1;
    while (1) {
      if ((int)(M).size() > 1) {
        auto it = --M.end();
        pair<long long, long long> a = *it;
        auto jt = it;
        --jt;
        pair<long long, long long> b = *jt;
        if (abs(a.first - b.first) == 1 && (a.first ^ b.first) != 1) {
          long long c = a.second + b.second;
          if (nk <= c) {
            x1 = a.first, x2 = b.first;
            y1 = c;
            break;
          } else {
            M.erase(it);
            M.erase(jt);
            nk -= c;
            Add(M, a);
            Add(M, b);
            continue;
          }
        }
      }
      if (nk <= M.rbegin()->second) {
        x1 = M.rbegin()->first;
        y1 = nk;
        break;
      } else {
        nk -= M.rbegin()->second;
        pair<long long, long long> t = *M.rbegin();
        M.erase(--M.end());
        Add(M, t);
      }
    }
    printf("%lld\n", Do(2, n - 1, x1, x2, y1));
  }
}
int main() {
  int Tc = 1;
  for (int tc = 1; tc <= Tc; tc++) {
    solve();
  }
  return 0;
};
