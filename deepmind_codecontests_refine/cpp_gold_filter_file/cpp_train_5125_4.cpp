#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
int A[MAXN];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int N, D;
    cin >> N >> D;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < A[i]; ++j) {
        D -= i;
        if (D < 0) break;
        ++A[0];
      }
    }
    cout << A[0] << endl;
  }
  return 0;
}
