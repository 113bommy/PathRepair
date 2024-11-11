#include <bits/stdc++.h>
using namespace std;
int n, n1, n2, mn, mx;
int A[100001];
int main() {
  cin >> n >> n1 >> n2;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(A, A + n);
  mn = min(n1, n2);
  mx = max(n1, n2);
  double s1 = 0;
  double s2 = 0;
  int nr = 0;
  int k = 0;
  for (int i = n - 1; k < mn; i--, k++) {
    s1 = s1 + A[i];
    nr = i;
  }
  k = 0;
  for (int i = nr - 1; k < mx; i--, k++) {
    s2 = s2 + A[i];
  }
  cout << s1 / mn + s2 / mx << endl;
  return 0;
}
