#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int ar[maxn + 5];
long long n;
bool sama_semua() {
  for (int i = 2; i <= n; i++) {
    if (ar[i] != ar[1]) {
      return false;
    }
  }
  return true;
}
list<pair<int, long long> > sen;
int main() {
  long long m, k, has;
  scanf("%lld %lld %lld", &n, &k, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", ar + i);
  }
  if (sama_semua()) {
    printf("%lld\n", (n * m) % k);
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (!sen.empty() && ar[i] == sen.back().first) {
      sen.back().second++;
    } else {
      sen.push_back(make_pair(ar[i], 1));
    }
    if (sen.back().second == k) {
      sen.pop_back();
    }
  }
  has = 0;
  while (sen.size() > 1) {
    if (sen.front().first != sen.back().first) {
      for (pair<int, long long> x : sen) {
        has += (x.second * m);
      }
      break;
    }
    if (sen.front().second + sen.back().second == k) {
      has += k;
      sen.pop_front();
      sen.pop_back();
    } else {
      if (sen.front().second + sen.back().second == k) {
        has -= (k * m);
      }
      for (pair<int, long long> x : sen) {
        has += (x.second * m);
      }
      break;
    }
  }
  if ((int)sen.size() == 1) {
    if ((sen.back().second * m) % k == 0) {
      has = 0;
    } else {
      has += ((sen.back().second * m) % k);
    }
  }
  printf("%lld\n", has);
}
