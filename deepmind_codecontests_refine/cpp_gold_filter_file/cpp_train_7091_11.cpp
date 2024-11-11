#include <bits/stdc++.h>
using namespace std;
const int oo = ~0u >> 2, mo = 12345;
const int mn = 26, mm = 20, ms = 200;
struct REC {
  int h, v;
  REC() {}
  REC(int _h, int _v) { h = _h, v = _v; }
};
vector<REC> rec;
struct MAT {
  int a[ms];
} e, f;
int s[ms][ms], co[mm];
bool one[mn];
vector<int> g[mn];
int m, l, num_one;
long long n;
MAT times(MAT a, MAT b) {
  MAT ret;
  memset(&ret, 0, sizeof(ret));
  for (int i = 0; i <= l; ++i)
    for (int j = 0; j <= l; ++j)
      ret.a[s[i][j]] = ((long long)a.a[i] * b.a[j] + ret.a[s[i][j]]) % mo;
  return ret;
}
MAT calc(long long n) {
  if (n == 1) return e;
  MAT ret;
  if (n & 1) {
    ret = calc(n - 1);
    ret = times(ret, e);
  } else {
    ret = calc(n / 2);
    ret = times(ret, ret);
  }
  return ret;
}
int main() {
  cin >> n >> m;
  if (!n) {
    printf("1\n");
    return 0;
  }
  for (int i = 1; i <= m; ++i) {
    char ch;
    int t;
    do {
      cin >> ch;
    } while (ch < 'A' || ch > 'Z');
    cin >> t;
    int h = ch - 'A';
    if (t == 1)
      num_one += !one[h], one[h] = 1;
    else
      g[h].push_back(t);
  }
  l = 1;
  for (int i = 0; i <= mn - 1; ++i)
    if (!one[i])
      for (int j = 0; j <= ((int)(g[i]).size()) - 1; ++j) {
        rec.push_back(*(new REC(i, g[i][j])));
        l *= g[i][j];
      }
  --l;
  for (int X = 0; X <= l; ++X)
    for (int Y = 0; Y <= l; ++Y) {
      int sum[mm], x = X, y = Y;
      for (int i = 0; i <= ((int)(rec).size()) - 1; ++i)
        sum[i] = (x + y) % rec[i].v, x /= rec[i].v, y /= rec[i].v;
      s[X][Y] = 0;
      for (int i = ((int)(rec).size()) - 1; i >= 0; --i)
        s[X][Y] = s[X][Y] * rec[i].v + sum[i];
    }
  co[0] = 1;
  for (int i = 1; i <= ((int)(rec).size()); ++i)
    co[i] = co[i - 1] * rec[i - 1].v;
  memset(&e, 0, sizeof(e)), e.a[0] = num_one;
  for (int i = 0; i <= ((int)(rec).size()) - 1; ++i) {
    int t = 0;
    for (int j = 0; j <= ((int)(rec).size()) - 1; ++j)
      if (rec[i].h == rec[j].h) t += co[j];
    e.a[t] = 1;
  }
  f = calc(n);
  int Ans = 0;
  for (int i = 0; i <= l; ++i)
    if (f.a[i]) {
      bool v[mn];
      int t = i;
      memset(&v, 0, sizeof(v));
      for (int j = 0; j <= ((int)(rec).size()) - 1; ++j) {
        if (!(t % rec[j].v)) v[rec[j].h] = 1;
        t /= rec[j].v;
      }
      bool flag = 1;
      for (int j = 0; j <= ((int)(rec).size()) - 1; ++j)
        if (!v[rec[j].h]) {
          flag = 0;
          break;
        }
      if (flag) Ans = (Ans + f.a[i]) % mo;
    }
  cout << Ans << endl;
}
