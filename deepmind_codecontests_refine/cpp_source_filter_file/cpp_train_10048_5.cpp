#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool getmin(T *a, const T &b) {
  if (b < *a) {
    *a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool getmax(T *a, const T &b) {
  if (b > *a) {
    *a = b;
    return true;
  }
  return false;
}
template <class T>
inline void read(T *a) {
  char c;
  while (isspace(c = getchar())) {
  }
  bool flag = 0;
  if (c == '-')
    flag = 1, *a = 0;
  else
    *a = c - 48;
  while (isdigit(c = getchar())) *a = *a * 10 + c - 48;
  if (flag) *a = -*a;
}
const int mo = 1000000007;
template <class T>
T pow(T a, T b, int c = mo) {
  T res = 1;
  for (T i = 1; i <= b; i <<= 1, a = 1LL * a * a % c)
    if (b & i) res = 1LL * res * a % c;
  return res;
}
const int N = 110000;
pair<int, int> a[N];
int maxx, minx, maxy, miny;
int n;
pair<int, int> pre[N], suf[N];
pair<int, int> calc(int l, int r) {
  if (l == 1)
    return suf[r + 1];
  else if (r == n)
    return pre[l - 1];
  else
    return std::make_pair(min(pre[l - 1].first, suf[r + 1].first),
                          max(pre[l - 1].second, suf[r + 1].second));
}
bool check(long long x) {
  int y = sqrt(x);
  for (int i = (1); i <= (n); ++i) {
    if (a[i].first > 0) break;
    int l1 = a[i].first + y;
    int l2 = -a[i].first;
    int l = min(l1, l2);
    int j =
        upper_bound(a + 1, a + n + 1, std::make_pair(l, 1000000000)) - a - 1;
    pair<int, int> tmp = calc(i, j);
    if (1LL * (tmp.second - tmp.first) * (tmp.second - tmp.first) <= x) {
      long long yy =
          max(1LL * tmp.first * tmp.first, 1LL * tmp.second * tmp.second);
      if (yy + 1LL * a[i].first * a[i].first <= x) return true;
    }
  }
  for (int i = (n); i >= (1); --i) {
    if (a[i].first < 0) break;
    int l1 = a[i].first - y;
    int l2 = -a[i].first;
    int l = max(l1, l2);
    int j = lower_bound(a + 1, a + n + 1, std::make_pair(l, 1000000000)) - a;
    pair<int, int> tmp = calc(j, i);
    if (1LL * (tmp.second - tmp.first) * (tmp.second - tmp.first) <= x) {
      long long yy =
          max(1LL * tmp.first * tmp.first, 1LL * tmp.second * tmp.second);
      if (yy + 1LL * a[i].first * a[i].first <= x) return true;
    }
  }
  return false;
}
int main() {
  minx = miny = 1e9;
  maxx = maxy = -1e9;
  cin >> n;
  for (int i = (1); i <= (n); ++i) {
    read(&a[i].first);
    read(&a[i].second);
    getmin(&minx, a[i].first);
    getmax(&maxx, a[i].first);
    getmin(&miny, a[i].second);
    getmax(&maxy, a[i].second);
  }
  sort(a + 1, a + n + 1);
  pre[1] = std::make_pair(a[1].second, a[1].second);
  for (int i = (2); i <= (n); ++i) {
    pre[i].first = min(pre[i - 1].first, a[i].second);
    pre[i].second = max(pre[i - 1].second, a[i].second);
  }
  suf[n] = std::make_pair(a[n].second, a[n].second);
  for (int i = (n - 1); i >= (1); --i) {
    suf[i].first = min(pre[i + 1].first, a[i].second);
    suf[i].second = max(pre[i + 1].second, a[i].second);
  }
  long long res = min(1LL * (maxx - minx) * (maxx - minx),
                      1LL * (maxy - miny) * (maxy - miny));
  long long l = 0, r = res;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (check(mid))
      res = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << res << endl;
  return 0;
}
