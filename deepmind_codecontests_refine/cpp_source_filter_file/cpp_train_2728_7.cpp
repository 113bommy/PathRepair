#include <bits/stdc++.h>
using namespace std;
void mainSolve() {
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for (long long int i = 0; i < n; i++) cin >> v[i];
  ;
  for (int i = 1; i < n; i++) {
    if (v[i] - v[i - 1] >= 2) {
      cout << "YES" << '\n';
      cout << (i) << " " << (i + 1) << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    mainSolve();
  }
  return 0;
}
