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
const int N = 210000;
int n, a[N], b[N];
int c[N], num[N];
void update(int x, int d) {
  for (; x <= n; x += ((x) & (-(x)))) c[x] += d;
}
int ask(int x) {
  int res = 0;
  for (; x; x -= ((x) & (-(x)))) res += c[x];
  return res;
}
int kth(int k) {
  int l = 1, r = n, res = 0;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ask(mid - 1) <= k)
      res = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  return res;
}
int main() {
  cin >> n;
  for (int i = (1); i <= (n); ++i) read(a + i), a[i]++;
  for (int i = (1); i <= (n); ++i) read(b + i), b[i]++;
  for (int i = (1); i <= (n); ++i) update(i, 1);
  for (int i = (1); i <= (n); ++i) {
    num[i] += ask(a[i] - 1);
    update(a[i], -1);
  }
  for (int i = (1); i <= (n); ++i) update(i, 1);
  for (int i = (1); i <= (n); ++i) {
    num[i] += ask(b[i] - 1);
    update(a[i], -1);
  }
  for (int i = (n); i >= (1); --i) {
    num[i - 1] += num[i] / (n - i + 1);
    num[i] %= (n - i + 1);
  }
  for (int i = (1); i <= (n); ++i) update(i, 1);
  for (int i = (1); i <= (n); ++i) {
    int x = kth(num[i]);
    update(x, -1);
    printf("%d ", x - 1);
  }
  cout << endl;
  return 0;
}
