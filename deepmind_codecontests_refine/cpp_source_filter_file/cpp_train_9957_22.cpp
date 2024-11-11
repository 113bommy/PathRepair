#include <bits/stdc++.h>
using namespace std;
bool debug = 0;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int &x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et() {
  puts("-1");
  exit(0);
}
long long fastPow(long long x, long long y, int mod = 1000000007) {
  long long ans = 1;
  while (y > 0) {
    if (y & 1) ans = (x * ans) % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ans;
}
long long gcd1(long long x, long long y) {
  long long z = y;
  while (x % y != 0) {
    z = x % y;
    x = y;
    y = z;
  }
  return z;
}
int c[300105], ss;
vector<int> ps;
bool vis[300105], del[300105];
void fmain(int ID) {
  scanf("%d%d", &n, &k);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    if (vis[i] == 0 && i != 1) ps.push_back(i);
    for (int j = i + i; j <= n; j += i) {
      c[j]++;
      if (i != 1) vis[j] = 1;
    }
  }
  for (m = 2; m <= n; m++) {
    ss += c[m];
    if (k < ss) break;
  }
  if (ss < k) etp();
  for (int P : ps) {
    int t = m / P;
    if (ss - t >= k) {
      ss -= t;
      del[P] = 1;
    }
    if (ss == k) break;
  }
  assert(ss == k);
  puts("Yes");
  ps.clear();
  for (int(i) = 1; (i) <= (int)(m); (i)++)
    if (!del[i]) ps.push_back(i);
  printf("%d\n", ps.size());
  for (int c : ps) printf("%d ", c);
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
