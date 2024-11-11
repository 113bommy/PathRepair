#include <bits/stdc++.h>
using namespace std;
vector<long long> frac(long long a) {
  auto s = sqrt((long double)a);
  vector<long long> res;
  for (long long m = 1; m <= s; m++) {
    if (a % m == 0) {
      res.push_back(m);
    }
  }
  return res;
}
bool isfit(long long a, long long b, long long a2, long long b2) {
  return a <= a2 && b <= b2 || b <= a2 && a <= b2;
}
int main() {
  long long a, b;
  cin >> a >> b;
  auto af = frac(a);
  auto bf = frac(b);
  auto abf = frac(a + b);
  long long minp = (a + b) * 2 + 2;
  for (long long i = 0; i < af.size(); i++) {
    for (long long j = 0; j < abf.size(); j++) {
      if (isfit(af[i], a / af[i], abf[j], (a + b) / abf[j])) {
        minp = min(minp, (abf[j] + (a + b) / abf[j]) * 2);
      }
    }
  }
  for (long long i = 0; i < bf.size(); i++) {
    for (long long j = 0; j < abf.size(); j++) {
      if (isfit(bf[i], a / bf[i], abf[j], (a + b) / abf[j])) {
        minp = min(minp, (abf[j] + (a + b) / abf[j]) * 2);
      }
    }
  }
  cout << minp << endl;
}
