#include <bits/stdc++.h>
using namespace std;
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
bool check_key(map<int64_t, int64_t> m, int64_t key) {
  if (m.find(key) == m.end()) return false;
  return true;
}
vector<int64_t> SieveOfEratosthenes(int64_t n) {
  bool prime[n + 1];
  memset(prime, true, sizeof(prime));
  vector<int64_t> res;
  for (int64_t p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (int64_t i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (int64_t p = 2; p <= n; p++)
    if (prime[p]) res.push_back(p);
  return res;
}
int64_t decimalToOctal(int64_t decimalNumber) {
  int64_t rem, i = 1, octalNumber = 0;
  while (decimalNumber != 0) {
    rem = decimalNumber % 8;
    decimalNumber /= 8;
    octalNumber += rem * i;
    i *= 10;
  }
  return octalNumber;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int64_t t;
  cin >> t;
  map<int64_t, int64_t> x;
  for (int64_t i = 0; i < t; i++) {
    int64_t n1;
    cin >> n1;
    x[i + 1] = n1;
  }
  int64_t t1;
  cin >> t1;
  for (int64_t _ = 0; _ < t1; _++) {
    int64_t n1, n2;
    cin >> n1 >> n2;
    if (n1 == 1) {
      x[2] += x[1] - n2;
      x[1] = 0;
      continue;
    } else if (n1 == t) {
      x[t - 1] += n2 - 1;
      x[t] = 0;
      continue;
    } else {
      x[n1 - 1] += n2 - 1;
      x[n1 + 1] += x[n1] - n2;
      x[n1] = 0;
      continue;
    }
  }
  if (t == 1) {
    cout << x[1] << ("\n");
  } else {
    for (auto thing : x) {
      cout << thing.second << ("\n");
    }
  }
  return 0;
}
