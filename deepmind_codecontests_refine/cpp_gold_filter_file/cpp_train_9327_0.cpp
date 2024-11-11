#include <bits/stdc++.h>
using namespace std;
const long long N = 4e5 + 10;
bool flip[N << 2];
long long seg[N << 2], lazy[N << 2];
void push(long long i, long long j, long long n) {
  if (lazy[n] != -1) {
    if (i ^ j) {
      lazy[n << 1] = lazy[n << 1 | 1] = lazy[n];
      flip[n << 1] = flip[n << 1 | 1] = 0;
    }
    seg[n] = (j - i + 1) * lazy[n];
    lazy[n] = -1;
  }
  if (flip[n]) {
    seg[n] = j - i + 1 - seg[n];
    if (i ^ j) {
      flip[n << 1] ^= 1;
      flip[n << 1 | 1] ^= 1;
    }
    flip[n] = 0;
  }
}
void update(long long i, long long j, long long l, long long r, bool v,
            long long n) {
  push(i, j, n);
  if (i > r || j < l) {
    return;
  }
  if (i >= l && j <= r) {
    lazy[n] = v;
    push(i, j, n);
    return;
  }
  long long m = (i + j) >> 1;
  update(i, m, l, r, v, n << 1);
  update(m + 1, j, l, r, v, n << 1 | 1);
  seg[n] = seg[n << 1] + seg[n << 1 | 1];
}
void update2(long long i, long long j, long long l, long long r, long long n) {
  push(i, j, n);
  if (i > r || j < l) {
    return;
  }
  if (i >= l && j <= r) {
    flip[n] ^= 1;
    push(i, j, n);
    return;
  }
  long long m = (i + j) >> 1;
  update2(i, m, l, r, n << 1);
  update2(m + 1, j, l, r, n << 1 | 1);
  seg[n] = seg[n << 1] + seg[n << 1 | 1];
}
long long query(long long i, long long j, long long l, long long r,
                long long n) {
  push(i, j, n);
  if (i > r || j < l) {
    return 0;
  }
  if (i >= l && j <= r) {
    return seg[n];
  }
  long long m = (i + j) >> 1;
  long long res = query(i, m, l, r, n << 1) + query(m + 1, j, l, r, n << 1 | 1);
  return res;
}
long long t[N], l[N], r[N];
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  map<long long, long long> m, rev;
  m[0] = m[1] = 1;
  for (long long i = 0; i < n; ++i) {
    cin >> t[i] >> l[i] >> r[i];
    m[l[i] - 1] = m[l[i]] = m[r[i]] = m[r[i] + 1] = 1;
  }
  long long cur = 0;
  for (auto &p : m) {
    p.second = cur;
    rev[cur++] = p.first;
  }
  for (long long i = 1; i < (N << 2); ++i) {
    lazy[i] = -1;
  }
  update(0, N - 1, 0, 0, 1, 1);
  for (long long i = 0; i < n; ++i) {
    l[i] = m[l[i]];
    r[i] = m[r[i]];
    if (t[i] == 1) {
      update(0, N - 1, l[i], r[i], 1, 1);
    } else if (t[i] == 2) {
      update(0, N - 1, l[i], r[i], 0, 1);
    } else {
      update2(0, N - 1, l[i], r[i], 1);
    }
    long long L = 1, R = N - 1;
    while (L < R) {
      long long M = (L + R) >> 1;
      if (query(0, N - 1, 0, M - 1, 1) == M) {
        L = M + 1;
      } else {
        R = M;
      }
    }
    cout << rev[L - 1] << '\n';
  }
  return 0;
}
