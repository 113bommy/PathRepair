#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f, oo = inf;
inline long long read() {
  register long long x = 0;
  char f = 0;
  register char c = getchar();
  for (; !isdigit(c); c = getchar()) f |= (c == '-');
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  return f ? -x : x;
}
inline void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(long long x) {
  write(x);
  puts("");
}
inline void writeln(long long x, char c, long long y) {
  write(x);
  putchar(c);
  writeln(y);
}
inline void writeln(long long x, char c, long long y, char d, long long z) {
  write(x);
  putchar(c);
  write(y);
  putchar(d);
  writeln(z);
}
namespace My {
const long long maxn = 500500;
unordered_map<long long, bool> make_pair;
long long hash[maxn], pw[maxn];
long long dp[maxn];
char s[maxn];
long long n;
const long long base = 71;
long long get(long long l, long long r) {
  if (l > r) return 0;
  return hash[r] - hash[l - 1] * pw[r - l + 1];
}
bool query(long long x) { return make_pair.find(x) != make_pair.end(); }
bool check(long long l, long long r) {
  return query(get(l, r - 1)) || query(get(l + 1, r));
}
void Add(long long pos) {
  long long len = dp[pos];
  while (len) {
    long long tmp = get(pos, pos + len - 1);
    if (query(tmp)) break;
    make_pair[tmp] = true;
    len--;
  }
}
long long main() {
  n = read();
  scanf("%s", s + 1);
  pw[0] = 1, hash[0] = 0;
  for (register long long i = (1); i <= (n); ++i) {
    hash[i] = hash[i - 1] * base + s[i] - 'a' + 1;
    pw[i] = pw[i - 1] * base;
  }
  long long ans = 0;
  make_pair[0] = true;
  dp[n + 1] = 0;
  for (register long long i = (n); i >= (1); --i) {
    dp[i] = dp[i + 1] + 1;
    while (!check(i, i + dp[i] - 1)) {
      --dp[i];
      Add(i + dp[i]);
    }
    ans = max(ans, dp[i]);
  }
  writeln(ans);
  return 0;
}
}  // namespace My
int main() { My::main(); }
