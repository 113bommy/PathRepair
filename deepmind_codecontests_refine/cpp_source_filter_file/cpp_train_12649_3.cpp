#include <bits/stdc++.h>
using namespace std;
int n, A[200010], resp = 1000000010;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  sort(A, A + n);
  for (int i = 0; i < (n - 2) / 2; i++) {
    int x = n - (n - 2) / 2 + i - 1;
    resp = min(resp, A[x] - A[i]);
  }
  if (n == 2) resp = A[1] - A[0];
  cout << resp;
  return 0;
}
