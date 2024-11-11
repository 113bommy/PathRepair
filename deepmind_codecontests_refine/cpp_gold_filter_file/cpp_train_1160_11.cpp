#include <bits/stdc++.h>
using namespace std;
const int inf = 2 * (1e9) + 10;
const long long infl = 2 * (1e18) + 10;
const long long MOD = 998244353;
const long NMAX = 300005;
long long rs;
int n;
int A[NMAX];
void addToAnswer(int l, int r, int isReversed) {
  if (l == r) return;
  if (isReversed)
    rs += 1LL * l * (r - l);
  else
    rs += 1LL * (n - r + 1) * (r - l);
}
int main() {
  cin >> n;
  A[0] = n + 1;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    addToAnswer(min(A[i - 1], A[i]), max(A[i - 1], A[i]), A[i - 1] > A[i]);
  }
  cout << rs << "\n";
  return 0;
}
