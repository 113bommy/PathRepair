#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i;
  cin >> n;
  vector<long long> A;
  for (i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      A.push_back(i);
      A.push_back(n / i);
    }
  }
  sort(A.begin(), A.end());
  long long ans;
  for (i = A.size() - 1; i >= 0; i--) {
    long long cnt = 0;
    long long j = 2;
    while (j * j < A[i]) {
      if (A[i] % (j * j) == 0) {
        cnt++;
      }
      j++;
    }
    if (cnt == 0) {
      ans = A[i];
      break;
    }
  }
  cout << ans;
}
