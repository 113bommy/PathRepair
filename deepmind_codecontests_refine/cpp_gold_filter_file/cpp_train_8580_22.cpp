#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> V(n);
  for (int i = 0; i < n; ++i) cin >> V[i];
  vector<int> A, B;
  int ans = 1e9;
  for (int i = 1; i <= 1000; i++) {
    int cur = i, cnt = 0;
    vector<int> auxA, auxB;
    for (int j = 0; j < n; ++j) {
      if (cur != V[j]) {
        auxA.push_back(j);
        auxB.push_back(cur);
        cnt++;
      }
      cur += k;
    }
    if (ans > cnt) {
      ans = cnt;
      A = auxA, B = auxB;
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < ans; ++i) {
    if (V[A[i]] > B[i])
      cout << "- " << A[i] + 1 << " " << V[A[i]] - B[i] << "\n";
    else
      cout << "+ " << A[i] + 1 << " " << B[i] - V[A[i]] << "\n";
  }
  return 0;
}
