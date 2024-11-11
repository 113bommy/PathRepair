#include <bits/stdc++.h>
using namespace std;
const int size = 110000, mod = 1000000007, inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int nex[2][4] = {0, 1, 0, -1, 1, 0, -1, 0};
long long cal(long long a, int n) {
  long long s = 1 % mod;
  while (n) {
    if (n & 1) s = (s * a) % mod;
    a = (a * a) % mod;
    n /= 2;
  }
  return s;
}
int n, ar[size];
long long ans;
vector<int> fac, fac2;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> ar[i];
  sort(ar, ar + n);
  for (int i = ar[n - 1]; i >= 1; i--) {
    long long t = 1;
    fac.clear();
    for (int j = 1; j * j <= i; j++)
      if (i % j == 0) {
        fac.push_back(j);
        if (j * j != i) fac.push_back(i / j);
      }
    sort(fac.begin(), fac.end());
    int pre = 0;
    for (int j = 1; j < fac.size(); j++) {
      int num = lower_bound(ar, ar + n, fac[j]) - ar;
      t = t * cal(j, num - pre) % mod;
      pre = num;
    }
    t = t * (cal(fac.size(), n - pre) - cal(fac.size() - 1, n - pre)) % mod;
    ans = (ans + t) % mod;
  }
  cout << (ans + mod) % mod << endl;
  return 0;
}
