#include <bits/stdc++.h>
using namespace std;
int q;
long long arr[55];
bool cannot;
bool check(long long st, long long ed, long long m, int n) {
  memset(arr, 0, sizeof arr);
  arr[1] = st;
  if (n == 1) return st == ed;
  long long dif = ed - st * (1ll << n - 2) - (1ll << n - 2);
  if (dif < 0) {
    cannot = true;
    return false;
  }
  long long sum = arr[1];
  for (int i = 2; i <= n; i++) {
    if (i == n) {
      if (dif < m) {
        arr[i] = sum + dif + 1;
        return true;
      }
      return false;
    }
    long long val = (1ll << n - i - 1);
    long long add = min(dif / val, m - 1);
    dif -= add * val;
    arr[i] = sum + add + 1;
    sum += arr[i];
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> q;
  while (q--) {
    long long a, b, m;
    cin >> a >> b >> m;
    bool flag = false;
    cannot = false;
    for (int len = 1; len <= 50; len++) {
      if (cannot) break;
      if (check(a, b, m, len)) {
        cout << len << ' ';
        for (int i = 1; i <= len; i++) cout << arr[i] << ' ';
        cout << endl;
        flag = true;
        break;
      }
    }
    if (!flag) cout << -1 << endl;
  }
  return 0;
}
