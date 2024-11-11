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
const int maxn = 200010;
int dp[maxn][7];
int orig[maxn], arr[maxn][2], larr;
int stat[maxn];
int n;
inline pair<int, int> adv(pair<int, int> now, int add, int base = 5) {
  pair<int, int> ans = now;
  if (ans.second >= base) {
    ans.first++;
    ans.second = 0;
    add--;
  }
  ans.second += add;
  ans.first += ans.second / base;
  ans.second %= base;
  return ans;
}
inline bool judge(pair<int, int> a, pair<int, int> b, int l) {
  int small = (b.first - a.first - 1) * 2 + b.second + 1 + int(a.second == 0);
  int big = (b.first - a.first - 1) * 5 + b.second + 5 - a.second;
  return l >= small && l <= big;
}
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  if (n == 1) {
    printf("-1\n");
    return 0;
  }
  bool fla = 1;
  for (int i = 0; i < n; i++) {
    scanf("%d", orig + i);
    stat[orig[i]]++;
    if (orig[i] != 0 && stat[orig[i]] > 5) fla = 0;
  }
  if (!fla) {
    printf("-1\n");
    return 0;
  }
  arr[larr][0] = 0;
  arr[larr][1] = 0;
  larr++;
  for (int i = 0; i < n; i++)
    if (orig[i] != 0) {
      arr[larr][0] = orig[i];
      arr[larr++][1] = i + 1;
    }
  memset(dp, -1, sizeof(dp));
  dp[0][4] = 0;
  for (int i = 0; i < larr - 1; i++) {
    for (int j = 0; j < 5; j++)
      if (dp[arr[i][1]][j] != -1) {
        int l = arr[i + 1][1] - arr[i][1];
        if (arr[i + 1][0] == arr[i][0]) {
          if (j + arr[i + 1][1] - arr[i][1] < 5)
            dp[arr[i + 1][1]][j + arr[i + 1][1] - arr[i][1]] = j;
        } else
          for (int k = 0; k < 5; k++) {
            if (judge(make_pair(arr[i][0], j), make_pair(arr[i + 1][0], k), l))
              dp[arr[i + 1][1]][k] = j;
          }
      }
  }
  int f = -1;
  if (arr[larr - 1][1] != n) {
    for (int j = 3; j >= 0; j--)
      if (dp[arr[larr - 1][1]][j] != -1) {
        if (j == 0 && arr[larr - 1][1] == n) break;
        f = j;
        break;
      }
    if (f == -1 && dp[arr[larr - 1][1]][4] != -1) f = 4;
  } else {
    for (int j = 1; j <= 4; j++)
      if (dp[arr[larr - 1][1]][j] != -1) {
        if (j == 0 && arr[larr - 1][1] == n) break;
        f = j;
        break;
      }
  }
  if (f == -1 || (f == 4 && arr[larr - 1][1] == n - 1)) {
    printf("-1\n");
    return 0;
  }
  int be = arr[larr - 1][1];
  if (f == 0) {
    orig[be] = arr[larr - 1][0];
    be++;
  }
  int flag = 0;
  for (int i = be, add = arr[larr - 1][0] + 1; i < n; i++, flag ^= 1) {
    orig[i] = add;
    if (flag) add++;
  }
  if (flag) orig[n - 1] = orig[n - 2];
  for (int i = larr - 1; i; i--) {
    int nxt = dp[arr[i][1]][f];
    pair<int, int> be = make_pair(arr[i - 1][0], nxt);
    for (int j = arr[i - 1][1]; j < arr[i][1] - 1; j++) {
      be.second++;
      if (be.first != arr[i][0] &&
          (be.second == 5 ||
           adv(be, arr[i][1] - 1 - j, 2) < make_pair(arr[i][0], f) ||
           arr[i][1] - 1 - j <= f + 2 * (arr[i][0] - be.first - 1)))
        be.first++, be.second = 0;
      orig[j] = be.first;
    }
    f = nxt;
  }
  printf("%d\n", orig[n - 1]);
  for (int i = 0; i < n; i++) printf("%d ", orig[i]);
  printf("\n");
  return 0;
}
