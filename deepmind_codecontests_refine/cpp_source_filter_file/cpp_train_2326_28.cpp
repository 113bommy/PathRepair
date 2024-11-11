#include <bits/stdc++.h>
using namespace std;
int main() {
  int d;
  cin >> d;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long ans;
  for (int i = 0; i < n - 1; i++) {
    ans += d - a[i];
  }
  cout << ans << endl;
}
