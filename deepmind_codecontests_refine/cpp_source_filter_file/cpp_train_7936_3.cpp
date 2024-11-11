#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 200;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long b, n;
  cin >> b;
  while (b--) {
    cin >> n;
    long long A[n];
    long long B[N];
    for (int i = 0; i < n; i++) {
      cin >> A[i];
      B[i] = 0;
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
      sum = A[i];
      for (int j = i + 1; j < n; j++) {
        sum += A[j];
        if (sum > 8000) break;
        B[sum] = 1;
      }
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += B[A[i]];
    }
    cout << ans << endl;
  }
}
