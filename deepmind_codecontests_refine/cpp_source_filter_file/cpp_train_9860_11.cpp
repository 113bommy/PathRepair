#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
long long c[N], ans[N];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  vector<pair<long long, long long> > p;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    p.push_back({x, i});
  }
  sort(p.begin(), p.end());
  for (int i = 0; i < n; i++) scanf("%lld", &c[i]);
  set<long long> mx;
  for (pair<long long, long long> pp : p) {
    vector<long long> temp;
    int rem = k;
    while (rem-- && !mx.empty()) {
      int curr = *mx.begin();
      mx.erase(mx.begin());
      temp.push_back(curr);
      ans[pp.second] += curr * -1;
    }
    mx.insert(c[pp.second] * -1);
    for (long long i : temp) mx.insert(i);
  }
  for (int i = 0; i < n; i++) printf("%lld ", c[i] + ans[i]);
  return 0;
}
