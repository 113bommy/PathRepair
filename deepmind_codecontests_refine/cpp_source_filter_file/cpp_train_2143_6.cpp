#include <bits/stdc++.h>
using namespace std;
long long n, k, pr[100009], HM[100009], res = 0, A[100009];
void put(long long p, long long num, long long ones) {
  if (ones > k || ones + n - p < k) return;
  if (p == n) {
    if (k == ones) {
      for (int i = 1; i <= n; i++) res += HM[(A[i] ^ num)];
    }
    return;
  }
  put(p + 1, 2 * num, ones);
  put(p + 1, 2 * num + 1, ones + 1);
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
    HM[A[i]]++;
  }
  if (k == 0) {
    for (int i = 0; i <= 1000; i++) {
      res += HM[i] * (HM[i] - 1);
    }
    cout << res / 2 << endl;
    return 0;
  }
  put(1, 0, 0);
  put(1, 1, 1);
  cout << res / 2 << endl;
  return 0;
}
