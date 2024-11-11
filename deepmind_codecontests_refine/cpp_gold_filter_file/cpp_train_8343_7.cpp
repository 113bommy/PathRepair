#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const int MOD = 1000000007;
const int UNDEF = -1;
const int INF = 1 << 30;
template <typename T>
inline bool chkmax(T &aa, T bb) {
  return aa < bb ? aa = bb, true : false;
}
template <typename T>
inline bool chkmin(T &aa, T bb) {
  return aa > bb ? aa = bb, true : false;
}
int rint();
char rch();
long long rlong();
const int mn = 2e5 + 4;
class SegmentTreeFast {
 public:
  long long modifyOperation(long long x, long long y) { return x + y; }
  long long queryOperation(long long l, long long r) { return max(l, r); }
  long long deltaEffectOnSegment(long long delta, int segmentLength) {
    return delta;
  }
  long long initNeutralDelta() { return 0; }
  bool isNeutralDelta(long long delta) { return delta == 0; }
  long long getInitValue(int i) { return 0; }
  long long getNeutralValue() { return 0; }
  long long joinDeltas(long long delta1, long long delta2) {
    return delta1 + delta2;
  }
  long long _cache_neutral_delta;
  long long getNeutralDelta() { return _cache_neutral_delta; }
  long long *value;
  long long *delta;
  int gn;
  long long joinValueWithDelta(long long value, long long delta) {
    if (isNeutralDelta(delta)) return value;
    return modifyOperation(value, delta);
  }
  void pushDelta(int i) {
    int d = 0;
    for (; (i >> d) > 0; d++) {
    }
    for (d -= 2; d >= 0; d--) {
      int x = i >> d;
      value[x >> 1] = joinNodeValueWithDelta(x >> 1, 1 << (d + 1));
      delta[x] = joinDeltas(delta[x], delta[x >> 1]);
      delta[x ^ 1] = joinDeltas(delta[x ^ 1], delta[x >> 1]);
      delta[x >> 1] = getNeutralDelta();
    }
  }
  SegmentTreeFast(int n) {
    _cache_neutral_delta = initNeutralDelta();
    gn = n;
    value = new long long[2 * n];
    for (int i = 0; i < n; i++) {
      value[i + n] = getInitValue(i);
    }
    for (int i = n - 1; i > 0; --i)
      value[i] = queryOperation(value[i << 1], value[i << 1 | 1]);
    delta = new long long[2 * n];
    fill(delta, delta + (2 * n), getNeutralDelta());
  }
  long long joinNodeValueWithDelta(int i, int len) {
    return joinValueWithDelta(value[i], deltaEffectOnSegment(delta[i], len));
  }
  long long query(int from, int to) {
    from += gn;
    to += gn;
    pushDelta(from);
    pushDelta(to);
    long long resl = getNeutralValue();
    long long resr = getNeutralValue();
    bool found = false;
    for (int len = 1; from <= to;
         from = (from + 1) >> 1, to = (to - 1) >> 1, len <<= 1) {
      if ((from & 1) != 0) {
        resl = found ? queryOperation(resl, joinNodeValueWithDelta(from, len))
                     : joinNodeValueWithDelta(from, len);
        found = true;
      }
      if ((to & 1) == 0) {
        resr = found ? queryOperation(joinNodeValueWithDelta(to, len), resr)
                     : joinNodeValueWithDelta(to, len);
        found = true;
      }
    }
    long long res = queryOperation(resl, resr);
    if (!found)
      ;
    return res;
  }
  void modify(int from, int to, long long delta) {
    from += gn;
    to += gn;
    pushDelta(from);
    pushDelta(to);
    int a = from;
    int b = to;
    for (; from <= to; from = (from + 1) >> 1, to = (to - 1) >> 1) {
      if ((from & 1) != 0) {
        this->delta[from] = joinDeltas(this->delta[from], delta);
      }
      if ((to & 1) == 0) {
        this->delta[to] = joinDeltas(this->delta[to], delta);
      }
    }
    for (int i = a, len = 1; i > 1; i >>= 1, len <<= 1) {
      int k = i >> 1;
      value[k] = queryOperation(joinNodeValueWithDelta(k << 1, len),
                                joinNodeValueWithDelta((k << 1) | 1, len));
    }
    for (int i = b, len = 1; i > 1; i >>= 1, len <<= 1) {
      int k = i >> 1;
      value[k] = queryOperation(joinNodeValueWithDelta(k << 1, len),
                                joinNodeValueWithDelta((k << 1) | 1, len));
    }
  }
};
int c[mn];
vector<pair<int, int> > r2lp[mn];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n = rint();
  SegmentTreeFast seg = SegmentTreeFast(n + 2);
  int m = rint();
  for (int x = 1; x <= n; x++) c[x] = rint();
  for (int i = 1; i <= m; i++) {
    int l = rint(), r = rint(), p = rint();
    r2lp[r].push_back(make_pair(l, p));
  }
  for (int x = 1; x <= n; x++) {
    {
      long long best = seg.query(0, n + 1);
      seg.modify(x + 1, x + 1, best);
    }
    {
      sort(r2lp[x].begin(), r2lp[x].end());
      for (auto &w : r2lp[x]) {
        int l = w.first, p = w.second;
        seg.modify(0, l, p);
      }
      seg.modify(0, x, -c[x]);
    }
  }
  long long final = seg.query(0, n + 1);
  printf("%lld\n", final);
}
static char stdinBuffer[1024];
static char *stdinDataEnd = stdinBuffer + sizeof(stdinBuffer);
static const char *stdinPos = stdinDataEnd;
void readAhead(size_t amount) {
  size_t remaining = stdinDataEnd - stdinPos;
  if (remaining < amount) {
    memmove(stdinBuffer, stdinPos, remaining);
    size_t sz = fread(stdinBuffer + remaining, 1,
                      sizeof(stdinBuffer) - remaining, stdin);
    stdinPos = stdinBuffer;
    stdinDataEnd = stdinBuffer + remaining + sz;
    if (stdinDataEnd != stdinBuffer + sizeof(stdinBuffer)) *stdinDataEnd = 0;
  }
}
int rint() {
  readAhead(16);
  int x = 0;
  bool neg = false;
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  if (*stdinPos == '-') {
    ++stdinPos;
    neg = true;
  }
  while (*stdinPos >= '0' && *stdinPos <= '9') {
    x *= 10;
    x += *stdinPos - '0';
    ++stdinPos;
  }
  return neg ? -x : x;
}
char rch() {
  readAhead(16);
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  char ans = *stdinPos;
  ++stdinPos;
  return ans;
}
long long rlong() {
  readAhead(32);
  long long x = 0;
  bool neg = false;
  while (*stdinPos == ' ' || *stdinPos == '\n') ++stdinPos;
  if (*stdinPos == '-') {
    ++stdinPos;
    neg = true;
  }
  while (*stdinPos >= '0' && *stdinPos <= '9') {
    x *= 10;
    x += *stdinPos - '0';
    ++stdinPos;
  }
  return neg ? -x : x;
}
