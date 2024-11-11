#include <bits/stdc++.h>
using namespace std;
int a[100005], x[100005], y[100005];
void solve() {
  long long int n;
  cin >> n;
  vector<int> arr;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    arr.push_back(x);
  }
  for (long long int i = 0; i < n - 1; i++) {
    cout << arr[(i + 1) % n] << " ";
  }
  cout << arr[0] << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return (0);
}
