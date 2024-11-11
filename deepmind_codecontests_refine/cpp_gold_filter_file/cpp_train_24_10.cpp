#include <bits/stdc++.h>
int mod = 1000000007;
using namespace std;
vector<int> v[100001];
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (a[0] + a[1] <= a[n - 1]) {
    cout << "1 "
         << "2 " << n << " " << endl;
  } else {
    cout << "-1 " << endl;
  }
}
int main() {
  int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
