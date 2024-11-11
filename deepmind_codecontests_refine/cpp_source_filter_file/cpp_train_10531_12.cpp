#include <bits/stdc++.h>
using namespace std;
const int N = (int)6e5 + 5;
const int inf = (int)1e9 + 7;
int n, x;
int p[N];
set<int> s;
int main() {
  scanf("%d %d", &n, &x);
  for (int i = 1; i <= (1 << n); ++i) {
    if (i == x) continue;
    s.insert(i);
  }
  s.erase(x);
  int l = 0;
  while (!s.empty()) {
    ++l, p[l] = *s.begin();
    s.erase(s.begin());
    s.erase(p[l] ^ x);
  }
  printf("%d\n", l);
  for (int i = 1; i <= l; ++i) {
    printf("%d ", p[i] ^ p[i - 1]);
  }
  return 0;
}
