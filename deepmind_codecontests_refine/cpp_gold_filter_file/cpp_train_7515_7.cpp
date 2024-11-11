#include <bits/stdc++.h>
using namespace std;
long long b[1000005];
long long a[1000005];
long long x;
bool ntp[1000005];
int n;
long long calc(int l, int r, long long ovrl, long long ovrr) {
  long long w = 0, qwq;
  long long ret = 0;
  long long tmp1, tmp2;
  tmp1 = a[l], tmp2 = a[r];
  a[l] = ovrl;
  a[r] -= ovrr;
  for (int i = l; i <= r; i++) {
    w += a[i];
    if (w + w >= x) {
      qwq = i;
      break;
    }
  }
  for (int i = l; i < qwq; i++) ret += ((long long)(qwq - i)) * a[i];
  for (int i = qwq + 1; i <= r; i++) ret += ((long long)(i - qwq)) * a[i];
  a[l] = tmp1, a[r] = tmp2;
  return ret;
}
long long work() {
  long long sum = 0;
  long long ans = 0;
  long long lst = 0, sy = 0;
  for (int i = 1; i <= n; i++) a[i] = b[i] % x;
  for (int i = 1; i <= n; i++) {
    sum += a[i];
    if (sum >= x) {
      sum -= x;
      ans += calc(lst, i, sy, sum);
      sy = sum;
      lst = i;
    }
  }
  return ans;
}
int main() {
  scanf("%d", &n);
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
    sum += b[i];
  }
  if (sum == 1) {
    cout << -1;
    return 0;
  } else {
    long long Ans = 900000000000000000ll;
    long long qwq = sum;
    for (long long i = 2; i * i <= sum; i++) {
      if (qwq % i == 0) {
        qwq /= i;
        x = i;
        Ans = min(Ans, work());
      }
    }
    if (qwq != 1) {
      x = qwq;
      Ans = min(Ans, work());
    }
    cout << Ans;
  }
  return 0;
}
