#include <bits/stdc++.h>
using namespace std;
int a[1000001];
vector<int> b;
map<int, int> mapa;
int n;
int bit[1000001];
vector<int> v;
inline void update(int x, int val) {
  while (x <= n) {
    bit[x] += val;
    x += (x & -x);
  }
}
inline int read(int x) {
  int ret = 0;
  while (x > 0) {
    ret += bit[x];
    x -= (x & -x);
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b.push_back(a[i]);
  }
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++) mapa[b[i]] = i + 1;
  int lowest = 1000001 - 1;
  for (int i = n - 1; i >= 0; i--) {
    if (read(mapa[a[i]] - 1) == 0)
      v.push_back(-1);
    else
      v.push_back(read(mapa[a[i]] - 1) - 1 - i - 1);
    if (mapa[a[i]] < lowest) {
      update(mapa[a[i]], i + 1);
      update(lowest, -i - 1);
      lowest = mapa[a[i]];
    }
  }
  reverse(v.begin(), v.end());
  for (int i = 0; i < v.size(); i++) printf("%d ", v[i]);
  printf("\n");
  return 0;
}
