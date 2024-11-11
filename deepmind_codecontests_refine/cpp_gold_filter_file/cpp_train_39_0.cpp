#include <bits/stdc++.h>
using namespace std;
set<long long> kharab = {1,  2,   3,   5,   6,   9,   10,  13,  17,  31,  34,
                         37, 38,  41,  43,  45,  46,  49,  50,  53,  57,  71,
                         83, 111, 123, 391, 403, 437, 457, 471, 483, 511, 523};
long long a[6];
vector<long long> D[43];
void f(long long n) {
  if (kharab.find(n) != kharab.end()) {
    fill(a, a + 6, -1);
    return;
  }
  if (n < 8) {
    a[0] = n;
    return;
  }
  for (long long i = 0; i <= 42; i++) {
    if ((!D[i].size() || ~D[i].back()) && i % 10 == n % 10 &&
        kharab.find((n - i) / 10) == kharab.end()) {
      f((n - i) / 10);
      for (long long j = 0; j < 6; j++) a[j] *= 10;
      for (long long j = 0; j < D[i].size(); j++) a[j] += D[i][j];
      return;
    }
  }
}
int32_t main() {
  long long t;
  cin >> t;
  D[4].push_back(4);
  D[7].push_back(7);
  for (long long i = 1; i <= 42; i++) {
    if (i == 4 || i == 7) continue;
    if (kharab.find(i) != kharab.end() || i == 40) {
      D[i].push_back(-1);
      continue;
    }
    if (D[i - 4].size() < 6 && (!D[i - 4].size() || ~D[i - 4].back())) {
      D[i] = D[i - 4];
      D[i].push_back(4);
    } else {
      D[i] = D[i - 7];
      D[i].push_back(7);
    }
  }
  while (t--) {
    long long n;
    cin >> n;
    fill(a, a + 6, 0);
    f(n);
    if (~a[0])
      for (long long i = 0; i < 6; i++) cout << a[i] << ' ';
    else
      cout << -1;
    cout << '\n';
  }
}
