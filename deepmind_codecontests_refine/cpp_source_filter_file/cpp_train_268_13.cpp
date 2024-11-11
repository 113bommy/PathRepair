#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y) {
  long long int res = 1;
  while (y > 0) {
    if (y & 1) res = (res * x) % 998244353;
    y = y >> 1;
    x = (x * x) % 998244353;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, m;
  cin >> n >> k >> m;
  long long int a[k];
  long long int sum = 0;
  for (int i = 0; i < k; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a, a + n);
  long long int money = 0;
  for (int i = 0; i <= n; i++) {
    long long int T = 0, tmp = 0, f = 0;
    T += sum * i;
    if (m >= T) tmp += (k * i) + i;
    for (int l = 0; l < k; l++) {
      for (int j = i; j < n; j++) {
        if (T + a[l] > m) {
          f = 1;
          break;
        }
        T += a[l];
        tmp++;
      }
      if (f) break;
    }
    money = max(money, tmp);
  }
  cout << money << endl;
}
