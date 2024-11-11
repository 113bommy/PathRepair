#include <bits/stdc++.h>
using namespace std;
const int maxn = 1040;
bitset<maxn> a[40], tmp;
int sp[40];
int C = 0;
int n, m;
int base = 0;
vector<int> zero;
int MSK[1 << 16], _MSK[1 << 16];
void inp() {
  int cnt;
  cin >> cnt;
  tmp = 0;
  while (cnt--) {
    int x;
    cin >> x;
    --x;
    tmp[x] = 1;
  }
}
int fndf() {
  int id = -1;
  for (int j = 0; j < n; j++) {
    if (tmp[j]) id = j;
  }
  return id;
}
int tellmsk() {
  int x = 0;
  for (int j = 0; j < m; j++) x += (tmp[n + j] << j);
  return x;
}
int to(int x) {
  int ans = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if ((((base) >> (i)) & 1) == 0) continue;
    ans += (((x) >> (i)) & 1) << cnt;
    cnt++;
  }
  return ans;
}
int main() {
  int q;
  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    inp();
    tmp[n + i] = 1;
    for (int j = 0; j < C; j++) {
      if (tmp[sp[j]]) tmp = tmp ^ a[j];
    }
    int id = fndf();
    if (id == -1) {
      zero.push_back(tellmsk());
    } else {
      base |= 1 << i;
      sp[C] = id;
      a[C] = tmp;
      C++;
    }
  }
  if ((int(zero.size())) * 2 < m) {
    for (int msk = 1; msk < (1 << (int(zero.size()))); msk++) {
      int lst = __builtin_ctz(msk);
      MSK[msk] = MSK[msk ^ (1 << lst)] ^ zero[lst];
    }
  } else {
    int len = __builtin_popcount(base);
    memset(MSK, 63, sizeof MSK);
    MSK[0] = 0;
    for (int x : zero) {
      x = to(x);
      memcpy(_MSK, MSK, sizeof MSK);
      for (int msk = 0; msk < (1 << len); msk++)
        MSK[msk] = min(MSK[msk], _MSK[msk ^ x] + 1);
    }
  }
  while (q--) {
    inp();
    for (int i = 0; i < C; i++) {
      if (tmp[sp[i]]) tmp = tmp ^ a[i];
    }
    if (fndf() != -1) {
      cout << -1 << "\n";
      continue;
    }
    int chose = tellmsk();
    int ans = __builtin_popcount(chose);
    if ((int(zero.size())) * 2 < m) {
      for (int msk = 1; msk < (1 << (int(zero.size()))); msk++)
        ans = min(ans, __builtin_popcount(chose ^ MSK[msk]));
    } else {
      chose = to(chose);
      int len = __builtin_popcount(base);
      for (int msk = 0; msk < (1 << len); msk++)
        ans = min(ans, MSK[msk] + __builtin_popcount(msk ^ chose));
    }
    cout << ans << "\n";
  }
  return 0;
}
