#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> V(n);
  for (int i = 0; i < n; i++) cin >> V[i];
  vector<int> S(k, 0);
  for (int i = 0; i < k; i++) {
    for (int j = i; j < n; j += k) S[i] += V[j];
  }
  int mn = INT_MAX, idx = 0;
  for (int i = 0; i < k; i++) {
    if (S[i] < mn) {
      mn = S[i];
      idx = i;
    }
  }
  cout << idx + 1 << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
