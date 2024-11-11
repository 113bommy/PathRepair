#include <bits/stdc++.h>
using namespace std;
map<int, int> bismarck, dp;
int n;
void factorization(int k) {
  for (int i = 2; i * i <= k; i++) {
    if (k % i == 0) {
      int c = 0;
      while (k % i == 0) {
        c++;
        k /= i;
      }
      dp[i] |= 1 << (c - 1);
    }
  }
  if (k > 1) {
    dp[k] |= 1;
  }
}
int grundy(int x) {
  if (x == 0) return 0;
  if (bismarck.count(x)) return bismarck[x];
  int s = 0;
  for (int i = 1, j = 1; i <= x; i <<= 1, j++) {
    s |= 1 << grundy((x >> j) | (x & ((1 << (j - 1)) - 1)));
  }
  int mex = 0;
  for (int i = 1; i <= s; i <<= 1, mex++) {
    if (!(s & i)) break;
  }
  return bismarck[x] = mex;
}
int main() {
  int k, ans = 0;
  cin >> n;
  while (n--) {
    cin >> k;
    factorization(k);
  }
  for (auto t : dp) {
    ans ^= grundy(t.second);
  }
  if (ans)
    cout << "Mojtaba";
  else
    cout << "Arpa";
}
