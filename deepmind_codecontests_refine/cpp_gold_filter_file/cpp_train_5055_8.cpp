#include <bits/stdc++.h>
using namespace std;
template <class T>
bool remin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
bool remax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int nxt() {
  int first;
  scanf("%d", &first);
  return first;
}
long long gcd(long long a, long long b) {
  a = abs(a);
  b = abs(b);
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
struct pt {
  long long first, second;
  pt() {}
  pt(long long first, long long second) : first(first), second(second) {}
  inline pt operator-(const pt &r) const {
    return pt(first - r.first, second - r.second);
  }
  inline pt operator+(const pt &r) const {
    return pt(first + r.first, second + r.second);
  }
  inline pt operator*(const long double &r) const {
    return pt(first * r, second * r);
  }
  inline long long sqlen() const {
    return abs(first * first + second * second);
  }
  inline bool operator<(const pt &r) const {
    if (first != r.first) return first < r.first;
    return second < r.second;
  }
  inline bool operator==(const pt &r) const {
    return first == r.first && second == r.second;
  }
};
ostream &operator<<(ostream &os, const pt &p) {
  return os << "(" << p.first << "," << p.second << ")";
}
inline long long cross(const pt &l, const pt &r) {
  return l.first * r.second - l.second * r.first;
}
inline long long dot(const pt &l, const pt &r) {
  return l.first * r.first + l.second * r.second;
}
long long pwmod(long long a, long long n, long long mod) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = ret * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ret;
}
template <typename T>
inline T sqr(T first) {
  return first * first;
}
class SegmentTreeMinAdd {
 public:
  SegmentTreeMinAdd() {}
  SegmentTreeMinAdd(int n) {
    valueMin.assign(2 * n, 0);
    valueMax.assign(2 * n, 0);
    delta.assign(2 * n, 0);
  }
  long long getMin(int from, int to) {
    from += valueMin.size() >> 1;
    to += valueMin.size() >> 1;
    pushDelta(from);
    pushDelta(to);
    long long res = LLONG_MAX - 10000;
    for (int len = 1; from <= to;
         from = (from + 1) >> 1, to = (to - 1) >> 1, len <<= 1) {
      if ((from & 1) != 0) {
        res = min(res, joinNodeValueWithDeltaMin(from, len));
      }
      if ((to & 1) == 0) {
        res = min(res, joinNodeValueWithDeltaMin(to, len));
      }
    }
    return res;
  }
  long long getMax(int from, int to) {
    from += valueMin.size() >> 1;
    to += valueMin.size() >> 1;
    pushDelta(from);
    pushDelta(to);
    long long res = LLONG_MIN + 10000;
    for (int len = 1; from <= to;
         from = (from + 1) >> 1, to = (to - 1) >> 1, len <<= 1) {
      if ((from & 1) != 0) {
        res = max(res, joinNodeValueWithDeltaMax(from, len));
      }
      if ((to & 1) == 0) {
        res = max(res, joinNodeValueWithDeltaMax(to, len));
      }
    }
    return res;
  }
  void add(int from, int to, long long val) {
    from += valueMin.size() >> 1;
    to += valueMin.size() >> 1;
    pushDelta(from);
    pushDelta(to);
    int a = from;
    int b = to;
    for (; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1) {
      if ((from & 1) != 0) {
        delta[from] = delta[from] + val;
      }
      if ((to & 1) == 0) {
        delta[to] = delta[to] + val;
      }
    }
    for (int i = a, len = 1; i > 1; i >>= 1, len <<= 1) {
      valueMin[i >> 1] = min(joinNodeValueWithDeltaMin(i, len),
                             joinNodeValueWithDeltaMin(i ^ 1, len));
      valueMax[i >> 1] = max(joinNodeValueWithDeltaMax(i, len),
                             joinNodeValueWithDeltaMax(i ^ 1, len));
    }
    for (int i = b, len = 1; i > 1; i >>= 1, len <<= 1) {
      valueMin[i >> 1] = min(joinNodeValueWithDeltaMin(i, len),
                             joinNodeValueWithDeltaMin(i ^ 1, len));
      valueMax[i >> 1] = max(joinNodeValueWithDeltaMax(i, len),
                             joinNodeValueWithDeltaMax(i ^ 1, len));
    }
  }

 private:
  vector<long long> valueMin;
  vector<long long> valueMax;
  vector<long long> delta;
  void pushDelta(int i) {
    int d = 0;
    for (; (i >> d) > 0; d++) {
    }
    for (d -= 2; d >= 0; d--) {
      int first = i >> d;
      valueMin[first >> 1] =
          joinNodeValueWithDeltaMin(first >> 1, 1 << (d + 1));
      valueMax[first >> 1] =
          joinNodeValueWithDeltaMax(first >> 1, 1 << (d + 1));
      delta[first] = delta[first] + delta[first >> 1];
      delta[first ^ 1] = delta[first ^ 1] + delta[first >> 1];
      delta[first >> 1] = 0;
    }
  }
  long long joinNodeValueWithDeltaMin(int i, int len) {
    return valueMin[i] + delta[i];
  }
  long long joinNodeValueWithDeltaMax(int i, int len) {
    return valueMax[i] + delta[i];
  }
} tree[2];
const int N = (int)2e5 + 100;
int a[N];
const int Q = (int)3e5 + 100;
int qt[Q], ql[Q], qr[Q], qk[Q];
bool ans[Q];
inline long long getSumSmall(int l, int r) {
  int ans = tree[r % 2].getMin(r / 2, r / 2);
  if (l != 0) ans -= tree[(l - 1) % 2].getMin((l - 1) / 2, (l - 1) / 2);
  if (r % 2 == 1) ans = -ans;
  if ((r - l + 1) % 2 == 1) ans = ans - 1;
  return ans;
}
inline void solve(int n, int q) {
  tree[0] = SegmentTreeMinAdd(n + 100);
  tree[1] = SegmentTreeMinAdd(n + 100);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0)
      sum += a[i];
    else
      sum -= a[i];
    tree[i % 2].add(i / 2, i / 2, sum);
  }
  for (int it = 0; it < q; it++) {
    if (qt[it] == 1) {
      int l = ql[it], r = qr[it], k = qk[it];
      if (l % 2 == 0) {
        tree[0].add(l / 2, r / 2, k);
        if (r % 2 == l % 2) {
          tree[0].add(r / 2 + 1, n / 2 + 1, k);
          tree[1].add((r + 1) / 2, n / 2 + 1, k);
        }
      } else {
        tree[1].add(l / 2, (r - 1) / 2, -k);
        if (r % 2 == l % 2) {
          tree[0].add((r + 1) / 2, n / 2 + 1, -k);
          tree[1].add((r + 1) / 2, n / 2 + 1, -k);
        }
      }
    } else {
      int l = ql[it], r = qr[it];
      if (getSumSmall(l, r) != 0) {
        continue;
      }
      int first = 0;
      if (l != 0) first = tree[(l - 1) % 2].getMin((l - 1) / 2, (l - 1) / 2);
      if (tree[0].getMin((l + 1) / 2, r / 2) - first + l % 2 <= 0) {
        continue;
      }
      if (first - tree[1].getMax(l / 2, (r - 1) / 2) + 1 - l % 2 <= 0) {
        continue;
      }
      ans[it] = true;
    }
  }
}
inline void solve() {
  int n, q;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &qt[i]);
    if (qt[i] == 1)
      scanf("%d%d%d", &ql[i], &qr[i], &qk[i]);
    else
      scanf("%d%d", &ql[i], &qr[i]);
  }
  solve(n, q);
  reverse(a, a + n);
  for (int i = 0; i < q; i++) {
    swap(ql[i], qr[i]);
    ql[i] = n - 1 - ql[i];
    qr[i] = n - 1 - qr[i];
  }
  solve(n, q);
  for (int i = 0; i < q; i++)
    if (qt[i] == 2) printf("%d\n", ans[i]);
}
void prepare() {}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  prepare();
  int t = 1;
  for (int i = 0; i < (int)(t); i++) {
    solve();
  }
  return 0;
}
