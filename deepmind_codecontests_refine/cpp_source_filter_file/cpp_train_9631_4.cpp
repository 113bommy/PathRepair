#include <bits/stdc++.h>
using namespace std;
const double pi = acos(0.0) * 2.0;
const long double eps = 1e-10;
const int step[8][2] = {{-1, 0}, {0, 1}, {1, 0},  {0, -1},
                        {-1, 1}, {1, 1}, {1, -1}, {-1, -1}};
template <class T>
inline T abs1(T a) {
  return a < 0 ? -a : a;
}
template <typename t, typename t1>
t min1(t a, t1 b) {
  return a < b ? a : b;
}
template <typename t, typename... arg>
t min1(t a, arg... arr) {
  return min1(a, min1(arr...));
}
template <typename t, typename t1>
t max1(t a, t1 b) {
  return a > b ? a : b;
}
template <typename t, typename... arg>
t max1(t a, arg... arr) {
  return max1(a, max1(arr...));
}
inline int jud(double a, double b) {
  if (abs(a) < eps && abs(b) < eps)
    return 0;
  else if (abs1(a - b) / max(abs1(a), abs1(b)) < eps)
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
  if (na == 0) return 0;
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
template <class T>
inline T lowb(T num) {
  return num & (-num);
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
  if (a == 0) return 0;
  return 32 - __builtin_clz(a);
}
inline int bitmaxl(int a) {
  if (a == 0) return 0;
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
template <class t1, class t2>
inline void add(t1 &a, t2 b, int mod = -1) {
  if (mod == -1) mod = 1000000007;
  a += b;
  while (a >= mod) a -= mod;
  while (a < 0) a += mod;
}
template <class t>
void output1(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) cerr << arr[i] << ' ';
  cerr << endl;
}
template <class t>
void output2(t arr) {
  for (int i = 0; i < (int)arr.size(); i++) output1(arr[i]);
}
const int mod = 1000000007;
const int maxn = 2010;
int match[2][maxn][maxn][2];
char uturn[2][maxn][maxn][2];
int onedirection[2][maxn][maxn][2];
char mp[2][maxn], str[maxn];
int n, lstr;
int getmatch(int row, int col, int stindex, int dir) {
  if (stindex >= lstr) return 0;
  if (col >= n || col < 0) return 0;
  int &ans = match[row][col][stindex][dir];
  if (ans != -1) return ans;
  ans = 0;
  int add = 1;
  if (dir == 1) add = -1;
  if (mp[row][col] == str[stindex])
    return ans = 1 + getmatch(row, col + add, stindex + 1, dir);
  else
    return ans = 0;
}
int getuturn(int row, int col, int stindex, int dir) {
  if (stindex >= lstr - 3) return 0;
  if (col >= n || col < 0) return 0;
  char &ans = uturn[row][col][stindex][dir];
  if (ans != -1) return ans;
  ans = 0;
  int add = 1;
  if (dir == 1) add = -1;
  if ((lstr - stindex) % 2 == 0) {
    ans += int(getmatch(row, col, stindex, dir) >= (lstr - stindex) / 2) *
           int(getmatch(1 - row, col + add * ((lstr - stindex) / 2 - 1),
                        stindex + (lstr - stindex) / 2,
                        1 - dir) >= (lstr - stindex) / 2);
  }
  return ans;
}
int getonedirection(int row, int col, int stindex, int dir) {
  if (stindex >= lstr) return 1;
  if (col >= n || col < 0) return 0;
  int &ans = onedirection[row][col][stindex][dir];
  if (ans != -1) return ans;
  ans = 0;
  int add = 1;
  if (dir == 1) add = -1;
  ans += getuturn(row, col, stindex, dir);
  if (str[stindex] != mp[row][col]) return ans;
  ::add(ans, getonedirection(row, col + add, stindex + 1, dir));
  if (stindex != n - 1 && str[stindex + 1] == mp[1 - row][col])
    ::add(ans, getonedirection(1 - row, col + add, stindex + 2, dir));
  return ans;
}
int getans(int row, int col, int dir) {
  int maxl = getmatch(row, col, 0, dir);
  int ans = getuturn(row, col, 0, dir);
  int add = 1;
  if (dir == 1) add = -1;
  ::add(ans, getonedirection(row, col - add, 1, 1 - dir));
  for (int i = 1; i <= min(maxl, (lstr - 1) / 2); i++) {
    if (getmatch(1 - row, col + add * (i - 1), i, 1 - dir) >= i)
      ::add(ans, getonedirection(1 - row, col - add, i * 2, 1 - dir));
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  memset(onedirection, -1, sizeof(onedirection));
  memset(match, -1, sizeof(match));
  memset(uturn, -1, sizeof(uturn));
  scanf("%s%s%s", mp[0], mp[1], str);
  n = strlen(mp[0]);
  lstr = strlen(str);
  if (lstr == 1) {
    int rans = 0;
    for (int i = 0; i < 2; i++)
      for (int j = 0; j < n; j++)
        if (mp[i][j] == str[0]) rans++;
    cout << rans << endl;
    return 0;
  }
  long long ans = 0;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < n; j++)
      if (mp[i][j] == str[0]) {
        add(ans, getans(i, j, 0));
        add(ans, getans(i, j, 1));
        if (lstr == 2 && mp[1 - i][j] == str[1]) ans--;
      }
  cout << ans << endl;
  return 0;
}
