#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, L = 14, OO = 0x3f3f3f3f;
const long long M = 10;
const double ESP = 1e-8;
int A[105], B[105];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  int n, k, x;
  cin >> n >> k;
  int mn = OO;
  for (int i = 0; i < n; i++) {
    cin >> x;
    mn = min(mn, x);
    A[x]++;
  }
  int cnt = 0;
  while (mn < k) {
    cnt++;
    int mx = 0;
    for (int i = 0; i <= 100; i++) B[i] = A[i];
    for (int i = 0; i <= 100; i++) {
      if (A[i] && !mx) mx = i;
      if (A[i]) {
        A[i]--;
        B[i]--;
        B[i + 1]++;
      }
    }
    for (int i = 0; i <= 100; i++) A[i] = B[i];
    mn = mx;
  }
  cout << max(0, cnt - 1) << endl;
}
