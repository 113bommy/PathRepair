#include <bits/stdc++.h>
using namespace std;
long long fib[100], A[100], B[100];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, n, najwieksza = 2;
  fib[0] = 1;
  fib[1] = 1;
  for (; fib[najwieksza - 1] + fib[najwieksza - 2] <= 1e18; najwieksza++)
    fib[najwieksza] = fib[najwieksza - 1] + fib[najwieksza - 2];
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> miejsca;
    for (int i = najwieksza - 1; i > 0; i--)
      if (fib[i] <= n) {
        n -= fib[i];
        miejsca.push_back(i);
      }
    miejsca.push_back(0);
    reverse(miejsca.begin(), miejsca.end());
    A[1] = 1;
    B[1] = (miejsca[1] - 1) / 2;
    for (int i = 2; i < (int)miejsca.size(); i++) {
      A[i] = A[i - 1] + B[i - 1];
      B[i] = A[i - 1] * ((miejsca[i] - miejsca[i - 1] - 1) / 2) +
             B[i - 1] * ((miejsca[i] - miejsca[i - 1]) / 2);
    }
    cout << A[miejsca.size() - 1] + B[miejsca.size() - 1] << "\n";
  }
  return 0;
}
