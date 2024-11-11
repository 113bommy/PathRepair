#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 1;
map<long long, long long> p;
vector<long long> v;
int n, size;
long long t, k;
int main() {
  scanf("%d %lld", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &t);
    p[t]++;
    v.push_back(t);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  size = v.size();
  long long minn = v[0], maxx = v[size - 1], l = 0, r = size;
  while (k > 0 && l < r) {
    if (p[v[l]] <= p[v[r]]) {
      long long sum = (v[l + 1] - v[l]) * p[v[l]];
      if (sum <= k) {
        k -= sum;
        p[v[l + 1]] += p[v[l]];
        l++;
        minn = v[l];
      } else {
        minn = v[l] + (k / p[v[l]]);
        k = 0;
      }
    } else {
      long long sum = (v[r] - v[r - 1]) * p[v[r]];
      if (sum <= k) {
        k -= sum;
        p[v[r - 1]] += p[v[r]];
        r--;
        maxx = v[r];
      } else {
        maxx = v[r] - (k / p[v[r]]);
        k = 0;
      }
    }
  }
  printf("%lld\n", maxx - minn);
}
