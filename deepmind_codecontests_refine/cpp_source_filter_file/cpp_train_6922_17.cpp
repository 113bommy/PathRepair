#include <bits/stdc++.h>
using namespace std;
int A[100011], B[100011], NA, NB, K, M;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> NA >> NB >> K >> M;
  for (int i = 0; i < NA; ++i) cin >> A[i];
  for (int i = 0; i < NB; ++i) cin >> B[i];
  int lastA = A[K - 1], firstB = B[0];
  for (int i = 0; i < NB; ++i) {
    if (lastA < B[i]) {
      if ((NB - 1) - i >= M) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
}
