#include <bits/stdc++.h>
using namespace std;
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, sum = 0, i, j;
  int A[500005];
  cin >> n;
  for (i = 0; i < n; i++) cin >> A[i];
  sort(A, A + n);
  for (i = 0, j = n - 1; i < j; i++, j--) {
    sum += (A[i] + A[j]) * (A[i] + A[j]);
  }
  cout << sum;
}
