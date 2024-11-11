#include <bits/stdc++.h>
using namespace std;
bool lucky(long long int a) {
  while (a) {
    if (a % 10 != 4 && a % 10 != 7) return false;
    a /= 10;
  }
  return true;
}
vector<long long int> gen() {
  vector<long long int> res;
  for (int k = 1; k < 11; k++) {
    for (int i = 0; i < (1 << k); i++) {
      long long int a = 0;
      for (int j = 0; j < k; j++) {
        a *= 10;
        if (i & (1 << j))
          a += 4;
        else
          a += 7;
      }
      res.push_back(a);
    }
  }
  sort(res.begin(), res.end());
  return res;
}
vector<int> gen(long long int n, long long int k) {
  long long int c = 1;
  k--;
  for (int i = 0; i < n; i++) c *= (i + 1);
  vector<int> res;
  if (c <= k) return res;
  res.resize(n);
  c /= n;
  for (int i = 0; i < n - 1; i++) {
    res[i] = k / c;
    k %= c;
    c /= (n - i - 1);
  }
  res[n - 1] = 0;
  vector<bool> d(n, false);
  for (int i = 0; i < n; i++) {
    int c = 0;
    while (1) {
      if (!d[c]) {
        if (res[i] == 0) {
          d[c] = true;
          res[i] = c;
          break;
        } else
          res[i]--;
      }
      c++;
    }
  }
  for (int i = 0; i < n; i++) res[i]++;
  return res;
}
int main() {
  long long int n, k;
  cin >> n >> k;
  vector<int> v = gen(min((int)n, 13), k);
  if (v.empty()) {
    cout << -1;
    return 0;
  }
  int res = 0;
  for (int i = 0; i < v.size(); i++) {
    v[i] += (n - v.size());
    if (lucky(i + n - v.size() + 1) && lucky(v[i])) res++;
  }
  if (n > 13) {
    vector<long long int> v2(gen());
    res -= v2.begin() - lower_bound(v2.begin(), v2.end(), n - 13 + 1);
  }
  cout << res;
}
