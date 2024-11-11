#include <bits/stdc++.h>
const int N = 1e6 + 7;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-7;
using namespace std;
int a[N], sum[N], sum1[N], sum2[N];
int main() {
  int n;
  long long ans1 = 0, ans2 = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] < 0) {
      sum1[i] = sum2[i - 1] + 1;
      sum2[i] = sum1[i - 1];
    } else {
      sum1[i] = sum1[i - 1];
      sum2[i] = sum2[i - 1] + 1;
    }
    ans1 += sum1[i], ans2 += sum2[i];
  }
  cout << ans1 << " " << ans2 << "\n";
  return 0;
}
