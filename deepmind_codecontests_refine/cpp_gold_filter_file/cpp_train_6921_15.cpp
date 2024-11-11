#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
void acceleration() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  acceleration();
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  long long ans = n;
  long long sum = a[0];
  for (int i = 1; i < n; i++) {
    if (sum > a[i]) {
      ans--;
    } else
      sum += a[i];
  }
  cout << ans;
  return 0;
}
