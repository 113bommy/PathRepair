#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300010;
const int MAXP = 300010;
const int MAXD = 350;
int n, a, b, p, s[MAXN], d, cnt;
long long f[MAXN], ans[MAXN];
struct Scenario {
  int a, b, index;
  Scenario() {}
  Scenario(int _a, int _b, int _index) : a(_a), b(_b), index(_index) {}
} que[MAXP];
inline bool cmp(const Scenario &a, const Scenario &b) { return a.b < b.b; }
inline long long calc(int a, int b) {
  long long res = 0;
  for (int i = a; i <= n; i += b) res += s[i];
  return res;
}
int main(int argc, char *argv[]) {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", s + i);
  scanf("%d", &p);
  for (int i = 0; i < p; ++i) {
    scanf("%d%d", &a, &b);
    que[i] = Scenario(a, b, i);
  }
  sort(que, que + p, cmp);
  d = int(sqrt(n));
  for (int i = 0; i < p; ++i)
    if (que[i].b <= d) {
      b = que[i].b;
      for (cnt = i; cnt < p && que[cnt].b == b; ++cnt)
        ;
      for (int j = n; j; --j) {
        f[j] = s[j];
        if (j + b <= n) f[j] += f[j + b];
      }
      for (int j = i; j < cnt; ++j) ans[que[i].index] = f[que[i].a];
      i = cnt - 1;
    } else
      ans[que[i].index] = calc(que[i].a, que[i].b);
  for (int i = 0; i < p; ++i) cout << ans[i] << endl;
}
