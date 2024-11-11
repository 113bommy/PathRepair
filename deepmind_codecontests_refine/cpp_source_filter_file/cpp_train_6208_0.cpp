#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  T = 1;
  while (T--) {
    int N;
    N = 6;
    int* A = new int[N]();
    int sum;
    int i, j;
    for (i = 0; i < N; i++) {
      cin >> A[i];
      sum += A[i];
    }
    int flag = 0;
    if (sum % 2 == 0) {
      sum /= 2;
      sort(A, A + N);
      sum -= A[0];
      for (i = 1; i < N && flag == 0; i++) {
        if (2 * A[i] > sum) break;
        for (j = i + 1; j < N; j++) {
          if (A[i] + A[j] > sum) break;
          if (A[i] + A[j] == sum) {
            flag = 1;
            break;
          }
        }
      }
      if (flag)
        cout << "YES\n";
      else
        cout << "NO\n";
    } else
      cout << "NO\n";
  }
  return 0;
}
