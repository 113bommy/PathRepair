#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int solve() {
  int n, altern{0}, consec{0};
  cin >> n;
  string votes;
  cin >> votes;
  for (int i = 0; i < n - 1; ++i) {
    if (votes[i] != votes[i + 1])
      ++altern;
    else
      ++consec;
  }
  return 1 + altern + min(consec, 2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << solve() << endl;
  return 0;
}
