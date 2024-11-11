#include <bits/stdc++.h>
using namespace std;
const int LEN = 100000;
struct fastio {
  int it, len;
  char s[LEN + 5];
  fastio() { it = len = 0; }
  char get() {
    if (it < len) return s[it++];
    it = 0, len = fread(s, 1, LEN, stdin);
    return len ? s[it++] : EOF;
  }
  bool notend() {
    char c;
    for (c = get(); c == ' ' || c == '\n' || c == '\r'; c = get())
      ;
    if (it) it--;
    return c != EOF;
  }
  void put(char c) {
    if (it == LEN) fwrite(s, 1, LEN, stdout), it = 0;
    s[it++] = c;
  }
  void flush() { fwrite(s, 1, it, stdout); }
} buff, bufo;
inline int getint() {
  char c;
  int res = 0, sig = 1;
  for (c = buff.get(); c < '0' || c > '9'; c = buff.get())
    if (c == '-') sig = -1;
  for (; c >= '0' && c <= '9'; c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline long long getll() {
  char c;
  long long res = 0, sig = 1;
  for (c = buff.get(); c < '0' || c > '9'; c = buff.get())
    if (c == '-') sig = -1;
  for (; c >= '0' && c <= '9'; c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline void putint(int x, char suf) {
  if (!x)
    bufo.put('0');
  else {
    if (x < 0) bufo.put('-'), x = -x;
    int k = 0;
    char s[15];
    while (x) {
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for (; k; k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline void putll(long long x, char suf) {
  if (!x)
    bufo.put('0');
  else {
    if (x < 0) bufo.put('-'), x = -x;
    int k = 0;
    char s[25];
    while (x) {
      s[++k] = x % 10 + '0';
      x /= 10;
    }
    for (; k; k--) bufo.put(s[k]);
  }
  bufo.put(suf);
}
inline char get_char() {
  char c;
  for (c = buff.get(); c == ' ' || c == '\n' || c == '\r'; c = buff.get())
    ;
  return c;
}
set<string> S;
void dfs(string s) {
  if (S.find(s) != S.end()) return;
  S.insert(s);
  char s1[] = {s[1], s[2], s[3], s[0], s[4], s[5], 0};
  dfs(s1);
  char s2[] = {s[0], s[4], s[2], s[5], s[3], s[1], 0};
  dfs(s2);
}
string s;
int main() {
  int ans = 0;
  cin >> s;
  sort(s.begin(), s.end());
  do {
    if (S.find(s) != S.end()) continue;
    ans++;
    dfs(s);
  } while (next_permutation(s.begin(), s.end()));
  cout << ans << endl;
  return 0;
}
