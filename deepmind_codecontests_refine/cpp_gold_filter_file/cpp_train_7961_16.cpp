#include <bits/stdc++.h>
using namespace std;
struct mul {
  long long p;
  vector<int> k;
  vector<long long> value;
  mul() {}
  mul(long long p, int k, long long value) : p(p), k(1, k), value(1, value){};
};
const int M = (int)1e9 + 7;
int main() {
  long long a;
  cin >> a;
  if (a == 1) {
    cout << 1;
    return 0;
  }
  vector<long long> d;
  for (long long i = 1; i * i <= a; ++i) {
    if (a % i) {
      continue;
    }
    d.push_back(i);
    if (i * i != a) {
      d.push_back(a / i);
    }
  }
  sort(d.begin(), d.end());
  vector<mul> P;
  for (int i = 0; i < d.size(); ++i) {
    long long x = d[i] - 1;
    long long p = max(x, 2LL);
    for (long long q = 2; q * q <= x; ++q) {
      if (x % q == 0) {
        p = q;
        break;
      }
    }
    long long q = p;
    int k = 1;
    while (q < x) {
      q *= p;
      ++k;
    }
    if (q == x) {
      P.push_back(mul(p, k, x + 1));
    }
  }
  sort(P.begin(), P.end(), [](mul a, mul b) { return a.p < b.p; });
  if (P.empty()) {
    cout << 0;
    return 0;
  }
  vector<mul> p(2, P[0]);
  for (int i = 1; i < P.size(); ++i) {
    if (p.back().p == P[i].p) {
      p.back().k.push_back(P[i].k[0]);
      p.back().value.push_back(P[i].value[0]);
    } else {
      p.push_back(P[i]);
    }
  }
  map<long long, int> bd;
  for (int i = 0; i < d.size(); ++i) {
    bd[d[i]] = i;
  }
  vector<vector<int> > dp(d.size(), vector<int>(p.size(), 0));
  dp[0][0] = 1;
  for (int i = 0; i < d.size(); ++i) {
    for (int j = 1; j < p.size(); ++j) {
      dp[i][j] = dp[i][j - 1];
      for (int x = 0; x < p[j].k.size(); ++x) {
        long long val = p[j].value[x];
        if (d[i] % val != 0) {
          continue;
        }
        int pos = bd[d[i] / val];
        dp[i][j] += dp[pos][j - 1];
        dp[i][j] %= M;
      }
    }
  }
  cout << dp.back().back() << endl;
  return 0;
}
