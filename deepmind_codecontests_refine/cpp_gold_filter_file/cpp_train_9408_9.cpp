#include <bits/stdc++.h>
using namespace std;
long long fac[2 * 100000 + 1];
int howMany2[2 * 100000 + 1];
int get2(int n) {
  int& ret = howMany2[n];
  if (ret) return ret;
  while (n) {
    n /= 2;
    ret += n;
  }
  return ret;
}
int divide2(int n) {
  while (n % 2 == 0) n /= 2;
  return n;
}
int n, a[100000], b[100000], m;
int seq[100000 * 2];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  for (int i = 0; i < n; i++) scanf("%d", b + i);
  scanf("%d", &m);
  fac[0] = 1;
  for (int i = 1; i <= 2 * 100000; i++) fac[i] = (fac[i - 1] * divide2(i)) % m;
  for (int i = 0; i < n; i++) seq[i] = a[i];
  for (int i = n; i < 2 * n; i++) seq[i] = b[i - n];
  sort(seq, seq + 2 * n);
  long long ans = 1;
  long long cnt2 = 0;
  int index = 0;
  while (index < 2 * n) {
    int ub = upper_bound(seq, seq + 2 * n, seq[index]) - seq;
    ans *= fac[ub - index];
    ans %= m;
    cnt2 += get2(ub - index);
    index = ub;
  }
  for (int i = 0; i < n; i++)
    if (a[i] == b[i]) cnt2--;
  for (int i = 0; i < cnt2; i++) {
    ans *= 2;
    ans %= m;
  }
  cout << ans;
}
