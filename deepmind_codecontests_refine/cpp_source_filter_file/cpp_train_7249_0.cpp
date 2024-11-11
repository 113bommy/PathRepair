#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
const int P = 1e9 + 7;
const int inf = 1e9;
const long long Inf = 1e18;
inline int IN() {
  char ch = getchar();
  int x = 0, f = 0;
  while (ch < '0' || ch > '9') ch = getchar(), f = (ch == '-');
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + ch - 48;
    ch = getchar();
  }
  return f ? (-x) : x;
}
inline int Pow(int x, int y, int p) {
  int an = 1;
  for (; y; y >>= 1, x = (long long)x * x % p)
    if (y & 1) an = (long long)an * x % p;
  return an;
}
void renew(int &x, int y) {
  x += y;
  if (x < 0)
    x += P;
  else if (x >= P)
    x -= P;
}
void setIO(string a) {
  freopen((a + ".in").c_str(), "r", stdin);
  freopen((a + ".out").c_str(), "w", stdout);
}
template <typename T>
inline void chkmin(T &a, const T &b) {
  if (a > b) a = b;
}
template <typename T>
inline void chkmax(T &a, const T &b) {
  if (a < b) a = b;
}
int pos[1005], val[1005], gt[1005], clz[265], x, k, n, q;
long long mat[26][95][95], ss[95], tmp[95], vec[95];
long long E[95][95], cnt, stat[265], id[265], dp[16][95];
vector<pair<int, int> > ee[95];
inline int cmp(const int &a, const int &b) { return pos[a] < pos[b]; }
void Pow(int x) {
  for (int i = (int)0; i <= (int)26; i++)
    if ((x >> i) & 1) {
      for (int t = (int)1; t <= (int)cnt; t++) tmp[t] = 1LL << 60;
      for (int k = (int)1; k <= (int)cnt; k++)
        for (int y = (int)1; y <= (int)cnt; y++)
          tmp[y] = min(tmp[y], vec[k] + mat[i][k][y]);
      for (int t = (int)1; t <= (int)cnt; t++) vec[t] = tmp[t];
    }
}
long long find(long long x) {
  int l = 1, r = q, aim = q + 1;
  while (l <= r) {
    int md = (l + r) / 2;
    if (pos[gt[md]] <= x) {
      aim = md;
      l = md + 1;
    } else {
      r = md - 1;
    }
  }
  if (aim > q) return 0;
  if (pos[gt[aim]] == x)
    return val[gt[aim]];
  else
    return 0;
}
int main() {
  scanf("%d%d%d%d", &x, &k, &n, &q);
  memset(vec, 0x3f, sizeof vec);
  for (int i = (int)1; i <= (int)k; i++) scanf("%lld", ss + i);
  for (int a = (int)0; a <= (int)(1 << k) - 1; a++)
    clz[a] = clz[a >> 1] + (a & 1);
  memset(E, 0x3f, sizeof E);
  for (int a = (int)0; a <= (int)(1 << k) - 1; a++)
    if (clz[a] == x) {
      ++cnt;
      stat[cnt] = a;
      id[a] = cnt;
    }
  vec[id[(1 << x) - 1]] = 0;
  for (int i = (int)1; i <= (int)cnt; i++) {
    int a = stat[i];
    if (a % 2 == 0) {
      E[id[a]][id[a / 2]] = 0;
      ee[id[a]].push_back(make_pair(id[a / 2], -1));
    } else {
      int b = a >> 1;
      for (int t = (int)1; t <= (int)k; t++) {
        if ((b >> (t - 1)) & 1) continue;
        int c = b | (1 << (t - 1));
        assert(id[c] != 0);
        E[id[a]][id[c]] = ss[t];
        ee[id[a]].push_back(make_pair(id[c], t));
      }
    }
  }
  memcpy(mat[0], E, sizeof mat[0]);
  for (int w = (int)1; w <= (int)25; w++) {
    memset(mat[w], 0x3f, sizeof mat[w]);
    for (int k = (int)1; k <= (int)cnt; k++)
      for (int i = (int)1; i <= (int)cnt; i++)
        for (int j = (int)1; j <= (int)cnt; j++) {
          mat[w][i][j] = min(mat[w][i][j], mat[w - 1][i][k] + mat[w - 1][k][j]);
        }
  }
  bool hs = 0;
  for (int i = (int)1; i <= (int)q; i++) {
    int dx, y;
    scanf("%d%d", &dx, &y);
    pos[i] = dx;
    if (dx == n - x + 1) hs = 1;
    val[i] = y;
    gt[i] = i;
  }
  if (!hs) {
    ++q;
    pos[q] = n - x + 1;
    val[q] = 0;
    gt[q] = q;
  }
  sort(gt + 1, gt + q + 1, cmp);
  int pre = 1;
  for (int z = (int)1; z <= (int)q; z++) {
    long long now = pos[gt[z]], valx = val[gt[z]];
    Pow(max(now - k, (long long)pre) - pre);
    {
      long long st = max(now - k, (long long)pre), ed = now;
      for (int i = (int)0; i <= (int)10; i++)
        for (int j = (int)1; j <= (int)cnt; j++) dp[i][j] = 1LL << 60;
      for (int j = (int)1; j <= (int)cnt; j++) dp[now - st][j] = vec[j];
      for (int tt = (int)now - st; tt >= (int)1; tt--) {
        for (int j = (int)1; j <= (int)cnt; j++)
          for (auto k : ee[j]) {
            long long val = E[j][k.first];
            if (k.second != -1) {
              val += find(now - tt + k.second);
            }
            dp[tt - 1][k.first] = min(dp[tt - 1][k.first], dp[tt][j] + val);
          }
      }
    }
    for (int i = (int)1; i <= (int)cnt; i++) vec[i] = dp[0][i];
    if (now == n - x + 1) break;
    pre = now;
  }
  printf("%lld\n", vec[id[(1 << x) - 1]]);
  return 0;
}
