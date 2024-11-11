#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const double eps = 1e-12;
const int step[8][2] = {{1, 0}, {-1, 0}, {0, 1},  {0, -1},
                        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}
template <class T>
inline T max1(T a, T b, T c = -1234567, T d = -1234567) {
  T ans = a > b ? a : b;
  if (c != -1234567) ans = max1(ans, c);
  if (d != -1234567) ans = max1(ans, d);
  return ans;
}
template <class T>
inline T min1(T a, T b, T c = -1234567, T d = -1234567) {
  T ans = a < b ? a : b;
  if (c != -1234567) ans = min(ans, c);
  if (d != -1234567) ans = min(ans, d);
  return ans;
}
template <class T>
inline T gcd1(T a, T b) {
  if (a < b) swap(a, b);
  if (a % b == 0) return b;
  return gcd1(b, a % b);
}
template <class T>
inline T lowb(T num) {
  return num & (-num);
}
inline int jud(double a, double b) {
  if (abs(a) < eps && abs(b) < eps)
    return 0;
  else if (abs1(a - b) / abs1(a) < eps)
    return 0;
  if (a < b) return -1;
  return 1;
}
template <typename t>
inline int jud(t a, t b) {
  if (a < b) return -1;
  if (a == b) return 0;
  return 1;
}
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
  int be = 0, en = na - 1;
  if (*a <= *(a + na - 1)) {
    if (f_lb == 0)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != 1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != -1)
          en = mid;
        else
          be = mid + 1;
      }
    if (f_small && jud(*(a + be), val) == 1) be--;
    if (!f_small && jud(*(a + be), val) == -1) be++;
  } else {
    if (f_lb)
      while (be < en) {
        int mid = (be + en + 1) / 2;
        if (jud(*(a + mid), val) != -1)
          be = mid;
        else
          en = mid - 1;
      }
    else
      while (be < en) {
        int mid = (be + en) / 2;
        if (jud(*(a + mid), val) != 1)
          en = mid;
        else
          be = mid + 1;
      }
    if (!f_small && jud(*(a + be), val) == -1) be--;
    if (f_small && jud(*(a + be), val) == 1) be++;
  }
  return be;
}
inline int bitnum(unsigned long long nValue) {
  nValue = ((0xaaaaaaaaaaaaaaaaull & nValue) >> 1) +
           (0x5555555555555555ull & nValue);
  nValue = ((0xccccccccccccccccull & nValue) >> 2) +
           (0x3333333333333333ull & nValue);
  nValue = ((0xf0f0f0f0f0f0f0f0ull & nValue) >> 4) +
           (0x0f0f0f0f0f0f0f0full & nValue);
  nValue = ((0xff00ff00ff00ff00ull & nValue) >> 8) +
           (0x00ff00ff00ff00ffull & nValue);
  nValue = ((0xffff0000ffff0000ull & nValue) >> 16) +
           (0x0000ffff0000ffffull & nValue);
  nValue = ((0xffffffff00000000ull & nValue) >> 32) +
           (0x00000000ffffffffull & nValue);
  return nValue;
}
long long pow(long long n, long long m, long long mod = 0) {
  long long ans = 1;
  long long k = n;
  while (m) {
    if (m & 1) {
      ans *= k;
      if (mod) ans %= mod;
    }
    k *= k;
    if (mod) k %= mod;
    m >>= 1;
  }
  return ans;
}
const int maxn = 22;
int dis[maxn][maxn][1 << 8];
char mp[maxn][maxn];
int have[maxn][maxn];
int q[maxn * maxn][3], lq, rq;
int n, m, sti, stj, cnt;
int p[maxn];
inline void out2(int a[][maxn], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cerr << a[i][j] << ' ';
    cerr << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", mp[i]);
  int now = 7;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (mp[i][j] >= '1' && mp[i][j] <= '8') {
        for (int t = 0; t <= i; t++) have[t][j] |= 1 << (mp[i][j] - '1');
        cnt++;
      } else if (mp[i][j] == 'S') {
        sti = i;
        stj = j;
        mp[i][j] = '.';
      } else if (mp[i][j] == 'B') {
        for (int t = 0; t <= i; t++) have[t][j] |= 1 << now;
        now--;
      }
    }
  memset(dis, 0x7f, sizeof(dis));
  lq = rq = 0;
  q[rq][0] = sti;
  q[rq][1] = stj;
  q[rq++][2] = 0;
  dis[sti][stj][0] = 0;
  for (; lq != rq; lq++) {
    int x = q[lq][0], y = q[lq][1], mask = q[lq][2];
    for (int i = 0; i < 4; i++) {
      int x1 = x + step[i][0], y11 = y + step[i][1], rmask = mask;
      if (x1 < 0 || y11 < 0 || x1 >= n || y11 >= m || mp[x1][y11] != '.')
        continue;
      if (i == 2) rmask ^= have[x][y];
      if (i == 3) rmask ^= have[x1][y11];
      if (dis[x1][y11][rmask] > dis[x][y][mask] + 1) {
        dis[x1][y11][rmask] = dis[x][y][mask] + 1;
        q[rq][0] = x1;
        q[rq][1] = y11;
        q[rq++][2] = rmask;
      }
    }
  }
  for (int i = 0; i < cnt; i++) scanf("%d", p + i);
  int ans = 0;
  for (int i = 0; i < 1 << cnt; i++) {
    if (dis[sti][stj][i] <= n * m) {
      int rans = -dis[sti][stj][i];
      for (int j = 0; j < cnt; j++)
        if (i & (1 << j)) rans += p[j];
      ans = max(rans, ans);
    }
  }
  printf("%d\n", ans);
  return 0;
}
