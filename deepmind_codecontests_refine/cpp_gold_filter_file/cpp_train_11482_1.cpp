#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
namespace Discrete {
int b[MAXN], btol, blen;
void insert(int x) { b[btol++] = x; }
void init() {
  sort(b, b + btol);
  blen = unique(b, b + btol) - b;
}
int val2id(int x) { return lower_bound(b, b + blen, x) - b + 1; }
}  // namespace Discrete
using Discrete::val2id;
int a[MAXN];
vector<int> vec[MAXN];
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    Discrete::btol = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), Discrete::insert(a[i]);
    Discrete::init();
    for (int i = 1; i <= n; i++) a[i] = val2id(a[i]);
    for (int i = 1; i <= Discrete::blen; i++) vec[i].clear();
    for (int i = 1; i <= n; i++) {
      vec[a[i]].push_back(i);
    }
    if (Discrete::blen == 1) {
      printf("NO\n");
    } else {
      printf("YES\n");
      for (int i = 2; i <= Discrete::blen; i++) {
        for (auto j : vec[i]) {
          printf("%d %d\n", j, vec[1][0]);
        }
      }
      for (int i = 1; i < (int)vec[1].size(); i++) {
        printf("%d %d\n", vec[1][i], vec[2][0]);
      }
    }
  }
}
