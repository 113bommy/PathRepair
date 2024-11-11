#include <bits/stdc++.h>
using namespace std;
void timo() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
}
int main() {
  timo();
  long long n, ans = 1, arr[18258];
  arr[0] = 1, arr[1] = 12;
  cin >> n;
  for (int i = 1; i < n; i++) {
    if (i > 1) arr[i] = arr[i - 1] + 12;
    ans += arr[i];
  }
  cout << ans << endl;
  return 0;
}
