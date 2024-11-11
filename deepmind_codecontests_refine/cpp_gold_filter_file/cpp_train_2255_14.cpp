#include <bits/stdc++.h>
using namespace std;
long long shokti[200005];
long long order[200005];
long long bs(long long num, long long hi) {
  long long lo = 0;
  long long ans = hi;
  while (lo <= hi) {
    long long mid = lo + hi;
    mid /= 2;
    if (shokti[mid] == num) {
      return mid;
    }
    if (shokti[mid] < num) {
      ans = mid;
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return ans;
}
int main() {
  long long i, j, k, l, m, n, o;
  long long testcase;
  long long input, flag, tag, ans;
  long long q;
  cin >> n >> q;
  shokti[0] = 0;
  for (i = 1; i <= n; i++) {
    scanf("%lld", &shokti[i]);
    shokti[i] += shokti[i - 1];
  }
  long long cur = 0;
  flag = 0;
  for (i = 1; i <= q; i++) {
    scanf("%lld", &input);
    flag += input;
    ans = bs(flag, n);
    if (ans == n) {
      ans = 0;
      flag = 0;
    }
    cout << n - ans << endl;
  }
}
