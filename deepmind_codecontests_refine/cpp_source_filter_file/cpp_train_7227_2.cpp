#include <bits/stdc++.h>
using namespace std;
bool done[5000];
int main() {
  int x, k, mx = 0, mn = 0;
  scanf("%d%d\n", &x, &k);
  for (int i = 1; i <= k; ++i) {
    short type;
    scanf("%d\n", &type);
    if (type == 1) {
      int a, b;
      scanf("%d%d\n", &a, &b);
      done[a] = 1;
      done[b] = 1;
    }
    if (type == 2) {
      int a;
      scanf("%d\n", &a);
      done[a] = 1;
    }
  }
  for (int i = 1; i < x; ++i) {
    if (done[i] == 0) ++mx;
  }
  for (int i = 1; i < x; ++i) {
    if (done[i] == 0 && done[i + 1] == 0) {
      ++mn;
      done[i] = 1, done[i + 1] = 1;
    } else if (done[i] == 0)
      done[i] = 1, ++mn;
  }
  cout << mn << " " << mx;
  return 0;
}
