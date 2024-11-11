#include <bits/stdc++.h>
long long num[200002];
using namespace std;
int main() {
  int n;
  cin >> n;
  int maxn = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &num[i]);
    if (i == 0)
      ans = abs(num[i]);
    else
      ans += abs(num[i] - num[i - 1]);
  }
  cout << ans << endl;
  return 0;
}
