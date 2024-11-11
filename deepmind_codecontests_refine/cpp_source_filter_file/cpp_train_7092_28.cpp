#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int n, u, v, w;
int f[N], sz[N];
bool isLucky(int num) {
  while (num) {
    int x = num % 10;
    num /= 10;
    if (x - 4 && x - 7) return 0;
  }
  return 1;
}
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) f[i] = i, sz[i] = 1;
  for (int i = 1; i <= n - 1; ++i) {
    scanf("%d %d %d", &u, &v, &w);
    if (!isLucky(w)) {
      sz[find(v)] += sz[find(u)];
      f[find(u)] = find(v);
    }
  }
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    int ret = sz[f[i]];
    ret = n - ret;
    res += (ret * 1ll * (ret - 1));
  }
  cout << res << endl;
}
