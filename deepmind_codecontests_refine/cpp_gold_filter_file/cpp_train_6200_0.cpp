#include <bits/stdc++.h>
using namespace std;
inline int F() {
  register int aa, bb, ch;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  ch == '-' ? aa = bb = 0 : (aa = ch - '0', bb = 1);
  while (ch = getchar(), ch >= '0' && ch <= '9') aa = aa * 10 + ch - '0';
  return bb ? aa : -aa;
}
const int mod = 100007;
const int Maxn = 100010;
int n;
namespace hash {
struct node {
  int w, ai;
};
std::vector<node> v[Maxn];
int ha[40];
void init() {
  ha[0] = 1;
  for (int i = 1; i <= 30; ++i) ha[i] = ha[i - 1] << 1;
}
void ins(int x) {
  int tmp = x % mod;
  for (int i = 0; i < v[tmp].end() - v[tmp].begin(); ++i) {
    if (v[tmp][i].ai == x) {
      ++v[tmp][i].w;
      return;
    }
  }
  node aa = (node){1, x};
  v[tmp].push_back(aa);
}
int find(int x) {
  int tmp = x % mod, ret = 0;
  for (int i = 0; i < v[tmp].end() - v[tmp].begin(); ++i) {
    if (v[tmp][i].ai == x) return v[tmp][i].w;
  }
  return 0;
}
}  // namespace hash
using namespace hash;
int main() {
  init();
  n = F();
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    int tmp = F();
    for (int j = 1; j < 31; ++j)
      if (ha[j] >= tmp) {
        ans += find(ha[j] - tmp);
      }
    ins(tmp);
  }
  cout << ans;
}
