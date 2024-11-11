#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int n, k, a[N], s[N], pr[N], ne[N];
long long ans = 0;
vector<int> b[N];
pair<int, int> e[N];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  s[0] = 0;
  for (int i = 1; i <= n; i++) {
    s[i] = (s[i - 1] + a[i]) % k;
  }
  for (int i = 0; i <= n; i++) {
    b[s[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    e[i - 1] = make_pair(a[i], i);
  }
  sort(e, e + n);
  for (int i = 0; i <= n + 1; i++) {
    pr[i] = i - 1;
    ne[i] = i + 1;
  }
  for (int it = 0; it < n; it++) {
    int id = e[it].second;
    int val = a[id] % k;
    int from = pr[id] + 1;
    int to = ne[id] - 1;
    if (id - from <= to - id) {
      for (int i = from; i <= id; i++) {
        int z = s[i - 1] + val;
        if (z >= k) {
          z -= k;
        }
        ans += lower_bound(b[z].begin(), b[z].end(), to + 1) -
               lower_bound(b[z].begin(), b[z].end(), i);
      }
    } else {
      for (int i = id; i <= to; i++) {
        int z = s[id] - val;
        if (z < 0) {
          z += k;
        }
        ans += lower_bound(b[z].begin(), b[z].end(), i) -
               lower_bound(b[z].begin(), b[z].end(), from - 1);
      }
    }
    pr[ne[id]] = pr[id];
    ne[pr[id]] = ne[id];
  }
  printf("%I64d\n", ans - n);
  return 0;
}
