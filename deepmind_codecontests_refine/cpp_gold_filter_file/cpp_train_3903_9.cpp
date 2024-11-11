#include <bits/stdc++.h>
using namespace std;
int n;
int solve(long long i) {
  if (i > n) return 0;
  return 1 + solve(i * 10 + 4) + solve(i * 10 + 7);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cout << solve(0) - 1;
  return 0;
}
