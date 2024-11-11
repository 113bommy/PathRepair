#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &i : a) cin >> i;
  sort(a.rbegin(), a.rend());
  long long ans = 0;
  for (int i = 1; i < n; i++) {
    ans += a(i / 2);
  }
  cout << ans << endl;
  return 0;
}