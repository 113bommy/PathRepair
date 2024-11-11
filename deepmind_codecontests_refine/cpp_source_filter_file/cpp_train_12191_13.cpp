#include <bits/stdc++.h>
using namespace std;
template <typename T>
void maxtt(T &t1, T t2) {
  t1 = max(t1, t2);
}
template <typename T>
void mintt(T &t1, T t2) {
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
void addmod(int &x, int y, int mod = 1000000007) {
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
map<vector<int>, int> mp;
vector<vector<int>> V;
int id[1000005];
int ps[1000005], f[1005], g[1005];
int dis[305][1005], ans[300][300];
int gid(vector<int> &vp) {
  if (mp.find(vp) != mp.end()) return mp[vp];
  V.push_back(vp);
  mp[vp] = V.size() - 1;
  return V.size() - 1;
}
void fmain(int ID) {
  int N = 1000000;
  for (int i = 2; i <= N; i++)
    if (!ps[i]) {
      for (int j = i; j <= N; j += i) {
        ps[j] = i;
      }
    }
  for (int i = 2; i <= N; i++) {
    map<int, int> vp;
    for (int j = i; j > 1; j /= ps[j]) {
      vp[ps[j]]++;
    }
    vector<int> vs;
    for (auto &p : vp) vs.push_back(p.second + 1);
    sort(vs.begin(), vs.end());
    id[i] = gid(vs);
  }
  for (int(i) = 0; (i) < (int)(V.size()); (i)++) {
    for (int(j) = 0; (j) < (int)(1000); (j)++) f[j] = N;
    f[1] = 0;
    for (int &y : V[i]) {
      swap(f, g);
      for (int(j) = 0; (j) < (int)(1000); (j)++) f[j] = N;
      for (int k = 1; k <= y + 10; k++) {
        for (int p = 1; p * k < 1000; p++) mintt(f[p * k], g[p] + abs(y - k));
      }
    }
    for (int(j) = 1; (j) <= (int)(999); (j)++)
      if (f[j] < N) {
        for (int k = 2; k * j < 1000; k++) mintt(f[k * j], f[j] + k - 1);
      }
    for (int(j) = 0; (j) < (int)(1000); (j)++) dis[i][j] = f[j];
  }
  for (int(i) = 0; (i) < (int)(V.size()); (i)++)
    for (int(j) = 0; (j) < (int)(V.size()); (j)++) {
      ans[i][j] = N;
      for (int(k) = 0; (k) < (int)(1000); (k)++)
        mintt(ans[i][j], dis[i][k] + dis[j][k]);
    }
  scanf("%d", &n);
  for (int(i) = 1; (i) <= (int)(n); (i)++) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", ans[id[x]][id[y]]);
  }
}
int main() {
  int t = 1;
  for (int(i) = 1; (i) <= (int)(t); (i)++) {
    fmain(i);
  }
  return 0;
}
