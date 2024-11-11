#include <bits/stdc++.h>
using namespace std;
const int MAX = 205;
int N;
string in;
int A[2][MAX];
int main() {
  cin >> N >> in;
  for (int i = 0; i < 2 * N; i++) {
    A[i % 2][i / 2] = in[i] - '0';
  }
  sort(A[0], A[0] + N);
  sort(A[1], A[1] + N);
  for (int k = 0; k < 2; k++) {
    bool okay = true;
    for (int i = 0; i < N; i++) {
      if (A[0][i] >= A[1][i]) {
        okay = false;
      }
      A[0][i] ^= A[1][i];
      A[1][i] ^= A[0][i];
      A[0][i] ^= A[1][i];
    }
    if (okay) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}
