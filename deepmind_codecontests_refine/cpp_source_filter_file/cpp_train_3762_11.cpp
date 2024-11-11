#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> A(n);
  for (auto &i : A) cin >> i;
  sort(A.begin(), A.end());
  int sum = 0;
  for (int i = 0; i < n / 2; i++) {
    int tmp = A[i] + A[n - i - 1];
    sum += tmp * tmp;
  }
  cout << sum << endl;
  return 0;
}
