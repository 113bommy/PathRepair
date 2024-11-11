#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n + 1, 1000);
  long long ans = 1000;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i - 1] < a[i]) ans += (ans / a[i - 1]) * (a[i] - a[i - 1]);
  }
  cout << ans << endl;
  return 0;
}