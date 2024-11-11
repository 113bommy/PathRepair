#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<long long int, long long int> &a,
         const pair<long long int, long long int> &b) {
  return a.second < b.second;
}
int main() {
  long long int n, k, ai, bi, total = 0, ans = 0;
  vector<long long int> a;
  vector<pair<long long int, long long int> > ab;
  map<long long int, long long int> jobs;
  scanf("%lld %lld", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &ai), a.push_back(ai), jobs[ai]++;
    if (jobs[ai] == 1) total++;
  }
  for (int i = 0; i < n; i++)
    scanf("%d", &bi), ab.push_back(make_pair(a[i], bi));
  sort(ab.begin(), ab.end(), cmp);
  total = k - total;
  for (int i = 0; i < n; i++) {
    if (jobs[ab[i].first] > 1 && total > 0) {
      ans += ab[i].second;
      total--;
      jobs[ab[i].first]--;
    }
  }
  printf("%lld", ans);
  return 0;
}
