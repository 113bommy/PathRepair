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
inline T max1(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline T max1(T a, T b, T c) {
  return max1(max1(a, b), c);
}
template <class T>
inline T max1(T a, T b, T c, T d) {
  return max1(max1(a, b, c), d);
}
template <class T>
inline T max1(T a, T b, T c, T d, T e) {
  return max1(max1(a, b, c, d), e);
}
template <class T>
inline T min1(T a, T b) {
  return a > b ? a : b;
}
template <class T>
inline T min1(T a, T b, T c) {
  return min1(min1(a, b), c);
}
template <class T>
inline T min1(T a, T b, T c, T d) {
  return min1(min1(a, b, c), d);
}
template <class T>
inline T min1(T a, T b, T c, T d, T e) {
  return min1(min1(a, b, c, d), e);
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
inline int bitnum(unsigned int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(int nValue) { return __builtin_popcount(nValue); }
inline int bitnum(unsigned long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitnum(long long nValue) {
  return __builtin_popcount(nValue) + __builtin_popcount(nValue >> 32);
}
inline int bitmaxl(unsigned int a) {
  if (a) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(int a) {
  if (a) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(unsigned long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
inline int bitmaxl(long long a) {
  int temp = a >> 32;
  if (temp) return 32 - __builtin_clz(temp) + 32;
  return bitmaxl(int(a));
}
long long pow(long long n, long long m, long long mod = 0) {
  if (m < 0) return 0;
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
const int maxn = 300100;
char str[maxn];
int dp[maxn];
int nxt[maxn][30];
long long cnt[30];
int l;
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%s", str);
  l = strlen(str);
  memset(nxt, -1, sizeof(nxt));
  for (int i = l - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) nxt[i][j] = nxt[i + 1][j];
    nxt[i][str[i] - 'a'] = i;
  }
  memset(cnt, 0, sizeof(cnt));
  for (int i = 0; i < l; i++) {
    int arr[30];
    for (int j = 0; j < 26; j++) {
      arr[j] = nxt[i][j];
      if (arr[j] == -1) arr[j] = l;
    }
    sort(arr, arr + 26);
    arr[26] = l;
    for (int j = 0; j <= 25; j++) cnt[j + 1] += arr[j + 1] - arr[j];
  }
  int lans = 26;
  for (; cnt[lans] == 0; lans--)
    ;
  printf("%d\n", lans);
  for (int i = 1; i <= lans; i++) printf("%I64d\n", cnt[i]);
  return 0;
}
