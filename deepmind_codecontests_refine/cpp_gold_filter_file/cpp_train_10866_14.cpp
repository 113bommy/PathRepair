#include <bits/stdc++.h>
using namespace std;
template <typename T>
void afill(T *arr, int size, T val) {
  fill(arr, arr + size, val);
}
long long mod;
double eps = 1e-9;
int n, t, m, q, k;
int incr[1 << 17], decr[1 << 17], arr[1 << 17];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  for (int i = 1; i <= n; ++i) {
    if (arr[i] <= arr[i - 1])
      decr[i] = decr[i - 1] + 1;
    else
      decr[i] = 1;
  }
  for (int i = n; i > 0; --i) {
    if (arr[i] <= arr[i + 1])
      incr[i] = incr[i + 1] + 1;
    else
      incr[i] = 1;
  }
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    int len = r - l + 1, inc = incr[l], dec = decr[r];
    if (inc >= len || dec >= len || (inc + dec >= len))
      cout << "Yes" << '\n';
    else
      cout << "No" << '\n';
  }
}
