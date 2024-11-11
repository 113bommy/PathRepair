#include <bits/stdc++.h>
using namespace std;
long long A[100006];
int main() {
  int n, x, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> x;
    A[x]++;
  }
  long long ans = 0;
  for (int i = 0; i <= 10000; i++) {
    for (int j = i; j <= 10000; j++) {
      if (__builtin_popcount(i ^ j) == k) {
        if (i != j)
          ans += A[i] * A[j];
        else
          ans += (A[i] * (A[i] - 1)) / 2;
      }
    }
  }
  cout << ans << endl;
}
