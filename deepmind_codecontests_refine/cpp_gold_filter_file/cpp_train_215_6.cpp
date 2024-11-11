#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, s;
  cin >> n >> s;
  vector<long long> A(n);
  for (long long i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  long long m = (n - 1) / 2;
  long long score = 0;
  if (A[m] < s) {
    for (long long i = m; i < n; i++) {
      if (A[i] < s) {
        score += (s - A[i]);
      }
    }
  } else {
    for (long long i = m; i >= 0; i--) {
      if (A[i] > s) {
        score += (A[i] - s);
      }
    }
  }
  cout << score;
  return 0;
}
