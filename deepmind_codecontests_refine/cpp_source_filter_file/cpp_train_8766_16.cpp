#include <bits/stdc++.h>
using namespace std;
int Gcd(int a, int b) {
  if (b == 0) return a;
  return Gcd(b, a % b);
}
int Lcm(int a, int b) { return a / Gcd(a, b) * b; }
template <class T>
void read(T &x) {
  static char ch;
  static bool neg;
  for (ch = neg = 0; ch < '0' || '9' < ch; neg |= ch == '-', ch = getchar())
    ;
  for (x = 0; '0' <= ch && ch <= '9'; (x *= 10) += ch - '0', ch = getchar())
    ;
  x = neg ? -x : x;
}
const int maxn = 1e6 + 10;
struct node {
  long long x, y;
} p[maxn];
vector<node> v;
long long sum[maxn];
int main() {
  long long x0, y0, ax, ay, bx, by, xs, ys, t;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  cin >> xs >> ys >> t;
  long long nowx = x0, nowy = y0;
  for (int i = 0; nowx <= 1E17 && nowy <= 1E17; i++) {
    v.push_back((node){nowx, nowy});
    long long tx = ax * nowx + bx;
    long long ty = ay * nowy + by;
    if (i > 0) sum[i] = sum[i - 1] + tx - nowx + ty - nowy;
    nowx = tx;
    nowy = ty;
  }
  int ans = 0;
  for (int i = 0; i < v.size(); i++) {
    int tot = 0;
    node tmp = v[i];
    long long len = abs(xs - tmp.x) + abs(ys - tmp.y);
    if (len <= t) {
      tot++;
      ans = max(ans, tot);
    }
    for (int j = i - 1; j >= 0; j--) {
      long long add = abs(v[j + 1].x - v[j].x) + abs(v[j + 1].y - v[j].y);
      if (add + len <= t) {
        len += add;
        tot++;
      } else {
        ans = max(ans, tot);
        break;
      }
    }
    for (int j = i + 1; j < v.size(); j++) {
      long long add = abs(v[j - 1].x - v[j].x) + abs(v[j - 1].y - v[j].y);
      if (j == i + 1) add += abs(v[0].x - v[i].x) + abs(v[0].y - v[i].x);
      if (add + len <= t) {
        len += add;
        tot++;
      } else {
        ans = max(ans, tot);
        break;
      }
    }
    ans = max(ans, tot);
  }
  cout << ans << endl;
  return 0;
}
