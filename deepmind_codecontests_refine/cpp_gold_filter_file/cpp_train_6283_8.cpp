#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int n, a[100007], b[100007];
int where[100007];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  for (int i = 0; i < n; i++) --a[i], --b[i];
  for (int i = 0; i < n; i++) where[a[i]] = i;
  multiset<int> l, r;
  for (int i = 0; i < n; i++) l.insert(where[b[i]] - i);
  int ld, rd;
  ld = 0;
  rd = n;
  for (int i = 0; i < n; i++) {
    int ans = 0x7f7f7f7f;
    if (l.size()) {
      multiset<int>::iterator it = l.lower_bound(-ld);
      if (it != l.end()) ans = min(ans, abs(*it + ld));
      if (it != l.begin()) {
        --it;
        ans = min(ans, abs(*it + ld));
      }
    }
    if (r.size()) {
      multiset<int>::iterator it = r.lower_bound(rd);
      if (it != r.end()) ans = min(ans, abs(*it - rd));
      if (it != r.begin()) {
        --it;
        ans = min(ans, abs(*it - rd));
      }
    }
    l.erase(l.find(where[b[i]] - i));
    r.insert(where[b[i]] - i);
    ++ld;
    --rd;
    printf("%d\n", ans);
  }
  return 0;
}
