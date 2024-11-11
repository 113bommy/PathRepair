#include <bits/stdc++.h>
using namespace std;
namespace fastio {
char in[100000];
int itr = 0, llen = 0;
char get() {
  if (itr == llen) llen = fread(in, 1, 100000, stdin), itr = 0;
  if (llen == 0) return EOF;
  return in[itr++];
}
char out[100000];
int itr2 = 0;
void put(char c) {
  out[itr2++] = c;
  if (itr2 == 100000) {
    fwrite(out, 1, 100000, stdout);
    itr2 = 0;
  }
}
int clear() {
  fwrite(out, 1, itr2, stdout);
  itr2 = 0;
  return 0;
}
int getint() {
  int ret = 0;
  char ch = get();
  while (ch < '0' || ch > '9') {
    ch = get();
    if (ch == '-') return -getint();
  }
  while ('0' <= ch && ch <= '9') {
    ret = ret * 10 - 48 + ch;
    ch = get();
  }
  return ret;
}
string getstr() {
  string ret = "";
  char ch = get();
  while (ch == ' ' || ch == '\n') ch = get();
  while (ch != ' ' && ch != '\n') ret.push_back(ch), ch = get();
  return ret;
}
void putstr(string s) {
  for (int i = 0; i < s.size(); i++) put(s[i]);
}
void putint(int x) {
  if (x < 0) {
    put('-');
    putint(-x);
    return;
  }
  if (x == 0) {
    put('0');
    return;
  }
  char c[40];
  int pos = 0;
  while (x) {
    c[pos++] = '0' + x % 10;
    x /= 10;
  }
  for (int i = pos - 1; i >= 0; i--) put(c[i]);
  put(' ');
}
void putln(int x) {
  if (x < 0) {
    put('-');
    putint(-x);
    return;
  }
  if (x == 0) {
    put('0');
    put('\n');
    return;
  }
  char c[40];
  int pos = 0;
  while (x) {
    c[pos++] = '0' + x % 10;
    x /= 10;
  }
  for (int i = pos - 1; i >= 0; i--) put(c[i]);
  put('\n');
}
}  // namespace fastio
using namespace fastio;
const int inf = 0x3f3f3f3f;
const double eps = 1e-6;
const int mod = 1000000007;
int modpow(int x, int y, int md = mod) {
  if (y == 0) return 1;
  int ret = modpow(x, y >> 1, md);
  ret = (long long)ret * ret % md;
  if (y & 1) ret = (long long)ret * x % md;
  return ret;
}
int n, m;
int like[1 << 9];
int best[1 << 9], best2[1 << 9], id2[1 << 9], id[1 << 9];
int Best[1 << 9], cnt[1 << 9];
pair<int, int> ans[1 << 9];
int main() {
  n = getint();
  m = getint();
  for (int i = 1; i <= n; i++) {
    int mask = 0;
    int t = getint();
    while (t--) {
      mask |= 1 << getint() - 1;
    }
    like[mask]++;
  }
  memset(id, -1, sizeof id);
  memset(id2, -1, sizeof id2);
  for (int i = 1; i <= m; i++) {
    int mask = 0;
    int _c = getint(), t = getint();
    while (t--) {
      mask |= 1 << getint() - 1;
    }
    if (id2[mask] == -1 || _c < best2[mask]) {
      best2[mask] = _c;
      id2[mask] = i;
    }
    if (id[mask] == -1 || best2[mask] < best[mask]) {
      swap(id[mask], id2[mask]);
      swap(best[mask], best2[mask]);
    }
  }
  for (int i = 0; i < (1 << 9); i++) Best[i] = 2e9 + 10;
  for (int mask1 = 0; mask1 < (1 << 9); mask1++) {
    for (int mask2 = 0; mask2 < (1 << 9); mask2++) {
      if (id[mask1] == -1 || id[mask2] == -1) continue;
      if (mask1 == mask2) {
        if (id2[mask2] == -1) continue;
        if (best[mask1] + best2[mask2] < Best[mask1 | mask2]) {
          Best[mask1 | mask2] = best[mask1] + best2[mask2];
          ans[mask1 | mask2] = make_pair(id[mask1], id2[mask2]);
        }
        continue;
      }
      if (best[mask1] + best[mask2] < Best[mask1 | mask2]) {
        Best[mask1 | mask2] = best[mask1] + best[mask2];
        ans[mask1 | mask2] = make_pair(id[mask1], id[mask2]);
      }
    }
  }
  for (int mask1 = 0; mask1 < (1 << 9); mask1++) {
    for (int mask2 = 0; mask2 < (1 << 9); mask2++) {
      if ((mask1 | mask2) == mask1) {
        cnt[mask1] += like[mask2];
      }
    }
  }
  pair<int, int> Final(-1, -1);
  for (int i = 0; i < (1 << 9); i++) {
    if (Best[i] != 2e9 + 10) Final = max(Final, make_pair(cnt[i], -Best[i]));
  }
  for (int i = 0; i < (1 << 9); i++) {
    if (cnt[i] == Final.first && Best[i] == -Final.second) {
      cout << ans[i].first << " " << ans[i].second << endl;
      return 0;
    }
  }
  return 0;
}
