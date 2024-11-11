#include <bits/stdc++.h>
using namespace std;
long long l[200010];
int n;
long long teste(long long x) {
  if (x <= 1) return n;
  long long res = 0;
  for (int i = 0; i < n; i++) {
    if (l[i] < x)
      res += x - (l[i] % x);
    else
      res += min(l[i] % x, x - (l[i] % x));
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> l[i];
  long long res = n;
  for (int i = 0; i < 20; i++) {
    int p = rand() * rand() % n;
    long long t = l[p];
    vector<long long> factors;
    for (int j = 2; j <= sqrt(t); j++) {
      while (t % j == 0) {
        t /= j;
        factors.push_back(j);
      }
    }
    if (t > 1) factors.push_back(t);
    t = l[p] - 1;
    for (int j = 2; j <= sqrt(t); j++) {
      while (t % j == 0) {
        t /= j;
        factors.push_back(j);
      }
    }
    if (t > 1) factors.push_back(t);
    t = l[p] + 1;
    for (int j = 2; j <= sqrt(t); j++) {
      while (t % j == 0) {
        t /= j;
        factors.push_back(j);
      }
    }
    if (t > 1) factors.push_back(t);
    sort(factors.begin(), factors.end());
    for (int j = 0; j < (int)factors.size(); j++) {
      if (j and factors[j] == factors[j - 1]) continue;
      res = min(res, teste(factors[j]));
    }
  }
  cout << res << endl;
}
