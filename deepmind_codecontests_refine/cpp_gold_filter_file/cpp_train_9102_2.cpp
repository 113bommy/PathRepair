#include <bits/stdc++.h>
using namespace std;
;
const double eps = 1e-8;
const int mod = 1000000007;
const int maxn = 1e5 + 7;
const double pi = acos(-1);
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
int n, m;
vector<int> L, R, v;
int p[maxn], isp[maxn], vis[maxn];
void init(int n) {
  for (int i = 2; i <= n; i++) {
    p[i] = 1;
  }
  for (int i = 2; i * i <= n; i++) {
    if (p[i]) {
      for (int j = i * i; j <= n; j += i) {
        p[j] = 0;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    if (p[i]) isp[m++] = i;
  }
}
int main() {
  scanf("%d", &n);
  init(n);
  for (int i = 1; i < m; i++) {
    v.clear();
    for (int j = isp[i]; j <= n; j += isp[i]) {
      if (vis[j]) continue;
      v.push_back(j);
    }
    if (v.size() % 2 == 1) {
      for (int j = 0; j < (int)v.size(); j++) {
        if (v[j] % 2 == 0) {
          v.erase(v.begin() + j);
          break;
        }
      }
    }
    for (int j = 1; j < (int)v.size(); j += 2) {
      vis[v[j - 1]] = vis[v[j]] = 1;
      L.push_back(v[j - 1]);
      R.push_back(v[j]);
    }
  }
  v.clear();
  for (int i = 2; i <= n; i += 2) {
    if (vis[i]) continue;
    v.push_back(i);
  }
  for (int i = 1; i < (int)v.size(); i += 2) {
    L.push_back(v[i - 1]);
    R.push_back(v[i]);
  }
  printf("%d\n", (int)L.size());
  for (int i = 0; i < (int)L.size(); i++) {
    printf("%d %d\n", L[i], R[i]);
  }
  return 0;
}
