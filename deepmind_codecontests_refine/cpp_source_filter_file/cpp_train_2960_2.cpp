#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long N = 1e6 + 5;
const long long INF = INT_MAX;
const int base = 27;
int a[N], BIT[N], n;
long long gt[N], sumAll[N], not_ex[N], DIV_4, DIV_2;
int pwr(int x, int p) {
  if (!p) return 1;
  long long tmp = pwr(x, p >> 1);
  tmp = (1LL * tmp * tmp) % MOD;
  if (p & 1) return (1LL * tmp * x) % MOD;
  return tmp;
}
void Add(int x, int val) {
  for (; x <= n; x += x & -x) BIT[x] += val;
  return;
}
int Get(int x) {
  int res = 0;
  for (; x; x -= x & -x) res += BIT[x];
  return res;
}
void Pre() {
  gt[0] = not_ex[n + 1] = 1;
  for (int i = 1; i <= n; i++) {
    gt[i] = (gt[i - 1] * i) % MOD;
    sumAll[i] = (((gt[i] * ((i * (i - 1)) % MOD)) % MOD) * DIV_4) % MOD;
  }
  for (int i = n; i; i--) {
    not_ex[i] = (not_ex[i + 1] + (Get(a[i] - 1) * gt[n - i]) % MOD) % MOD;
    Add(a[i], 1);
  }
}
int Calc(int i) {
  if (i == n) return 0;
  long long cnt_less = Get(a[i] - 1);
  long long sum_less =
      (cnt_less * sumAll[n - i] % MOD +
       ((cnt_less * (cnt_less - 1) % MOD * gt[n - i]) % MOD * DIV_2) % MOD) %
      MOD;
  Add(a[i], -1);
  long long sum_equal = (Calc(i + 1) + (cnt_less * not_ex[i + 1]) % MOD) % MOD;
  return (sum_less + sum_equal) % MOD;
}
int main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  DIV_2 = pwr(2, MOD - 2);
  DIV_4 = pwr(4, MOD - 2);
  Pre();
  cout << Calc(1);
  return 0;
}
