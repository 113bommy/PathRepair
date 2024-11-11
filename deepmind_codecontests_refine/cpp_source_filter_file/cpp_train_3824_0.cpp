#include <bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7;
int u, v, mod, x, a[105];
map<int, vector<int> > mp;
inline int myrand() { return x = (1LL * x * 17 + 13) % m; }
inline int ksm(int x, int n) {
  int ret = 1;
  while (n) {
    if (n & 1) ret = 1LL * ret * x % mod;
    n >>= 1;
    x = 1LL * x * x % mod;
  }
  return ret;
}
inline int change(int x, int t) {
  if (!t)
    return (x + 1) % mod;
  else if (t == 1)
    return (x + mod - 1) % mod;
  return ksm(x, mod - 2);
}
int main() {
  scanf("%d%d%d", &u, &v, &mod);
  if (u == v) return 0 * puts("0");
  for (int i = 0; i < 31234; ++i) {
    int t = u;
    vector<int> vec;
    for (int j = 0; j < 100; ++j) {
      int x = myrand() % 3;
      t = change(t, x);
      vec.push_back(x);
    }
    if (!mp.count(t)) mp[t] = vec;
  }
  if (mp.count(v)) {
    puts("100");
    vector<int> &vv = mp[v];
    for (int i = 0; i < (int)vv.size(); ++i) printf("%d ", vv[i] + 1);
    return 0;
  }
  while (1) {
    int t = v;
    bool flag = false;
    vector<int> vec;
    for (int i = 0; i < 100; ++i) {
      int x = myrand() % 3;
      vec.push_back(x);
      t = change(t, x ^ 1);
    }
    if (mp.count(t)) flag = true;
    if (flag) {
      puts("200");
      vector<int> &vv = mp[t];
      for (int i = 0; i < (int)vv.size(); ++i) printf("%d ", vv[i] + 1);
      for (int i = 0; i < (int)vec.size(); ++i) printf("%d ", vec[99 - i]);
      break;
    }
  }
  return 0;
}
