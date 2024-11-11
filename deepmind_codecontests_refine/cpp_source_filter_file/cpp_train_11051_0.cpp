#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,mmx,avx,tune=native")
using namespace std;
const int MOD = 1000000007;
const int UNDEF = -1;
const int INF = 1 << 30;
template <typename T>
inline bool chkmax(T& aa, T bb) {
  return aa < bb ? aa = bb, true : false;
}
template <typename T>
inline bool chkmin(T& aa, T bb) {
  return aa > bb ? aa = bb, true : false;
}
int rint();
char rch();
long long rlong();
const int mn = 1e5 + 2;
long long b[mn], g[mn];
void fail() {
  printf("-1\n");
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n = rint(), m = rint();
  for (int i = 1; i <= n; i++) b[i] = rint();
  for (int i = 1; i <= m; i++) g[i] = rint();
  sort(b + 1, b + m + 1, greater<long long>());
  sort(g + 1, g + m + 1, greater<long long>());
  for (int i = 1; i <= m; i++) {
    if (g[i] < b[1]) fail();
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += b[i] * (long long)m;
  long long idx = 1, cnt = m - 1;
  for (int j = 1; j <= m; j++) {
    if (g[j] <= b[1]) break;
    ;
    if (cnt == 0) {
      ++idx;
      cnt = m - 1;
      if (idx >= n) fail();
    }
    long long need = g[j] - b[idx];
    ans += need;
    ;
    cnt--;
  }
  printf("%lld\n", ans);
}
static char stdinBuffer[1024];
static char* stdinDataEnd = stdinBuffer + sizeof(stdinBuffer);
static const char* stdinPos = stdinDataEnd;
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
