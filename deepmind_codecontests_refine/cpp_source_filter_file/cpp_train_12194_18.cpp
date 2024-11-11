#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10, maxV = 6;
bitset<maxV> f[maxV + 10], ie[maxV + 10], sets[maxN];
int q, n;
void print_set(bitset<maxV>& x) {
  for (int i = 0; i < maxV; ++i)
    if (x[i])
      cout << 1;
    else
      cout << 0;
  cout << endl;
}
bool is_square_free(int x) {
  for (int i = 2; i * i <= x; ++i)
    if (x % (i * i) == 0) return false;
  return true;
}
void init() {
  for (int i = 1; i <= maxV; ++i) {
    for (int j = 1; j * j <= i; ++j)
      if (i % j == 0) {
        f[i].set(j - 1);
        if (j * j != i) f[i].set((i / j) - 1);
      }
    for (int j = 1; i * j <= maxV; ++j)
      if (is_square_free(j)) ie[i].set((i * j) - 1);
  }
}
int main() {
  cin >> n >> q;
  init();
  for (int i = 0; i < q; ++i) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int x, v;
      scanf("%d %d", &x, &v);
      sets[x] = f[v];
    } else if (t == 2) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      sets[x] = sets[y] ^ sets[z];
    } else if (t == 3) {
      int x, y, z;
      scanf("%d %d %d", &x, &y, &z);
      sets[x] = sets[y] & sets[z];
    } else if (t == 4) {
      int x, v;
      scanf("%d %d", &x, &v);
      int cnt = (sets[x] & ie[v]).count();
      printf("%d", cnt % 2);
    }
  }
}
