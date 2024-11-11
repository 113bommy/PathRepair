#include <bits/stdc++.h>
using namespace std;
int n, mx;
set<int> s;
int main() {
  scanf("%d", &n);
  for (int i = 0, x; i < 2 * n; i++) {
    scanf("%d", &x);
    if (s.find(x) == s.end()) {
      s.insert(x);
      mx = max(mx, (int)s.size());
    } else
      s.erase(x);
  }
  printf("%d", mx);
}
