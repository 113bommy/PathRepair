#include <bits/stdc++.h>
using namespace std;
long long int n, m, s = 0, dem = 0;
long long int A[1000000], B[1000000];
int main() {
  cin >> n >> m;
  for (long long int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (long long int i = 1; i <= n; i++) {
    s = s + A[i];
    if (s / m != 0) {
      dem = s / m;
      s = s % m;
    }
    B[i] = dem;
    dem = 0;
  }
  for (long long int i = 1; i <= n; i++) {
    cout << B[i];
  }
  return 0;
}
