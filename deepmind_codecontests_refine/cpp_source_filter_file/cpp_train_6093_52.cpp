#include <bits/stdc++.h>
using namespace std;
template <typename T>
T sqr(T x) {
  return x * x;
}
const int MAXBIT = 32;
int main() {
  int n;
  long long k;
  cin >> n >> k;
  ++n;
  vector<long long> v(n);
  for (int i = 0; i < int(n); i++) {
    cin >> v[i];
  }
  vector<long long> p = v;
  p.resize(2 * n + MAXBIT + 1, 0);
  for (int i = 0; i < int(p.size() - 1); i++) {
    long long sign = p[i] < 0 ? -1 : 1;
    long long a = abs(p[i]);
    p[i + 1] += (a >> 1) * sign;
    p[i] = (a & 1) * sign;
    if (p[i] < 0) {
      p[i] = 1;
      p[i + 1] -= 1;
    }
  }
  long long sign = p.back() < 0 ? -1 : 1;
  if (p.back() < 0) {
    p.back() = 0;
    for (int i = 0; i < int(p.size() - 1); i++) {
      p[i] = !p[i];
    }
    p[0] += 1;
    for (int i = 0; i < int(p.size() - 1); i++) {
      p[i + 1] += p[i] >> 1;
      p[i] = p[i] & 1;
    }
  }
  int total = 0;
  for (int i = 0; i < int(p.size()); i++) {
    total += p[i];
  }
  int ilast = 0;
  int inwnd = 0;
  int res = 0;
  for (int i = 0; i < int(n); i++) {
    while (ilast - i < MAXBIT) {
      inwnd += p[ilast++];
    }
    if (inwnd != total) continue;
    long long val = 0;
    for (int j = 0; j < int(MAXBIT); j++) {
      if (p[i + j]) {
        val |= 1 << j;
      }
    }
    val *= sign;
    val -= v[i];
    if (abs(val) <= k && !(i == n - 1 && val == 0)) ++res;
    inwnd -= p[i];
  }
  cout << res << endl;
  return 0;
}
