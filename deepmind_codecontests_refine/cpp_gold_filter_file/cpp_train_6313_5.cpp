#include <bits/stdc++.h>
using namespace std;
const int maxn = 102000;
int n;
long long vol[maxn], tmp[maxn], sz;
multiset<long long> s;
void read() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%I64d", &vol[i]);
  for (int i = 1; i <= n; i++) scanf("%I64d", &tmp[i]);
}
long long ans[maxn];
void work() {
  sz = 0;
  for (int i = 1; i <= n; i++) {
    s.insert(vol[i] + sz);
    while (!s.empty()) {
      long long data = *s.begin();
      if (data <= sz + tmp[i]) {
        ans[i] += data - sz;
        s.erase(s.begin());
      } else
        break;
    }
    ans[i] += ((long long)s.size() * tmp[i]);
    sz += tmp[i];
  }
  for (int i = 1; i <= n; i++) printf("%I64d ", ans[i]);
}
int main() {
  read();
  work();
  return 0;
}
