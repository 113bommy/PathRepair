#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string A[2];
  cin >> A[0] >> A[1];
  int N = (int)A[0].size();
  sort(A[0].begin(), A[0].end());
  sort(A[1].begin(), A[1].end(), greater<char>());
  string ret(N, ' ');
  int l = 0, r = N - 1;
  int a1 = 0, b1 = 0;
  int a2 = (int)ceil((double)N / 2.0), b2 = (int)(N / 2);
  --a2, --b2;
  for (int i = (0); i < (N); i++) {
    if (!(i & 1)) {
      if (A[0][a1] < A[1][b1]) {
        ret[l++] = A[0][a1++];
      } else {
        ret[r--] = A[0][a2--];
      }
    } else {
      if (A[1][a1] > A[0][b1]) {
        ret[l++] = A[1][b1++];
      } else {
        ret[r--] = A[1][b2--];
      }
    }
  }
  cout << ret << "\n";
  return 0;
}
