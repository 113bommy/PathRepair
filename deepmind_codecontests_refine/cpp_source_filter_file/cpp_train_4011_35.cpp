#include <bits/stdc++.h>
using namespace std;
void print1d(const vector<long long int>& vec) {
  for (auto val : vec) {
    cout << val << " ";
  }
  cout << endl;
}
void print2d(const vector<vector<long long int>>& vec) {
  for (auto row : vec) {
    for (auto val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
}
void xoreq(long long int S, long long int X) {
  long long int A = (S - X) / 2;
  if (A < 0 or (S - X) % 2 != 0 or (X & A) != 0) {
    cout << 0 << endl;
    return;
  }
  long long int tmp = X;
  long long int set_bit_xor = 0;
  while (tmp) {
    set_bit_xor += (tmp & 1);
    tmp = tmp >> 1;
  }
  long long int ans = (1 << set_bit_xor);
  if (A == 0) {
    ans -= 2;
  }
  cout << ans << endl;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int S, X;
  cin >> S >> X;
  xoreq(S, X);
  return 0;
}
