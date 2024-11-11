#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
vector<long long> sum_perm(1000004), f(1000004);
class Fenwick {
  vector<int> a;

 public:
  Fenwick() { a.resize(1000004); }
  void add(int x, int delta = 1) {
    for (; x < a.size(); x = (x | (x + 1))) {
      a[x] += delta;
    }
  }
  int sum(int x) const {
    int res = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1) {
      res += a[x];
    }
    return res;
  }
};
void PreCalc() {
  sum_perm[0] = 0;
  sum_perm[1] = 0;
  f[0] = 1;
  f[1] = 1;
  for (long long j = 2; j < 1000004; ++j) {
    long long i = j % mod;
    f[j] = (f[j - 1] * i) % mod;
    long long a = (i * (i - 1) / 2) % mod;
    a *= f[j - 1];
    a %= mod;
    sum_perm[j] = (i * sum_perm[j - 1] + a) % mod;
  }
}
Fenwick F;
long long get_ans(long long i, const vector<int> &perm,
                  long long &num_of_perm) {
  long long n = perm.size();
  if (i == n - 1) {
    num_of_perm = 1;
    return 0;
  }
  long long a = perm[i] - F.sum(perm[i]);
  long long k = (a - 1) % mod, l = (a - 2) % mod;
  F.add(perm[i]);
  long long delta = get_ans(i + 1, perm, num_of_perm);
  delta += ((k * sum_perm[n - i - 1]) % mod +
            (((k * l / 2) % mod) * f[n - i]) % mod);
  delta += (k * num_of_perm) % mod;
  num_of_perm += k * f[n - i - 1];
  num_of_perm %= mod;
  return delta % mod;
}
int main() {
  PreCalc();
  int n;
  scanf("%d", &n);
  vector<int> perm(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &perm[i]);
  }
  long long num_of_perm = 0;
  cout << get_ans(0, perm, num_of_perm) << "\n";
}
