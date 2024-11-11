#include <bits/stdc++.h>
using namespace std;
long long int modpow(long long int a, long long int n, long long int temp) {
  long long int res = 1, y = a;
  while (n > 0) {
    if (n & 1) res = (res * y) % temp;
    y = (y * y) % temp;
    n /= 2;
  }
  return res % temp;
}
vector<long long int> arr[4111];
vector<pair<long long int, long long int> > edges;
long long int countit[4111], ans = (int)(1e9 + 7);
int main() {
  long long int n, m, i, val, v1, v2, j, sz;
  scanf("%lld", &n);
  scanf("%lld", &m);
  for (i = 0; i < m; ++i) {
    scanf("%lld", &v1);
    scanf("%lld", &v2);
    edges.push_back(make_pair(v1, v2));
    arr[v1].push_back(v2);
    arr[v2].push_back(v1);
  }
  for (i = 0; i < m; ++i) {
    memset(countit, 0, sizeof(countit));
    v1 = edges[i].first;
    v2 = edges[i].second;
    sz = arr[v1].size();
    for (j = 0; j < sz; ++j) countit[arr[v1][j]]++;
    sz = arr[v2].size();
    for (j = 0; j < sz; ++j) countit[arr[v2][j]]++;
    val = arr[v1].size() + arr[v2].size();
    for (i = 1; i < 4111; ++i) {
      if (countit[i] == 2 && i != v1 && i != v2) {
        if (ans > val + arr[i].size() - 6) ans = val + arr[i].size() - 6;
      }
    }
  }
  if (ans == (int)(1e9 + 7)) ans = -1;
  printf("%lld\n", ans);
  return 0;
}
