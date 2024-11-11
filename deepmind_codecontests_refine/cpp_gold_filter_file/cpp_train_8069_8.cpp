#include <bits/stdc++.h>
using namespace std;
long long n, m, t, k, i, j, s[3005], x, y, l[3005], r[3005], to[3005],
    val[3005], ans, tmp;
vector<long long> pos[3005];
void ins(long long &x, long long y) {
  r[x] = y;
  l[y] = x;
  x = y;
}
void shan(long long x) {
  l[r[x]] = l[x];
  r[l[x]] = r[x];
}
int main() {
  scanf("%I64d%I64d%I64d%I64d", &n, &m, &t, &k);
  for ((i) = 1; (i) <= (t); (i)++) {
    scanf("%I64d%I64d", &x, &y);
    pos[x].push_back(y);
  }
  for ((i) = 1; (i) <= (n); (i)++) {
    for ((j) = (i); (j) <= (n); (j)++)
      for (__typeof((pos[j]).begin()) it = (pos[j]).begin();
           it != (pos[j]).end(); it++)
        s[*it]++;
    tmp = 0;
    long long lst = 0;
    for ((j) = 1; (j) <= (m); (j)++)
      if (s[j]) ins(lst, j);
    ins(lst, m + 1);
    long long p = 0, sum = 0;
    for (j = r[0]; j <= m; j = r[j]) {
      while (sum < k && p <= m) {
        p = r[p];
        sum += s[p];
      }
      tmp += (j - l[j]) * (m - p + 1);
      to[j] = p;
      val[j] = sum;
      sum -= s[j];
    }
    for ((j) = (n); (j) >= (i); (j)--) {
      ans += tmp;
      for (__typeof((pos[j]).begin()) it = (pos[j]).begin();
           it != (pos[j]).end(); it++) {
        s[*it]--;
        long long p = *it, sum = 0;
        while (p && sum + s[l[p]] < k) {
          p = l[p];
          sum += s[p];
        }
        while (p <= *it) {
          if ((--val[p]) < k && to[p] <= m) {
            tmp -= (p - l[p]) * (r[to[p]] - to[p]);
            to[p] = r[to[p]];
            val[p] += s[to[p]];
          }
          p = r[p];
        }
        if (!s[*it]) shan(*it);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
