#include <bits/stdc++.h>
using namespace std;
long long n, big, ans = LLONG_MAX;
vector<long long> vec[101234];
long long check(long long z) {
  long long res = 0, tot = vec[0].size();
  vector<long long> ret;
  for (long long i = 1; i <= big; i++) {
    long long now = 0, siz = vec[i].size(), poi = siz;
    for (long long j = 0; j < siz; j++) {
      if (poi < z) {
        for ("lyc"; j < siz; j++) ret.push_back(vec[i][j]);
        break;
      }
      res += vec[i][j];
      tot++, poi--;
    }
  }
  if (tot >= z)
    return res;
  else {
    sort(ret.begin(), ret.end());
    long long siz = ret.size();
    for (long long i = 0; i < siz; i++) {
      res += ret[i];
      tot++;
      if (tot >= z) return res;
    }
    return res;
  }
}
int main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    long long gru, rmb;
    scanf("%lld%lld", &gru, &rmb);
    vec[gru].push_back(rmb);
    big = max(big, gru);
  }
  for (long long i = 1; i <= big; i++) sort(vec[i].begin(), vec[i].end());
  if (check(0) == 0) {
    printf("0");
    return 0;
  }
  long long l = 1, r = big;
  while (l <= r) {
    long long lmid = l + (r - l) / 3, rmid = r - (r - l) / 3;
    long long tmp1 = check(lmid), tmp2 = check(rmid);
    if (tmp1 > tmp2)
      l = lmid + 1;
    else
      r = rmid - 1;
    ans = min(ans, min(tmp1, tmp2));
  }
  printf("%lld", ans);
  return 0;
}
