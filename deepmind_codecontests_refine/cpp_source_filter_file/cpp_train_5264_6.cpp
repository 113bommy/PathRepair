#include <bits/stdc++.h>
using namespace std;
int a[100100];
multiset<int> s;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    s.insert(a[i]);
  }
  for (int i = 0; i < n; i++) {
    auto it = --s.end();
    int q = *it;
    s.erase(it);
    int res = q;
    while (q != 1) {
      q >>= 1;
      if (s.count(q) == 0) {
        res = q;
        break;
      }
    }
    s.insert(res);
  }
  for (auto i : s) {
    printf("%d ", i);
  }
  return 0;
}
