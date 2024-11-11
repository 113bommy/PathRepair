#include <bits/stdc++.h>
using namespace std;
void TLEsol();
long long int c1, c2, p1, p2;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) TLEsol();
  return 0;
}
void TLEsol() {
  long long int n, m, sum = 0, q, x, idx;
  cin >> n >> m;
  vector<long long int> arr(n);
  for (auto& a : arr) cin >> a;
  while (m--) {
    cin >> q >> idx;
    if (q == 1) {
      cin >> x;
      arr[idx - 1] = x;
    } else if (q == 2) {
      sum += idx;
    } else {
      cout << arr[idx - 1] + sum << "\n";
    }
  }
}
