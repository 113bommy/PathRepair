#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000010;
int vals[MAX];
int Prod(int w) {
  int res = 1;
  while (w > 0) {
    if (w % 10) res *= (w % 10);
    w /= 10;
  }
  return res;
}
int G(int w) {
  if (vals[w] >= 0) return vals[w];
  if (w < 10) return vals[w] = w;
  return vals[w] = G(Prod(w));
}
vector<int> by_k[10];
int main() {
  memset(vals, -1, sizeof vals);
  for (int i = 1; i <= 1000000; ++i) by_k[G(i)].push_back(i);
  int q;
  scanf("%d", &q);
  while (q-- > 0) {
    int l, r, k;
    scanf("%d%d%d", &l, &r, &k);
    printf("%d\n", (int)(lower_bound(by_k[k].begin(), by_k[k].end(), r) -
                         lower_bound(by_k[k].begin(), by_k[k].end(), l)));
  }
  return 0;
}
