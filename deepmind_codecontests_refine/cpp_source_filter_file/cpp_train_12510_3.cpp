#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int ans1 = ((3 + 2 * n) + sqrt(8 * n + 4 * k + 9)) / 2;
  long long int ans2 = ((3 + 2 * n) - sqrt(8 * n + 4 * k + 9)) / 2;
  long long int ans = min(ans1, ans2);
  cout << ans2 << endl;
  return 0;
}
