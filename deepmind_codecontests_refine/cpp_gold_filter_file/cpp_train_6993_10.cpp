#include <bits/stdc++.h>
const double PI = 3.1415926535897932384626433;
const int KL = 1e6;
const long long MOD = 1e9 + 7;
using namespace std;
int n, a[KL], q, st[KL], en[KL], fr[KL];
vector<pair<pair<int, int>, int>> vec;
int main() {
  scanf("%d", &n);
  scanf("%d", &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (st[a[i]] == 0) st[a[i]] = i;
    en[a[i]] = i;
    fr[a[i]]++;
  }
  for (int i = 1; i <= 200000; i++) {
    if (fr[i]) {
      vec.push_back({{st[i], en[i]}, fr[i]});
    }
  }
  sort(vec.begin(), vec.end());
  int l = vec[0].first.first, r = vec[0].first.second, mx = vec[0].second,
      sum = 0;
  for (int i = 1; i < vec.size(); i++) {
    if (vec[i].first.first > r) {
      sum += (r - l + 1) - mx;
      l = vec[i].first.first;
      r = vec[i].first.second;
      mx = vec[i].second;
    } else {
      r = max(r, vec[i].first.second);
      mx = max(mx, vec[i].second);
    }
  }
  sum += (r - l + 1) - mx;
  printf("%d\n", sum);
  return 0;
}
