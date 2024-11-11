#include <bits/stdc++.h>
using namespace std;
long long ans;
long long l, r, n;
pair<long long, long long> a[100];
vector<pair<long long, long long> > pows;
long long res(long long x) {
  vector<pair<long long, long long> > powX;
  pair<long long, long long> a[100];
  if (!x) {
    return x;
  }
  if (x == 1) {
    return pows[0].second;
  }
  if (x == 2) {
    return pows[1].second + res(x - 1);
  }
  long long k = 1;
  long long j = 0;
  for (long long i = x; i >= 1; i /= 2, j++) {
    a[j].second = i % 2;
    a[j].first = i;
  }
  for (long long i = j - 1; i >= 0; i--) {
    a[i].first = k;
    k *= 2;
    powX.push_back(make_pair(a[i].first, a[i].second));
  }
  powX.push_back(make_pair(0, k));
  for (int i = 0; i < pows.size(); i++) {
    if (x == pows[i].first - 1) {
      return (pows[i - 1].second + 2 * res(x / 2));
    } else if (x == pows[i].first) {
      return (pows[i].second + res(x - 1));
    }
  }
  long long sup = 0;
  long long pow = 1;
  for (int i = (int)powX.size() - 2; i >= 0; i--) {
    sup += (powX[i].second != 0 ? res(pow) : 0);
    pow *= 2;
  }
  return sup;
}
int main() {
  scanf("%lld%lld%lld", &n, &l, &r);
  long long k = 1;
  long long j = 0;
  for (long long i = n; i >= 1; i /= 2, j++) {
    a[j].second = i % 2;
    a[j].first = i;
  }
  for (long long i = j - 1; i >= 0; i--) {
    a[i].first = k;
    k *= 2;
    pows.push_back(make_pair(a[i].first, a[i].second));
  }
  pows.push_back(make_pair(0, k));
  cout << res(r) - res(l - 1);
  return 0;
}
