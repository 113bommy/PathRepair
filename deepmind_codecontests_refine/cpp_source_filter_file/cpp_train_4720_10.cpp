#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e7 + 10;
int n, a, arr[MAX], ans;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> a >> n;
  arr[1] = 1;
  for (int i = 2; i <= 10000000; i++) {
    int u = sqrt(i);
    if (u * u == i) {
      for (int j = 1; j <= (1000000) / i; j++) arr[i * j] = j;
    } else if (!arr[i])
      arr[i] = i;
  }
  for (int i = a; i < a + n; i++) ans += arr[i];
  cout << ans << "\n";
  return 0;
}
