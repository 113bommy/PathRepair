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
string direc = "RDLU";
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 1000000007) {
  assert(y >= 0);
  x += y;
  if (x >= mod) x -= mod;
  assert(x >= 0 && x < mod);
}
void et(int x = -1) {
  printf("%d\n", x);
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
long long gcd1(long long x, long long y) { return y ? gcd1(y, x % y) : x; }
const long long M = 10004205361450474LL;
vector<long long> vp;
int rd() {
  cout << vp.size();
  for (long long z : vp) cout << " " << z;
  cout << endl;
  int x;
  cin >> x;
  if (x < 0) exit(0);
  vp.clear();
  return x;
}
long long dp[10005][6];
long long dfs(long long l, int q) {
  if (q == 0) return 0;
  mintt(l, 10000LL);
  if (dp[l][q]) return dp[l][q];
  long long r = l;
  for (int(i) = 1; (i) <= (int)(l); (i)++) {
    r += dfs(r, q - 1) + 1;
  }
  r += dfs(r, q - 1);
  return dp[l][q] = r - l;
}
void fmain(int ID) {
  long long pos = 1;
  for (int(i) = 1; (i) <= (int)(5); (i)++) {
    long long r = pos;
    for (long long j = 1; j <= min(pos, 10000LL); j++) {
      r += dfs(r, 5 - i);
      vp.push_back(r);
      r++;
    }
    int ans = rd();
    if (ans == 0) continue;
    pos = vp[ans - 1] + 1;
  }
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
