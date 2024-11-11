#include <bits/stdc++.h>
template <typename T>
inline void SWAP(T &a, T &b) {
  T tmp = a;
  a = b;
  b = tmp;
}
template <typename T>
inline T ABS(const T &VAL) {
  return VAL < 0 ? -VAL : VAL;
}
template <typename T>
inline T MAX(const T &a, const T &b) {
  return a < b ? b : a;
}
template <typename T>
inline T MIN(const T &a, const T &b) {
  return a < b ? a : b;
}
template <typename T>
inline T SQR(const T &a) {
  return a * a;
}
const int INTinf = 1000000005;
const int nINTinf = 0 - 2147483648;
const long long LLinf = 9223372036854775807LL;
using namespace std;
int n;
bool a[2005][2005];
int ch[2005][2005];
const int l = -3;
const int r = 4;
const int p = 22;
bool check2(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= n) return false;
  return ch[x][y] == 2;
}
bool check(int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= n) return false;
  if (ch[x][y]) return false;
  int sum = 0;
  for (int i = MAX(x + l, 0); i < MIN(x + r, n); i++) {
    for (int j = MAX(y + l, 0); j <= MIN(y + r, n); j++) {
      sum += a[i][j];
    }
  }
  if (sum >= p) {
    ch[x][y] = 2;
    return true;
  }
  ch[x][y] = 1;
  return false;
}
vector<pair<int, int> > order;
long long sX;
long long sY;
int cnt;
int squares = 0;
int circles = 0;
inline void put(int x, int y) {
  if (check(x, y)) {
    order.push_back(pair<int, int>(x, y));
    cnt++;
    sX += x;
    sY += y;
  }
}
void add(int x, int y) {
  sX = x;
  sY = y;
  cnt = 1;
  order.push_back(pair<int, int>(x, y));
  while (!order.empty()) {
    x = order.back().first;
    y = order.back().second;
    order.pop_back();
    if (x > 0) {
      put(x - 1, y);
    }
    if (x < n - 1) {
      put(x + 1, y);
    }
    if (y > 0) {
      put(x, y - 1);
    }
    if (y < n - 1) {
      put(x, y + 1);
    }
  }
  int aX = sX / cnt;
  int aY = sY / cnt;
  if (cnt < 50) {
    return;
  }
  int diu = 0;
  while (check2(aX - diu, aY)) {
    diu++;
  }
  int diu2 = 0;
  while (check2(aX - diu2, aY - diu2)) {
    diu2++;
  }
  int diu3 = 0;
  while (check2(aX - diu3, aY - diu3 * 2)) {
    diu3++;
  }
  int diu4 = 0;
  while (check2(aX + diu4, aY - diu4 * 2)) {
    diu4++;
  }
  diu--;
  diu2--;
  diu3--;
  diu4--;
  double val[3];
  val[0] = diu;
  val[1] = sqrt((long double)(diu2 * diu2 * 2));
  val[2] = sqrt((long double)(diu3 * diu3 * 5));
  val[3] = sqrt((long double)(diu4 * diu4 * 5));
  sort(val, val + 4);
  if (val[0] / val[3] < 0.86) {
    squares++;
  } else {
    circles++;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i != n; i++) {
    for (int j = 0; j != n; j++) {
      int q;
      scanf("%d", &q);
      a[i][j] = q;
    }
  }
  for (int i = 0; i != n; i++) {
    for (int j = 0; j != n; j++) {
      if (!ch[i][j]) {
        if (check(i, j)) {
          add(i, j);
        }
      }
    }
  }
  cout << circles << ' ' << squares << endl;
  return 0;
}
