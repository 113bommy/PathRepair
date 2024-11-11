#include <bits/stdc++.h>
using namespace std;
template <typename T>
void maxtt(T& t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T& t1, T t2) {
  t1 = min(t1, t2);
}
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "URDL";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 998244353) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 998244353) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
string S = "RPS";
int gid(char x) {
  for (int(i) = 0; (i) < (int)(3); (i)++)
    if (S[i] == x) return i;
  return -1;
}
struct fw {
  int b[200135];
  void update(int x, int v) {
    for (int i = x; i <= n; i += i & -i) {
      b[i] += v;
    }
  }
  int query(int x) {
    int ret = 0;
    for (; x > 0; ret += b[x], x -= x & -x)
      ;
    return ret;
  }
  int qy(int l, int r) { return query(r) - query(l - 1); }
} t[3];
char s[200135];
set<int> sp[3];
int ppt() {
  for (int(i) = 0; (i) < (int)(3); (i)++)
    if (sp[i].size() == n) return n;
  if (sp[0].empty()) return sp[2].size();
  if (sp[1].empty()) return sp[0].size();
  if (sp[2].empty()) return sp[1].size();
  int r0 = *sp[0].begin(), r1 = *sp[0].rbegin();
  int p0 = *sp[1].begin(), p1 = *sp[1].rbegin();
  int s0 = *sp[2].begin(), s1 = *sp[2].rbegin();
  int ans = n;
  if (p0 < s0) ans -= t[0].qy(p0, s0);
  if (s1 < p1) ans -= t[0].qy(s1, p1);
  if (s0 < r0) ans -= t[1].qy(s0, r0);
  if (r1 < s1) ans -= t[1].qy(r1, s1);
  if (r0 < p0) ans -= t[2].qy(r0, p0);
  if (p1 < r1) ans -= t[2].qy(p1, r1);
  return ans;
}
void fmain(int tid) {
  scanf("%d%d", &n, &m);
  scanf("%s", s + 1);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    int j = gid(s[i]);
    t[j].update(i, 1);
    sp[j].insert(i);
  }
  printf("%d\n", ppt());
  char ope[3];
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    scanf("%d%s", &k, ope);
    int j = gid(s[k]);
    t[j].update(k, -1);
    sp[j].erase(k);
    s[k] = ope[0];
    j = gid(s[k]);
    t[j].update(k, 1);
    sp[j].insert(k);
    printf("%d\n", ppt());
  }
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
