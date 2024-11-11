#include <bits/stdc++.h>
using namespace std;
void solveCase() {
  long long n = 0, T = 0;
  cin >> n >> T;
  vector<long long> a(n);
  long long sum = 0;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  long long down = 0, candyCnt = 0;
  while (down != n) {
    candyCnt += (T / sum) * (n - down);
    T -= sum * (T / sum);
    for (long long i = 0; i < n; i++) {
      if (a[i] == -1) continue;
      if (a[i] <= T) {
        candyCnt++;
        T -= a[i];
      } else {
        sum -= a[i];
        a[i] = -1;
        down++;
      }
    }
  }
  cout << candyCnt;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solveCase();
}
