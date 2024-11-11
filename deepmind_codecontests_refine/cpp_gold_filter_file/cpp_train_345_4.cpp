#include <bits/stdc++.h>
using namespace std;
const int maxn = 111111;
const int maxm = 111111;
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
struct ans {
  int x, y;
  ans() {}
  ans(int _x, int _y) {
    x = _x;
    y = _y;
  }
  bool operator<(const ans &o) const {
    if (x != o.x) return x < o.x;
    return y > o.y;
  }
};
int n, d, s;
struct yzhaj {
  int c, l, f;
} r[maxn];
int angel = 0;
vector<int> sakura;
vector<int> lily;
int main() {
  scanf("%d%d%d", &n, &d, &s);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &r[i].c, &r[i].f, &r[i].l);
    if (r[i].c) angel++;
    if (r[i].l >= d) {
      if (r[i].c)
        sakura.push_back(r[i].f);
      else
        lily.push_back(r[i].f);
    }
  }
  sort(sakura.begin(), sakura.end());
  sort(lily.begin(), lily.end());
  ans ret(0, 0);
  for (int i = 0, j = s; i < lily.size() && lily[i] <= j; ++i) {
    ret.x++;
    ret.y += lily[i];
    j -= lily[i];
  }
  lily.push_back(INF);
  sakura.push_back(INF);
  if (sakura[0] <= s) {
    ans tmp(0, 0);
    int tot = 1;
    for (int i = 0; i < n; ++i)
      if (r[i].c) tot = min(n, r[i].c + tot - 1);
    tmp.x = min(n, angel + tot);
    tmp.y = sakura[0];
    for (int i = 1, j = 0; tmp.x < n;) {
      int rec = min(sakura[i], lily[j]);
      if (rec + tmp.y > s) break;
      tmp.x++;
      tmp.y += rec;
      if (sakura[i] < lily[j])
        i++;
      else
        j++;
    }
    if (ret < tmp) ret = tmp;
  }
  printf("%d %d\n", ret.x, ret.y);
}
