#include <bits/stdc++.h>
using namespace std;
vector<long long> type2_mana;
long long n, m, k, x, s;
vector<pair<long long, long long> > type1;
vector<pair<long long, long long> > type2;
long long calcule(long long i, long long j) {
  if (i == -1) {
    if (type2[j].second > s) {
      return LLONG_MAX;
    } else
      return ((n - type2[j].first) * x);
  } else if (j == -1) {
    if (type1[i].second > s) {
      return LLONG_MAX;
    } else
      return (n * (type1[i].first));
  } else {
    if ((type1[i].second + type2[j].second) > s)
      return LLONG_MAX;
    else {
      return ((n - type2[j].first) * (type1[i].first));
    }
  }
}
long long findbest(long long mana) {
  long long tmp =
      distance(type2_mana.begin(),
               upper_bound(type2_mana.begin(), type2_mana.end(), mana));
  if (tmp == k) tmp--;
  while (type2_mana[tmp] > mana && tmp > -1) tmp--;
  return (tmp);
}
int main() {
  cin >> n >> m >> k >> x >> s;
  type1.resize(m);
  type2.resize(k);
  type2_mana.resize(k);
  for (long long i = 0; i < m; i++) cin >> type1[i].first;
  for (long long i = 0; i < m; i++) cin >> type1[i].second;
  for (long long i = 0; i < k; i++) cin >> type2[i].first;
  for (long long i = 0; i < k; i++) {
    cin >> type2[i].second;
    type2_mana[i] = type2[i].second;
  }
  long long res = (x * n);
  for (long long j = 0; j < k; j++) {
    { res = min(calcule(-1, j), res); }
  }
  for (long long i = 0; i < m; i++) {
    res = min(calcule(i, -1), res);
    long long tmp = findbest(s - type1[i].second);
    res = min(calcule(i, tmp), res);
  }
  cout << res << endl;
  return 0;
}
