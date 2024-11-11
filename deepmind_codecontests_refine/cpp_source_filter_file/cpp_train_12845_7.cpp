#include <bits/stdc++.h>
using namespace std;
void domain_expansion_() {
  int n, k;
  cin >> n >> k;
  if (2 * k >= n * (n - 1))
    cout << "no solution";
  else {
    for (int i = 0; i < n; i++) cout << i << " " << i << '\n';
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt = 1;
  while (tt--) domain_expansion_();
  return 0;
}
