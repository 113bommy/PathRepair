#include <bits/stdc++.h>
using namespace std;
struct fastIO {
  inline fastIO operator>>(int& num) {
    num = 0;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    bool foo = 0;
    if (c == '-') {
      foo = 1;
      c = getchar();
    }
    while (c >= '0' && c <= '9') {
      num = (num << 3) + (num << 1) + c - '0';
      c = getchar();
    }
    if (foo) num = -num;
    return *this;
  }
  inline fastIO operator>>(long long& num) {
    num = 0;
    char c = getchar();
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    bool foo = 0;
    if (c == '-') {
      foo = 1;
      c = getchar();
    }
    while (c >= '0' && c <= '9') {
      num = (num << 3) + (num << 1) + c - '0';
      c = getchar();
    }
    if (foo) num = -num;
    return *this;
  }
  inline fastIO operator>>(float& num) {
    scanf("%f", &num);
    return *this;
  }
  inline fastIO operator>>(double& num) {
    scanf("%lf", &num);
    return *this;
  }
  inline fastIO operator>>(long double& num) {
    scanf("%Lf", &num);
    return *this;
  }
  inline fastIO operator>>(char& num) {
    num = getchar();
    while (num == ' ' || num == '\n') num = getchar();
    return *this;
  }
  inline fastIO operator>>(char* num) {
    int cnt = 0;
    char c = getchar();
    while (c == ' ' || c == '\n') c = getchar();
    while (c != ' ' && c != '\n') {
      num[cnt++] = c;
      c = getchar();
    }
    num[cnt] = 0;
    return *this;
  }
  inline fastIO operator>>(string& num) {
    cin >> num;
    return *this;
  }
  inline void printInt(const int& num) {
    if (num < 10) {
      putchar(num + '0');
      return;
    }
    printInt(num / 10);
    putchar((num % 10) + '0');
  }
  inline void printINT(const long long& num) {
    if (num < 10) {
      putchar(num + '0');
      return;
    }
    printINT(num / 10);
    putchar((num % 10) + '0');
  }
  inline fastIO operator<<(const int& num) {
    if (num < 0)
      putchar('-'), printInt(-num);
    else
      printInt(num);
    return *this;
  }
  inline fastIO operator<<(const long long& num) {
    if (num < 0)
      putchar('-'), printINT(-num);
    else
      printINT(num);
    return *this;
  }
  inline fastIO operator<<(const float& num) {
    printf("%.10f", num);
    return *this;
  }
  inline fastIO operator<<(const double& num) {
    printf("%.16lf", num);
    return *this;
  }
  inline fastIO operator<<(const long double& num) {
    printf("%.20Lf", num);
    return *this;
  }
  inline fastIO operator<<(const char& num) {
    putchar(num);
    return *this;
  }
  inline fastIO operator<<(const char* num) {
    for (int i = 0; num[i]; i++) putchar(num[i]);
    return *this;
  }
  inline fastIO operator<<(const string& num) {
    cout << num;
    return *this;
  }
} fio;
const int MAXN = 5005;
struct bit2d {
  int dt[MAXN][MAXN];
  void add1line(int x, int y, int a) {
    while (y < MAXN) {
      dt[x][y] += a;
      y += (y & -y);
    }
  }
  int sum1line(int x, int y) {
    int sum = 0;
    while (y) {
      sum += dt[x][y];
      y -= (y & -y);
    }
    return sum;
  }
  void add(int x, int y, int a) {
    while (x < MAXN) {
      add1line(x, y, a);
      x += (x & -x);
    }
  }
  int sum(int x, int y) {
    int sum = 0;
    while (x) {
      sum += sum1line(x, y);
      x -= (x & -x);
    }
    return sum;
  }
  int sum(int x1, int x2, int yxiaomiexuduhuanrenleiwannianankang, int y2) {
    x1--;
    yxiaomiexuduhuanrenleiwannianankang--;
    x1 = max(x1, 0);
    yxiaomiexuduhuanrenleiwannianankang =
        max(yxiaomiexuduhuanrenleiwannianankang, 0);
    x2 = max(x2, 0);
    y2 = max(y2, 0);
    x1 = min(x1, MAXN - 1);
    yxiaomiexuduhuanrenleiwannianankang =
        min(yxiaomiexuduhuanrenleiwannianankang, MAXN - 1);
    x2 = min(x2, MAXN - 1);
    y2 = min(y2, MAXN - 1);
    return sum(x2, y2) - sum(x2, yxiaomiexuduhuanrenleiwannianankang) -
           sum(x1, y2) + sum(x1, yxiaomiexuduhuanrenleiwannianankang);
  }
} bit;
int n, m, k;
pair<int, int> change(int x, int y) { return make_pair(x + y, x - y + m); }
pair<int, int> changeback(int x, int y) {
  return make_pair((x + y - m) / 2, (x - y + m) / 2);
}
pair<int, int> changeback(pair<int, int> xy) {
  return changeback(xy.first, xy.second);
}
pair<int, int> findminx(int y, int x1, int x2) {
  if (!bit.sum(x1, x2, y, y)) {
    return make_pair(((int)0x3f3f3f3f), ((int)0x3f3f3f3f));
  }
  x1 = max(x1, 0);
  x2 = min(x2, MAXN - 1);
  int l = x1 - 1, r = x2;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (bit.sum(x1, m, y, y)) {
      r = m;
    } else {
      l = m;
    }
  }
  return changeback(r, y);
}
pair<int, int> findminy(int x, int yxiaomiexuduhuanrenleiwannianankang,
                        int y2) {
  if (!bit.sum(x, x, yxiaomiexuduhuanrenleiwannianankang, y2)) {
    return make_pair(((int)0x3f3f3f3f), ((int)0x3f3f3f3f));
  }
  yxiaomiexuduhuanrenleiwannianankang =
      max(yxiaomiexuduhuanrenleiwannianankang, 0);
  y2 = min(y2, MAXN - 1);
  int l = yxiaomiexuduhuanrenleiwannianankang - 1, r = y2;
  while (r - l > 1) {
    int m = (l + r) >> 1;
    if (bit.sum(x, x, yxiaomiexuduhuanrenleiwannianankang, m)) {
      r = m;
    } else {
      l = m;
    }
  }
  return changeback(x, r);
}
int main() {
  fio >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pair<int, int> chg = change(i, j);
      bit.add(chg.first, chg.second, 1);
    }
  }
  while (k--) {
    int x, y;
    fio >> x >> y;
    pair<int, int> chg = change(x, y);
    x = chg.first;
    y = chg.second;
    int l = -1, r = max(n, m);
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (bit.sum(x - m, x + m, y - m, y + m)) {
        r = m;
      } else {
        l = m;
      }
    }
    l = r;
    pair<int, int> ans = min(
        min((findminx(y - l, x - l, x + l)), (findminx(y + l, x - l, x + l))),
        min((findminy(x - l, y - l, y + l)), (findminy(x + l, y - l, y + l))));
    int minx = ans.first, miny = ans.second;
    fio << minx << ' ' << miny << '\n';
    chg = change(minx, miny);
    bit.add(chg.first, chg.second, -1);
  }
  return 0;
}
