#include <bits/stdc++.h>
using namespace std;
void solve() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &i : A) cin >> i;
  ;
  int sum = accumulate(A.begin(), A.end(), 0);
  int maxi = *max_element(A.begin(), A.end());
  if (maxi > (sum - maxi))
    cout << "T\n";
  else
    cout << ((sum & 1) ? "T\n" : "HL\n");
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int T;
  T = 1;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
