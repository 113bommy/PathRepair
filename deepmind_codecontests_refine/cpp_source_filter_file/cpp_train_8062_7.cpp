#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, sum = 0, ans = 0;
  cin >> n;
  vector<long> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    sum += v[i];
  }
  sort(v.begin(), v.end());
  ans += sum;
  for (int i = 0; i < n - 1; ++i) {
    ans += sum;
    sum = sum - v[i];
  }
  cout << ans << endl;
}
