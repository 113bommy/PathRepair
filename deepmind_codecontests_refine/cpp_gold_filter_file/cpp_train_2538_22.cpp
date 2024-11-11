#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const double eps = 1e-12;
const int step[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
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
inline T lb(T num) {
  return num & (-num);
}
inline int jud(double a, double b) {
  if (abs1(a - b) < eps) return 0;
  if (a < b) return -1;
  return 1;
}
template <typename it, typename t1>
inline int find(t1 val, it a, int na, bool f_small = 1, bool f_lb = 1) {
  if (na == 1) return 0;
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
    if (f_small && jud(*(a + be), val) == 1 && be != 0) be--;
    if (!f_small && jud(*(a + be), val) == -1 && be != na - 1) be++;
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
    if (!f_small && jud(*(a + be), val) == -1 && be != 0) be--;
    if (f_small && jud(*(a + be), val) == 1 && be != na - 1) be++;
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
const int mod = 1000000007;
const int maxn = 11;
int n, m, nc, rannc, nxtnc;
int have[maxn][maxn], cant[maxn][maxn], mp[maxn][maxn];
int used[maxn];
long long dfs(int i, int j) {
  if (j == m) j = 0, i++;
  if (i == n) return 1;
  have[i][j] = 0;
  if (i != 0) have[i][j] |= have[i - 1][j];
  if (j != 0) have[i][j] |= have[i][j - 1];
  if ((have[i][j] == (1 << nc) - 1)) return 0;
  if (mp[i][j]) {
    if ((1 << mp[i][j] - 1) & have[i][j]) return 0;
    have[i][j] |= 1 << (mp[i][j] - 1);
    return dfs(i, j + 1);
  }
  long long rans = 0;
  int nxtnc1 = nxtnc;
  for (int i1 = 0; i1 < nc; i1++)
    if (((cant[i][j] & (1 << i1)) == 0) && (have[i][j] & (1 << i1)) == 0) {
      if (!used[i1] && i1 != nxtnc) continue;
      have[i][j] |= (1 << i1);
      used[i1]++;
      if (used[i1] == 1) {
        for (; nxtnc < nc; nxtnc++)
          if (used[nxtnc] == 0) break;
        rannc--;
        rans += ((rannc + 1) * dfs(i, j + 1)) % mod;
        rans %= mod;
        rannc++;
        nxtnc = nxtnc1;
      } else {
        rans += dfs(i, j + 1);
        rans %= mod;
      }
      used[i1]--;
      have[i][j] ^= (1 << i1);
    }
  return rans;
}
int main() {
  scanf("%d%d%d", &n, &m, &nc);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", mp[i] + j);
  if (n + m - 1 > nc) {
    cout << 0 << endl;
    return 0;
  }
  rannc = nc;
  for (int i = n - 1; i >= 0; i--)
    for (int j = m - 1; j >= 0; j--) {
      if (i != n - 1) {
        if (mp[i + 1][j]) cant[i][j] |= 1 << mp[i + 1][j] - 1;
        cant[i][j] |= cant[i + 1][j];
      }
      if (j != m - 1) {
        if (mp[i][j + 1]) cant[i][j] |= 1 << mp[i][j + 1] - 1;
        cant[i][j] |= cant[i][j + 1];
      }
      if (mp[i][j]) {
        if ((1 << (mp[i][j] - 1)) & cant[i][j]) {
          cout << 0 << endl;
          return 0;
        }
        used[mp[i][j] - 1]++;
        if (used[mp[i][j] - 1] == 1) rannc--;
      }
    }
  for (; used[nxtnc]; nxtnc++)
    ;
  cout << dfs(0, 0) << endl;
  return 0;
}
