#include <bits/stdc++.h>
using namespace std;
int arr[100009];
int mid[100009];
int n = 0;
int ma = 0;
int ans = 0;
int k;
int fun(int a, int b) {
  if (a >= k && a < k * 2) return 0;
  ans += mid[a * 2] - (arr[a * 2 - 1] + b);
  fun(a * 2, mid[a * 2]);
  ans += mid[a * 2 + 1] - (arr[a * 2] + b);
  fun(a * 2 + 1, mid[a * 2 + 1]);
  return 0;
}
int main() {
  cin >> n;
  int m = pow(2, n + 1) - 2;
  k = pow(2, n);
  for (int i = 1; i <= m; i++) cin >> arr[i];
  for (int i = 1; i < k * 2; i++) mid[i] = 100009;
  for (int i = k; i < k * 2; i++) {
    int ma1 = 0;
    int po = i;
    while (po > 0) {
      ma1 += po - 1;
      po /= 2;
    }
    ma = max(ma, ma1);
  }
  for (int i = k; i < k * 2; i++) {
    int po = i;
    int num = ma;
    while (po > 0) {
      mid[po] = min(mid[po], num);
      num -= arr[po - 1];
      po /= 2;
    }
  }
  fun(1, 0);
  cout << ans << endl;
  return 0;
}
