#include <bits/stdc++.h>
using namespace std;
inline int read(int u = 0, char c = getchar(), bool f = false) {
  for (; !isdigit(c); c = getchar()) f |= c == '-';
  for (; isdigit(c); c = getchar()) u = (u << 1) + (u << 3) - '0' + c;
  return f ? -u : u;
}
namespace Geo {
const double pi = acos(-1);
const double eps = 1e-6;
int sign(double x) { return (x > eps) - (x < -eps); }
struct vec {
  double x, y;
  vec(double x = 0, double y = 0) : x(x), y(y) {}
  friend vec operator+(vec a, vec b) { return vec(a.x + b.x, a.y + b.y); }
  friend vec operator-(vec a, vec b) { return vec(a.x - b.x, a.y - b.y); }
  friend vec operator*(vec a, double b) { return vec(a.x * b, a.y * b); }
  friend vec operator*(double b, vec a) { return a * b; }
  friend vec operator/(vec a, double b) { return a * (1 / b); }
  friend double operator*(vec a, vec b) { return a.x * b.x + a.y * b.y; }
  friend double operator^(vec a, vec b) { return a.x * b.y - a.y * b.x; }
  double dis() { return sqrt(*this * *this); }
  vec normal() { return vec(-y, x) / dis(); }
  friend bool operator==(vec a, vec b) {
    return !sign(a.x - b.x) && !sign(a.y - b.y);
  }
};
bool cmpx(vec a, vec b) {
  return sign(a.x - b.x) < 0 || (sign(a.x - b.x) == 0 && sign(a.y - b.y) < 0);
}
struct cir {
  vec o;
  double r;
  cir(vec o = vec(0, 0), double r = 0) : o(o), r(r) {}
  friend vector<vec> operator&(cir a, cir b) {
    if (sign(a.r - b.r) < 0) swap(a, b);
    vector<vec> ans;
    vec u = b.o - a.o;
    if (sign(u.dis() - a.r - b.r) > 0)
      return ans;
    else if (sign(u.dis() - abs(a.r - b.r)) < 0)
      return ans;
    else if (sign(u.dis() - a.r - b.r) == 0)
      ans.push_back(u * a.r / (a.r + b.r) + a.o);
    else if (sign(u.dis() - abs(a.r - b.r)) == 0)
      ans.push_back(u * a.r / u.dis() + a.o);
    else {
      double x = u.dis(), y = a.r, z = b.r;
      double p = (x + y + z) / 2;
      double S = sqrt((p - x) * (p - y) * (p - z) * p);
      double h = S * 2 / x;
      double s = sqrt(y * y - h * h);
      vec v = u * s / x, w = u.normal() * h;
      ans.push_back(a.o + v + w);
      ans.push_back(a.o + v - w);
    }
    return ans;
  }
};
}  // namespace Geo
using namespace Geo;
const int maxn = 10;
cir C[maxn];
vector<vec> all;
vector<vec> coc[maxn];
struct MFS {
  vector<int> fa;
  void init(int n) {
    fa.resize(n + 1);
    for (int i = 1; i <= n; i++) fa[i] = i;
  }
  int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
  void merge(int x, int y) { fa[find(x)] = find(y); }
} St;
int bel[maxn];
int main() {
  int n = read();
  St.init(n);
  int v = 0, c = 0, e = 0;
  for (int i = 1; i <= n; i++)
    C[i].o.x = read(), C[i].o.y = read(), C[i].r = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) {
        vector<vec> ans = C[i] & C[j];
        for (int k = ans.size() - 1; ~k; --k)
          coc[i].push_back(ans[k]), all.push_back(ans[k]);
        if (ans.size()) St.merge(i, j);
      }
  for (int i = 1; i <= n; i++) {
    sort(coc[i].begin(), coc[i].end(), cmpx);
    coc[i].erase(unique(coc[i].begin(), coc[i].end()), coc[i].end());
    e += coc[i].size();
  }
  sort(all.begin(), all.end(), cmpx);
  all.erase(unique(all.begin(), all.end()), all.end());
  v = all.size();
  for (int i = 1; i <= n; i++) bel[i] = St.find(i);
  sort(bel + 1, bel + 1 + n);
  c = unique(bel + 1, bel + 1 + n) - bel - 1;
  cout << e + c + 1 - v << endl;
}
