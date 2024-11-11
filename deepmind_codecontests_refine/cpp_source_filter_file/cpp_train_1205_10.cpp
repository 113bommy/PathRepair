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
const int maxn = 55;
char mp[maxn][maxn], to[maxn][maxn];
int n, m;
pair<int, int> ans[maxn];
int lans;
void change(int x, int y) {
  if (mp[x][y] == 'L') {
    assert(mp[x + 1][y] == 'L' || mp[x + 1][y] == 'R' || mp[x + 1][y] == 'U');
    if (mp[x + 1][y] == 'R') change(x + 1, y - 1);
    assert(mp[x + 1][y] == 'L' || mp[x + 1][y] == 'U');
    if (mp[x + 1][y] == 'U') change(x + 1, y);
    assert(mp[x + 1][y] == 'L');
    ans[lans++] = make_pair(x, y);
    mp[x][y] = 'U';
    mp[x][y + 1] = 'U';
    mp[x + 1][y] = 'D';
    mp[x + 1][y + 1] = 'D';
    return;
  } else {
    assert(mp[x][y + 1] == 'L' || mp[x][y + 1] == 'U');
    if (mp[x][y + 1] == 'D') change(x - 1, y + 1);
    assert(mp[x][y + 1] == 'L' || mp[x][y + 1] == 'U');
    if (mp[x][y + 1] == 'L') change(x, y + 1);
    assert(mp[x][y + 1] == 'U');
    ans[lans++] = make_pair(x, y);
    mp[x][y] = 'L';
    mp[x][y + 1] = 'R';
    mp[x + 1][y] = 'L';
    mp[x + 1][y + 1] = 'R';
    return;
  }
}
bool check(char mp[][maxn]) {
  bool flag = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (mp[i][j] == 'L') flag &= mp[i][j + 1] == 'R';
      if (mp[i][j] == 'R') flag &= mp[i][j - 1] == 'L';
      if (mp[i][j] == 'U') flag &= mp[i + 1][j] == 'D';
      if (mp[i][j] == 'D') flag &= mp[i - 1][j] == 'U';
    }
  return flag;
}
int main() {
  ios_base::sync_with_stdio(0);
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%s", mp[i]);
  for (int j = 0; j < n; j++) {
    scanf("%s", to[j]);
  }
  if (!check(mp) || !check(to)) {
    puts("-1");
    return 0;
  }
  bool flag = 1;
  while (flag) {
    flag = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++)
        if (mp[i][j] != to[i][j]) {
          change(i, j);
          flag = 1;
        }
  }
  printf("%d\n", lans);
  for (int i = 0; i < lans; i++) {
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  }
  return 0;
}
