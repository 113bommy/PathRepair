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
int T, B = 20, in[(1135)], id[(1135)], nid[(1135)];
int val[(1 << 20) + 5], valToX[(1 << 20) + 5];
vector<int> mp[(1135)];
void init() {
  vector<tuple<char, int, int>> es;
  vector<int> vp;
  queue<int> q;
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    if (in[i] == 0) q.push(i);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    vp.push_back(x);
    for (int c : mp[x]) {
      in[c]--;
      if (in[c] == 0) q.push(c);
    }
  }
  for (int(i) = 1; (i) <= (int)(n); (i)++) nid[i] = -1;
  for (int(j) = 0; (j) < (int)(B); (j)++) {
    nid[vp[n - 1 - j]] = j;
    id[j] = vp[n - 1 - j];
  }
  vector<vector<bool>> vis(B + 1, vector<bool>(B + 1, 0));
  for (int(i) = 1; (i) <= (int)(B - 1); (i)++) {
    int x = id[i];
    for (int c : mp[x])
      if (nid[c] != -1 && nid[c] < i) {
        vis[i][nid[c]] = 1;
      }
    for (int j = 0; j < i; j++)
      if (!vis[i][j]) {
        es.push_back({'+', x, id[j]});
      }
  }
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    if (nid[i] == -1) {
      es.push_back({'+', i, i});
    }
  vector<int> msk[4];
  for (int(i) = 0; (i) < (int)(1 << B); (i)++) {
    int cc = __builtin_popcount(i);
    if (cc <= 3) msk[cc].push_back(i);
  }
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    if (nid[i] == -1) {
      for (int c : mp[i])
        if (nid[c] != -1) {
          val[i] |= 1 << nid[c];
        }
      if (valToX[val[i]] == 0) {
        valToX[val[i]] = i;
      }
    }
  auto cg = [&](int i) {
    for (int(z) = 1; (z) <= (int)(3); (z)++)
      for (int M : msk[z]) {
        int nm = val[i] ^ M;
        if (valToX[nm] == 0) {
          valToX[nm] = i;
          for (int(j) = 0; (j) < (int)(B); (j)++)
            if (M & (1 << j)) {
              int pre = (val[i] >> j) & 1;
              if (pre == 0) {
                es.push_back({'+', i, id[j]});
              } else
                es.push_back({'-', i, id[j]});
            }
          val[i] ^= M;
          return;
        }
      }
  };
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    if (nid[i] == -1 && valToX[val[i]] != i) {
      cg(i);
    }
  printf("%d\n", (int)es.size());
  for (auto [x, y, z] : es) printf("%c %d %d\n", x, y, z);
  fflush(stdout);
}
char rd(int x) {
  printf("? 1 %d\n", x);
  fflush(stdout);
  char ope[10];
  scanf("%s", ope);
  return ope[0];
}
void fmain(int tid) {
  scanf("%d%d%d", &n, &m, &T);
  mintt(B, n);
  for (int(i) = 1; (i) <= (int)(m); (i)++) {
    int u, v;
    scanf("%d%d", &u, &v);
    mp[u].push_back(v);
    in[v]++;
  }
  init();
  for (int(i) = 1; (i) <= (int)(T); (i)++) {
    int ans = -1;
    int M = 0;
    for (int(j) = 1; (j) <= (int)(B); (j)++) {
      char X = rd(id[j]);
      if (X == 'L') {
        ans = id[j];
        break;
      } else if (X == 'W')
        M |= 1 << j;
    }
    if (ans == -1) ans = valToX[M];
    printf("! %d\n", ans);
    fflush(stdout);
    char ope[20];
    scanf("%s", ope);
    if (ope[0] == 'W') exit(0);
  }
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
