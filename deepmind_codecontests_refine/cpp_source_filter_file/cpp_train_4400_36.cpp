#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n;
  vector<int> f(n);
  for (int i = 1; i <= n; i++) {
    cin >> k;
    f[k] = i;
  }
  cout << f[2];
  for (int i = 2; i <= n; i++) {
    cout << " " << f[i];
  }
  cout << endl;
  return 0;
}
