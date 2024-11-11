#include <bits/stdc++.h>
#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("avx2")
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
const long long MOD2 = (long long)998244353 * (long long)998244353;
long long ln, lk, lm;
void etp(bool f = 0) {
  puts(f ? "YES" : "NO");
  exit(0);
}
void addmod(int& x, int y, int mod = 998244353) {
  x += y;
  if (x >= mod) x -= mod;
  if (x < 0) x += mod;
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
bitset<2135> a[2135];
int pos[2135], ans[2135];
bool gauss(int n, int m) {
  int d = 1;
  for (int(j) = 1; (j) <= (int)(m); (j)++) {
    int i = d;
    while (i <= n && a[i][j] == 0) i++;
    if (i == n + 1) continue;
    if (i != d) swap(a[i], a[d]);
    pos[d] = j;
    for (int k = 1; k <= n; k++)
      if (k != d && a[k][j] == 1) {
        a[k] ^= a[d];
      }
    d++;
  }
  for (int i = d; i <= n; i++)
    if (a[i][m + 1]) return 0;
  for (int(i) = 1; (i) <= (int)(d - 1); (i)++) ans[pos[i]] = a[i][m + 1];
  return 1;
}
int ins[2135];
void fmain(int tid) {
  scanf("%d%d", &n, &m);
  map<char, int> mp;
  mp['W'] = 0;
  mp['R'] = 1;
  mp['Y'] = 2;
  mp['B'] = 3;
  vector<vector<int>> num(n + 1, vector<int>(4, 0));
  for (int(i) = 1; (i) <= (int)(n); (i)++) num[i][0] = num[i][3] = 1;
  char ope[10];
  int cnt = 0;
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    scanf("%s%d", ope, &k);
    for (int(j) = 1; (j) <= (int)(k); (j)++) scanf("%d", ins + j);
    if (ope[0] == 'm') {
      scanf("%s", ope);
      int val = mp[ope[0]];
      cnt++;
      for (int(j) = 1; (j) <= (int)(k); (j)++) {
        int x = ins[j];
        if (num[x][0]) a[cnt][x * 2 - 1] = 1;
        if (num[x][1]) a[cnt][x * 2] = 1;
      }
      a[cnt][n * 2 + 1] = val & 1;
      cnt++;
      for (int(j) = 1; (j) <= (int)(k); (j)++) {
        int x = ins[j];
        if (num[x][2]) a[cnt][x * 2 - 1] = 1;
        if (num[x][3]) a[cnt][x * 2] = 1;
      }
      a[cnt][n * 2 + 1] = (val >> 1) & 1;
    } else if (ope[0] == 'R' && ope[1] == 'Y') {
      for (int(j) = 1; (j) <= (int)(k); (j)++) {
        int x = ins[j];
        swap(num[x][0], num[x][2]);
        swap(num[x][1], num[x][3]);
      }
    } else if (ope[0] == 'R') {
      for (int(j) = 1; (j) <= (int)(k); (j)++) {
        int x = ins[j];
        num[x][2] ^= num[x][0];
        num[x][3] ^= num[x][1];
      }
    } else {
      for (int(j) = 1; (j) <= (int)(k); (j)++) {
        int x = ins[j];
        num[x][0] ^= num[x][2];
        num[x][1] ^= num[x][3];
      }
    }
  }
  if (!gauss(cnt, n * 2)) etp();
  puts("YES");
  string S = ".RYB";
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    int z = ans[i * 2 - 1] ^ (ans[i << 1] << 1);
    printf("%c", S[z]);
  }
  puts("");
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
