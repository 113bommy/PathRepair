#include <bits/stdc++.h>
using namespace std;
char a[1000][1010];
int solve() {
  int n, m;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  for (int i = 0; i < n; ++i) {
    cout << a[i];
  }
  cout << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n = 1;
  cin >> n;
  while (n--) {
    solve();
  }
  return 0;
}
