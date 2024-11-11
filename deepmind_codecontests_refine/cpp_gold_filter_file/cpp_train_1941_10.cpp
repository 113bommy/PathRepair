#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  long long count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      count += (a[i] > a[j]);
      count %= 2;
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int L, R;
    cin >> L >> R;
    count += (((R - L + 1) * (R - L)) / 2);
    count %= 2;
    if (count == 0)
      cout << "even";
    else
      cout << "odd";
    cout << endl;
  }
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
