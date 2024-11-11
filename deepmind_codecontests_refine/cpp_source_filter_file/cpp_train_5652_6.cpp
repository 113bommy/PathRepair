#include <bits/stdc++.h>
using namespace std;
void solve(int n) {
  cout << "YES\n";
  cout << n - 2 << endl;
  for (int i = 1; i + 2 <= n; i += 2)
    cout << i << " " << i + 1 << " " << i + 2 << endl;
  for (int i = 1; i + 2 <= n - 1; i += 2)
    cout << i << " " << i + 1 << " " << n << endl;
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  if (n % 2 == 0) {
    int x = 0;
    for (int i = 0; i < n; i++) x = x ^ a[i];
    if (x)
      solve(n - 1);
    else
      cout << "NO\n";
  } else
    solve(n);
  return 0;
}
