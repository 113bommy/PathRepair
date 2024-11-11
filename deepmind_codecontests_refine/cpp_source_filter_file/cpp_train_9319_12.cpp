#include <bits/stdc++.h>
using namespace std;
const double eps = 1E-8;
const int dx4[4] = {1, 0, 0, -1};
const int dy4[4] = {0, -1, 1, 0};
const int inf = 0x3f3f3f3f;
const int N = 1E3 + 7;
int n;
long long a[N], b[N];
long long sum1[N], sum2[N];
int main() {
  cin >> n;
  sum1[0] = sum2[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum1[i] = sum1[i - 1] ^ a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    sum2[i] = sum2[i - 1] ^ b[i];
  }
  long long ans = -1;
  long long cur;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      long long tmp1 = sum1[j] ^ sum1[i - 1];
      long long tmp2 = sum2[j] ^ sum2[i - 1];
      cur = tmp1 + tmp2;
      if (cur > ans) ans = cur;
    }
  }
  cout << ans << endl;
  return 0;
}
