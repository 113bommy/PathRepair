#include <bits/stdc++.h>
using namespace std;
bool check(int l, int pre[], int a, int b, int k) {
  for (int i = a; i <= b - l + 1; i++) {
    int j = i + l - 1;
    if (pre[j] - pre[i - 1] < k) return false;
  }
  return true;
}
int main() {
  int a, b, k;
  cin >> a >> b >> k;
  vector<bool> sieve(b + 1, 0);
  for (int i = 2; i * i <= b; i++) {
    if (i < 2) sieve[i] = true;
    if (!sieve[i])
      for (int j = 2; j * i <= b; j++) sieve[i * j] = true;
  }
  int pre[b + 1];
  pre[0] = 0;
  for (int i = 1; i <= b; i++) {
    if (!sieve[i])
      pre[i] = 1 + pre[i - 1];
    else
      pre[i] = pre[i - 1];
  }
  int start = 1, end = b - a + 1, ans = INT_MAX, l;
  while (start <= end) {
    l = (start + end) / 2;
    if (check(l, pre, a, b, k)) {
      ans = min(ans, l);
      end = l - 1;
    } else
      start = l + 1;
  }
  if (ans == INT_MAX)
    cout << "-1" << endl;
  else
    cout << ans << endl;
  return 0;
}
