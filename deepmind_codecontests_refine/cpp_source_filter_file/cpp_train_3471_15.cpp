#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int UNDEF = -1;
const long long INF = 1e18;
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
const int mn = 1e5 + 4;
int a[mn];
long long pqs = 0;
priority_queue<int, vector<int>, greater<int> > pq;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n = rint(), k = rint();
  long long b = rlong();
  for (int x = 1; x <= n; x++) a[x] = rint();
  int final = n;
  for (int x = n - 1; x >= 1; x--) {
    long long need = pqs + a[x];
    if (b <= need) chkmin(final, x);
    pq.push(a[x]);
    pqs += a[x];
    if (pq.size() > k - 1) {
      pqs -= pq.top();
      pq.pop();
    }
  }
  printf("%d\n", final);
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
