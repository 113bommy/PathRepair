#include <bits/stdc++.h>
using namespace std;
long long sr(long long v) {
  long long s = sqrt(v);
  for (long long i = s - 1; i < s + 2; i++) {
    if (i * i <= v) {
      if ((i + 1) * (i + 1) > v) return i;
    }
  }
  return s;
}
vector<pair<long long, long long> > fc(long long v) {
  vector<pair<long long, long long> > res;
  for (long long i = 1; i * i <= v; i++) {
    if (!(v % i)) {
      res.push_back({i, v / i});
    }
  }
  return res;
}
long long mg(long long a, long long b) {
  vector<pair<long long, long long> > f[2] = {fc(a), fc(b)};
  long long tot = a + b;
  for (long long i = sr(tot); i >= 1; i--) {
    if (!(tot % i)) {
      for (int j = 0; j < 2; j++) {
        auto it = lower_bound(f[j].begin(), f[j].end(),
                              pair<long long, long long>(i, 0));
        if (it == f[j].begin()) continue;
        long long val = (it - 1)->second;
        if ((tot / i) >= val) {
          return i * 2 + (tot * 2 / i);
        }
      }
    }
  }
  return tot * 2 + 2;
}
int main() {
  long long a, b;
  cin >> a >> b;
  cout << mg(a, b) << '\n';
}
