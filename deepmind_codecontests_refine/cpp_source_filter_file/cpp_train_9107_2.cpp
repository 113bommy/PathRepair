#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const long long INFL = LLONG_MAX;
int main() {
  std::ios::sync_with_stdio(0);
  int n;
  cin >> n;
  int A[n];
  for (int(i) = 0; (i) < (n); (i)++) {
    cin >> A[i];
    while (A[i] % 2 == 0) A[i] /= 2;
    while (A[i] % 3 == 0) A[i] /= 3;
  }
  for (int(i) = (1); (i) <= (n - 1); (i)++) {
    if (A[i] != A[1]) {
      cout << "No" << '\n';
      return 0;
    }
  }
  cout << "Yes" << '\n';
  return 0;
}
