#include <bits/stdc++.h>
using namespace std;
const int inf = 1e5 + 9;
long long num[inf];
multiset<long long> s;
set<int> idx;
int main() {
  int n, a;
  scanf("%d", &n);
  idx.insert(0);
  idx.insert(n + 1);
  for (int i = 1; i <= n; ++i) scanf("%d", &num[i]);
  for (int i = 1; i <= n; ++i) num[i] += num[i - 1];
  s.insert(num[n]);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a);
    set<int>::iterator it = idx.lower_bound(a);
    set<int>::iterator it2 = prev(it);
    s.erase(s.find(num[*it - 1] - num[*it2]));
    s.insert(num[*it - 1] - num[a]);
    s.insert(num[a - 1] - num[*it2]);
    idx.insert(a);
    printf("%I64d\n", *s.rbegin());
  }
}
