#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
long long n, m, x, y, k, arr[N], brr[N], crr[N], l[N], r[N], d[N];
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= m; i++) cin >> l[i] >> r[i] >> d[i];
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    crr[x]++;
    crr[y + 1]--;
  }
  for (int i = 1; i <= m; i++) {
    crr[i] += crr[i - 1];
    brr[l[i]] += d[i] * crr[i];
    brr[r[i] + 1] -= d[i];
  }
  for (int i = 1; i <= n; i++) {
    brr[i] += brr[i - 1];
    cout << arr[i] + brr[i] << ' ';
  }
  return 0;
}
