#include <bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int> > > va, vb;
int a[2020], b[2020];
pair<int, int> ans[2];
int main() {
  int na, nb, i, j, tot = 0;
  long long sum = 0;
  cin >> na;
  for ((i) = 0; i < (na); i++) {
    scanf("%d", a + i);
    sum += a[i];
    for (j = 0; j < i; j++) va.push_back({a[j] + a[i], {j, i}});
  }
  cin >> nb;
  for ((i) = 0; i < (nb); i++) {
    scanf("%d", b + i);
    sum -= b[i];
    for (j = 0; j < i; j++) vb.push_back({b[j] + b[i], {j, i}});
  }
  long long mn = abs(sum);
  long long dif;
  for ((i) = 0; i < (na); i++) {
    for (j = 0; j < nb; j++) {
      dif = sum - 2 * a[i] + 2 * b[j];
      if (mn > abs(dif)) {
        mn = abs(dif);
        tot = 1;
        ans[0] = {i, j};
      }
    }
  }
  sort((va).begin(), (va).end());
  sort((vb).begin(), (vb).end());
  for (i = 0, j = 0; i < va.size() && j < vb.size();) {
    dif = sum - 2ll * va[i].first + 2ll * vb[j].first;
    if (mn > abs(dif)) {
      mn = abs(dif);
      tot = 2;
      ans[0] = {va[i].second.first, vb[j].second.first};
      ans[1] = {va[i].second.second, vb[j].second.second};
    }
    if (dif > 0)
      i++;
    else
      j++;
  }
  printf("%I64d\n", mn);
  printf("%d\n", tot);
  for ((i) = 0; i < (tot); i++)
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
}
