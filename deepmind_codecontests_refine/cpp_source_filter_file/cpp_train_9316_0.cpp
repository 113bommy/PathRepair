#include <bits/stdc++.h>
template <class T>
inline void chkmax(T &x, const T &y) {
  if (x < y) x = y;
}
template <class T>
inline void chkmin(T &x, const T &y) {
  if (x > y) x = y;
}
template <class T>
inline void read(T &x) {
  char c;
  int f = 1;
  x = 0;
  while (((c = getchar()) < '0' || c > '9') && c != '-')
    ;
  if (c == '-')
    f = -1;
  else
    x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
  x *= f;
}
int outn;
char out[(int)2e7];
template <class T>
inline void write(T x) {
  if (x < 0) out[outn++] = '-', x = -x;
  if (x) {
    static int tmpn;
    static char tmp[20];
    tmpn = 0;
    while (x) tmp[tmpn++] = x % 10 + '0', x /= 10;
    while (tmpn) out[outn++] = tmp[--tmpn];
  } else
    out[outn++] = '0';
}
const int N = 1e5;
const double lim = 1.8 * CLOCKS_PER_SEC;
const double eps = 1e-8;
int n, k;
struct pot {
  double x, y;
  pot() { x = y = 0; }
  pot(double _x, double _y) : x(_x), y(_y) {}
  inline friend pot operator+(const pot &p, const pot &q) {
    return pot(p.x + q.x, p.y + q.y);
  }
  inline friend pot operator-(const pot &p, const pot &q) {
    return pot(p.x - q.x, p.y - q.y);
  }
  inline friend double operator*(const pot &p, const pot &q) {
    return p.x * q.x + p.y * q.y;
  }
  inline friend double operator^(const pot &p, const pot &q) {
    return p.x * q.y - p.y * q.x;
  }
  inline friend pot operator*(const pot &p, const double &k) {
    return pot(p.x * k, p.y * k);
  }
  inline friend pot operator/(const pot &p, const double &k) {
    return pot(p.x / k, p.y / k);
  }
};
struct line {
  pot p, v;
  line() {}
  line(pot _p, pot _v) : p(_p), v(_v) {}
  line(int a, int b, int c) {
    if (!b)
      p = pot((double)-c / a, 0), v = pot(0, 1);
    else if (!a)
      p = pot(0, (double)-c / b), v = pot(1, 0);
    else
      p = pot(0, (double)-c / b), v = pot(1, (double)-b / a);
  }
} l[N + 9];
std::vector<int> res;
std::vector<std::pair<int, int> > ans;
inline int getrand(int lim) { return 1ll * rand() * rand() % lim; }
inline bool parallel(const line &a, const line &b) {
  return fabs(a.v ^ b.v) < eps;
}
inline pot intersection(const line &a, const line &b) {
  pot w = b.p - a.p;
  double k = (w ^ a.v) / (a.v ^ b.v);
  return b.p + b.v * k;
}
inline bool online(const pot &x, const line &l) {
  return fabs((l.p - x) ^ l.v) < eps;
}
void dfs(int k, std::vector<int> res) {
  if (!(int)(res).size()) {
    puts("YES");
    write((int)(ans).size()), out[outn++] = '\n';
    for (int i = 0; i < (int)(ans).size(); ++i) {
      write(ans[i].first), out[outn++] = ' ';
      write(ans[i].second), out[outn++] = '\n';
    }
    printf("%s", out);
    exit(0);
  }
  if (!k) return;
  int p = getrand((int)(res).size()), q = getrand((int)(res).size());
  if (p == q) {
    ans.push_back(std::make_pair(res[p], -1));
    res.erase(find(res.begin(), res.end(), res[p]));
    dfs(k - 1, res);
    ans.pop_back();
  } else {
    if (parallel(l[res[p]], l[res[q]])) return;
    ans.push_back(std::make_pair(res[p], res[q]));
    pot x = intersection(l[res[p]], l[res[q]]);
    std::vector<int> nex;
    for (int i = 0; i < (int)(res).size(); ++i)
      if (!online(x, l[res[i]])) nex.push_back(res[i]);
    dfs(k - 1, nex);
    ans.pop_back();
  }
}
int main() {
  read(n), read(k);
  for (int i = 1; i <= n; ++i) {
    int a, b, c;
    read(a), read(b), read(c);
    l[i] = line(a, b, c);
  }
  for (int i = 1; i <= n; ++i) res.push_back(i);
  while (clock() < lim) dfs(k, res);
  puts("NO");
  return 0;
}
