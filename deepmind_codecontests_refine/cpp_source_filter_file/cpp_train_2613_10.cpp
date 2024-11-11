#include <bits/stdc++.h>
using namespace std;
const int P = 1e9 + 7;
const int inf = 1e9;
int N;
char tmp[99];
set<int> s;
int lo = -inf, hi = inf;
int main() {
  scanf("%d", &N);
  s.insert(-inf);
  s.insert(inf);
  int ans = 1;
  for (int i = 0, x; i < N; i++) {
    scanf("%s%d", tmp, &x);
    if (tmp[1] == 'D') {
      s.insert(x);
    } else {
      if (x < lo || x > hi) {
        ans = 0;
        break;
      }
      if (ans != lo && ans != hi) {
        ans = (ans * 2ll) % P;
      }
      auto it = s.find(x);
      it++;
      hi = *it;
      it--;
      it--;
      lo = *it;
      it++;
      s.erase(it);
    }
  }
  int n = 0;
  for (int x : s) {
    if (x != -inf && x != inf && lo < x && x < hi) {
      n++;
    }
  }
  ans = (1ll * ans * (n + 1)) % P;
  printf("%d\n", ans);
}
