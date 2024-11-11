#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, l[N], r[N];
multiset<int> a, b;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &l[i], &r[i]);
    a.insert(l[i]);
    b.insert(r[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    a.erase(a.find(l[i]));
    b.erase(b.find(r[i]));
    ans = max(ans, *b.begin() - *a.rbegin());
    a.insert(l[i]);
    b.insert(r[i]);
  }
  printf("%d\n", ans);
  return 0;
}
