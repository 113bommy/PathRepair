#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
long long n, k = 0, m;
long long a[100010];
void Run() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> m;
    a[i] += a[i - 1] + m;
  }
  long long sum = a[n] / 3;
  long long ans = 0;
  if (a[n] % 3) {
    cout << 0;
    return;
  }
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] == 2 * sum) ans += k;
    if (a[i] == sum) k++;
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  Run();
  return 0;
}
