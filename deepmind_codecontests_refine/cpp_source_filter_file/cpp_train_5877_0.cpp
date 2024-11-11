#include <bits/stdc++.h>
using namespace std;
void fre() {
  freopen("c://test//input.in", "r", stdin);
  freopen("c://test//output.out", "w", stdout);
}
template <class T1, class T2>
inline void gmax(T1 &a, T2 b) {
  if (b > a) a = b;
}
template <class T1, class T2>
inline void gmin(T1 &a, T2 b) {
  if (b < a) a = b;
}
const int N = 1e5 + 10, M = 0, Z = 1e9 + 7, ms63 = 0x3f3f3f3f;
int n, d;
long long x;
int a[N], b[N];
long long getNextX() {
  x = (x * 37 + 10007) % 1000000007;
  return x;
}
void initAB() {
  for (int i = 0; i < n; i = i + 1) a[i] = i + 1;
  for (int i = 0; i < n; i = i + 1) swap(a[i], a[getNextX() % (i + 1)]);
  for (int i = 0; i < n; i = i + 1) {
    if (i < d)
      b[i] = 1;
    else
      b[i] = 0;
  }
  for (int i = 0; i < n; i = i + 1) swap(b[i], b[getNextX() % (i + 1)]);
}
set<pair<int, int> > sot;
vector<int> c;
int main() {
  while (~scanf("%d%d%lld", &n, &d, &x)) {
    sot.clear();
    c.clear();
    initAB();
    for (int i = 0; i < n; ++i) {
      sot.insert(make_pair(-a[i], i));
      if (sot.size() > 30) sot.erase(sot.begin());
      if (b[i]) c.push_back(i);
      int ans = 0;
      for (auto &it : sot) {
        if (b[i - it.second]) {
          ans = -it.first;
          break;
        }
      }
      if (!ans) {
        for (int j = c.size() - 1; ~j; --j) gmax(ans, a[i - c[j]]);
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
