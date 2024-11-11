#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n, a, b;
  cin >> n >> a >> b;
  __typeof(n) ar[n];
  for (__typeof(n) i = 0; i < n; i++) cin >> ar[i];
  sort(ar, ar + n);
  if (a > b) {
    cout << n;
    return;
  }
  int i = 0;
  while (ar[i] < a) i++;
  cout << (i + 1) / 2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
