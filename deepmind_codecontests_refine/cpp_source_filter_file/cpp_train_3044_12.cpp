#include <bits/stdc++.h>
using namespace std;
const int MN = 6e5 + 10;
long long A[MN], B[MN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
      cin >> A[i] >> B[i];
      A[i + N] = A[i];
      B[i + N] = B[i];
    }
    long long res = 0;
    long long men = 1e9;
    for (int i = 2; i <= N + 1; i++) {
      if (A[i] > B[i - 1]) {
        res += A[i] - B[i - 1];
        A[i] -= (A[i] - B[i - 1]);
      }
    }
    for (int i = 2; i <= N + 1; i++) {
      men = min(men, A[i]);
    }
    cout << res + men << "\n";
  }
  return 0;
}
