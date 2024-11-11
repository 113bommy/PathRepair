#include <bits/stdc++.h>
using namespace std;
using ll = long long;
namespace _buff {
const size_t BUFF = 1e5;
char buff[BUFF], *begin = buff, *end = buff;
char getc() {
  if (begin == end) end = (begin = buff) + fread(buff, 1, BUFF, stdin);
  return begin == end ? -1 : *begin++;
}
}  // namespace _buff
ll read() {
  using namespace _buff;
  ll ret = 0;
  bool pos = true;
  char c = getc();
  for (; (c < '0' || c > '9') && c != '-'; c = getc()) assert(~c);
  if (c == '-') {
    pos = false;
    c = getc();
  }
  for (; c >= '0' && c <= '9'; c = getc())
    ret = (ret << 3) + (ret << 1) + (c ^ 48);
  return pos ? ret : -ret;
}
const size_t N = 2e5 + 5;
ll a[N], b_low[N], b_up[N], b[N];
void chkMin(ll &dp, ll val) {
  if (val < dp) dp = val;
}
void chkMax(ll &dp, ll val) {
  if (val > dp) dp = val;
}
int main() {
  int n = read();
  ll t = read();
  for (int i = 0; i < n; ++i) {
    a[i] = read();
  }
  a[n] = 3e18 + 5;
  set<int> s;
  for (int i = 0; i < n; ++i) {
    b_low[i] = a[i] + t;
    b_up[i] = 4e18;
    s.emplace(i);
  }
  for (int i = 0; i < n; ++i) {
    int k = read() - 1;
    if (k < i) {
      return puts("No"), 0;
    }
    chkMin(b_up[i], a[k + 1] + t);
    auto it = s.upper_bound(i);
    while (it != s.end() && *it <= k) {
      chkMax(b_low[*it - 1], a[*it] + t);
      it = s.erase(it);
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i) chkMax(b_low[i], b[i - 1] + 1);
    if (b_low[i] >= b_up[i]) {
      return puts("No"), 0;
    }
    b[i] = b_low[i];
  }
  puts("Yes");
  for (int i = 0; i < n; ++i) {
    printf("%lld%c", b[i], "\n "[i < n - 1]);
  }
  return 0;
}
