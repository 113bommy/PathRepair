#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (A[i] % 2 != 0) {
      A[i]--;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << A[i] << ' ';
  }
  return 0;
}
