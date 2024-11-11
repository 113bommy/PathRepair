#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  int A[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += A[i];
  }
  int max = 0;
  if (sum <= m)
    max = sum;
  else
    max = m;
  cout << max << "\n";
}
int main() {
  int t;
  cin >> t;
  while (t) {
    t--;
    solve();
  }
  return 0;
}
