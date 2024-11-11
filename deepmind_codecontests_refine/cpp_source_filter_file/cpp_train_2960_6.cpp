#include <bits/stdc++.h>
using namespace std;
long long arr[1234569] = {0}, a[1234567];
long long ans[1234567] = {0}, fact[1234567];
long long all;
long long n;
long long update(long long ind) {
  while (ind < 1234567) {
    arr[ind]++;
    ind += ind & (-ind);
  }
  return 0;
}
long long query(long long ind) {
  long long sumi = 0;
  while (ind > 0) {
    sumi += arr[ind];
    ind -= ind & (-ind);
  }
  return sumi;
}
long long compute(long long ind) {
  if (ind == n) {
    ans[ind] = 0;
    return 0;
  }
  if (ans[ind] != 0) return ans[ind];
  long long haha = compute(ind + 1) * (n - ind);
  haha %= (1000 * 1000 * 1000 + 7);
  ans[ind] = ((n - ind) * (n - ind + 1) / 2);
  ans[ind] %= (1000 * 1000 * 1000 + 7);
  ans[ind] *= fact[n - ind];
  ans[ind] %= (1000 * 1000 * 1000 + 7);
  ans[ind] += haha;
  ans[ind] %= (1000 * 1000 * 1000 + 7);
  return ans[ind];
}
long long counted(long long val) {
  if (val == n) {
    all = 1;
    return 0;
  }
  update(a[val]);
  long long i = val;
  long long lol = a[val] - 1 - query(a[val] - 1);
  long long answ = counted(val + 1);
  long long haha = lol * ans[val + 1];
  haha %= (1000 * 1000 * 1000 + 7);
  long long value = lol * (lol - 1) / 2;
  value %= (1000 * 1000 * 1000 + 7);
  value *= fact[n - i];
  haha += (value);
  haha %= (1000 * 1000 * 1000 + 7);
  haha += answ;
  haha %= (1000 * 1000 * 1000 + 7);
  haha += all * lol;
  haha %= (1000 * 1000 * 1000 + 7);
  all = lol * fact[n - i] + all;
  all %= (1000 * 1000 * 1000 + 7);
  return haha;
}
int main() {
  std::ios::sync_with_stdio(false);
  long long i;
  fact[0] = 1;
  for (i = 1; i < 1000003; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= (1000 * 1000 * 1000 + 7);
  }
  cin >> n;
  for (i = 1; i < n + 1; i++) {
    cin >> a[i];
  }
  compute(1);
  cout << counted(1) << endl;
}
