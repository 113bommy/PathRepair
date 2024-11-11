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
const int N = 1010;
int a[N][N], p[N][N];
long long ans;
int x, y;
int n, m;
pair<int, int> tmp[N * N];
bool cmp1(const pair<int, int> &A, const pair<int, int> &B) {
  return 1LL * A.second * x - 1LL * y * (A.first - n) >
         1LL * B.second * x - 1LL * y * (B.first - n);
}
bool cmp2(const pair<int, int> &A, const pair<int, int> &B) {
  return 1LL * A.second * x - 1LL * y * A.first <
         1LL * B.second * x - 1LL * y * B.first;
}
struct node {
  int val, min;
};
node tree[2 * (1 << 20)];
void modify(int L, int R, int h, int id = 1, int low = 1, int high = m) {
  if (L <= low && R >= high) {
    tree[id].val = max(tree[id].val, h);
    tree[id].min = max(tree[id].min, h);
    return;
  }
  int mid = (low + high) / 2;
  if (L < mid) modify(L, R, h, 2 * id, low, mid);
  if (R > mid) modify(L, R, h, 2 * id + 1, mid, high);
  tree[id].min = max(tree[id].val, min(tree[2 * id].min, tree[2 * id + 1].min));
}
int ask(int L, int R, int id = 1, int low = 1, int high = m) {
  if (L <= low && R >= high) return tree[id].min;
  int ans = (1 << 30);
  int mid = (low + high) / 2;
  if (L < mid) ans = min(ans, ask(L, R, 2 * id, low, mid));
  if (R > mid) ans = min(ans, ask(L, R, 2 * id + 1, mid, high));
  ans = max(ans, tree[id].val);
  return ans;
}
void solve1() {
  int cnt = 0;
  m = 0;
  long long ans = 0;
  for (int i = (0); i <= (n); ++i)
    for (int j = (0); j <= (n); ++j) tmp[++cnt] = std::make_pair(i, j);
  sort(tmp + 1, tmp + cnt + 1, cmp1);
  for (int i = (1); i <= (cnt); ++i) {
    int a = tmp[i].first, b = tmp[i].second;
    if (i == 1 || cmp1(tmp[i - 1], tmp[i])) ++m;
    p[a][b] = m;
  }
  for (int i = (n); i >= (1); --i)
    for (int j = (1); j <= (n); ++j) {
      int l[4];
      l[0] = p[i][j], l[1] = p[i - 1][j], l[2] = p[i][j - 1];
      l[3] = p[i - 1][j - 1];
      sort(l, l + 4);
      int L = l[0], R = l[3];
      int t = ask(L, R);
      if (t < a[i][j]) ans += a[i][j] - t;
      modify(L, R, a[i][j]);
    }
  cout << ans << endl;
}
void solve2() {
  int cnt = 0;
  m = 0;
  long long ans = 0;
  for (int i = (0); i <= (n); ++i)
    for (int j = (0); j <= (n); ++j) tmp[++cnt] = std::make_pair(i, j);
  sort(tmp + 1, tmp + cnt + 1, cmp1);
  for (int i = (1); i <= (cnt); ++i) {
    int a = tmp[i].first, b = tmp[i].second;
    if (i == 1 || cmp1(tmp[i - 1], tmp[i])) ++m;
    p[a][b] = m;
  }
  for (int i = (n); i >= (1); --i)
    for (int j = (n); j >= (1); --j) {
      int l[4];
      l[0] = p[i][j], l[1] = p[i - 1][j], l[2] = p[i][j - 1];
      l[3] = p[i - 1][j - 1];
      sort(l, l + 4);
      int L = l[0], R = l[3];
      int t = ask(L, R);
      if (t < a[i][j]) ans += a[i][j] - t;
      modify(L, R, a[i][j]);
    }
  cout << ans << endl;
}
void solve3() {
  int cnt = 0;
  m = 0;
  long long ans = 0;
  for (int i = (0); i <= (n); ++i)
    for (int j = (0); j <= (n); ++j) tmp[++cnt] = std::make_pair(i, j);
  sort(tmp + 1, tmp + cnt + 1, cmp2);
  for (int i = (1); i <= (cnt); ++i) {
    int a = tmp[i].first, b = tmp[i].second;
    if (i == 1 || cmp2(tmp[i - 1], tmp[i])) ++m;
    p[a][b] = m;
  }
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (n); ++j) {
      int l[4];
      l[0] = p[i][j], l[1] = p[i - 1][j], l[2] = p[i][j - 1];
      l[3] = p[i - 1][j - 1];
      sort(l, l + 4);
      int L = l[0], R = l[3];
      int t = ask(L, R);
      if (t < a[i][j]) ans += a[i][j] - t;
      modify(L, R, a[i][j]);
    }
  cout << ans << endl;
}
void solve4() {
  int cnt = 0;
  m = 0;
  long long ans = 0;
  for (int i = (0); i <= (n); ++i)
    for (int j = (0); j <= (n); ++j) tmp[++cnt] = std::make_pair(i, j);
  sort(tmp + 1, tmp + cnt + 1, cmp2);
  for (int i = (1); i <= (cnt); ++i) {
    int a = tmp[i].first, b = tmp[i].second;
    if (i == 1 || cmp2(tmp[i - 1], tmp[i])) ++m;
    p[a][b] = m;
  }
  for (int i = (1); i <= (n); ++i)
    for (int j = (n); j >= (1); --j) {
      int l[4];
      l[0] = p[i][j], l[1] = p[i - 1][j], l[2] = p[i][j - 1];
      l[3] = p[i - 1][j - 1];
      sort(l, l + 4);
      int L = l[0], R = l[3];
      int t = ask(L, R);
      if (t < a[i][j]) ans += a[i][j] - t;
      modify(L, R, a[i][j]);
    }
  cout << ans << endl;
}
int main() {
  cin >> n >> x >> y;
  for (int i = (1); i <= (n); ++i)
    for (int j = (1); j <= (n); ++j) read(&a[i][j]);
  if (!x) {
    long long sum = 0;
    for (int i = (1); i <= (n); ++i) {
      int t = 0;
      for (int j = (1); j <= (n); ++j) getmax(&t, a[i][j]);
      sum += t;
    }
    cout << sum << endl;
  } else if (!y) {
    long long sum = 0;
    for (int i = (1); i <= (n); ++i) {
      int t = 0;
      for (int j = (1); j <= (n); ++j) getmax(&t, a[j][i]);
      sum += t;
    }
    cout << sum << endl;
  } else if (x < 0 && y > 0)
    solve1();
  else if (x < 0 && y < 0)
    solve2();
  else if (x > 0 && y > 0)
    solve3();
  else
    solve4();
  return 0;
}
