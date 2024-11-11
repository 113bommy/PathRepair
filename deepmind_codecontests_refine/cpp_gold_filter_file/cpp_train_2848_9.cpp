#include <bits/stdc++.h>
using namespace std;
int solve(int n, int k) {
  vector<int> seq;
  int inp;
  for (int i = 0; i < n; i++) {
    cin >> inp;
    seq.push_back(inp);
  }
  for (int i = k - 1; i < n; i++) {
    if (seq[i] != seq[k - 1]) {
      return -1;
    }
  }
  int ctr = k - 2, j = 0;
  while (seq[ctr] == seq[k - 1] && ctr >= 0) {
    ctr--;
    j++;
  }
  if (k == 1) {
    return 0;
  }
  return (k - j - 1);
}
int main() {
  int n, k;
  cin >> n >> k;
  int ans = solve(n, k);
  cout << ans;
  return 0;
}
