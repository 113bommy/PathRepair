#include <bits/stdc++.h>
using namespace std;
int sz(int A[], int a, int b) {
  int z = 0;
  for (int x = 0; x < a; x++)
    if (A[x] >= b) z++;
  return z;
}
int main() {
  int D[10];
  int k;
  int n;
  cin >> k;
  int A[1000];
  for (int o = 0; o < k; o++) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> A[i];
    }
    for (int s = n; s >= 1; s--) {
      if (sz(A, n, s) >= s) {
        D[o] = s;
        break;
      }
    }
  }
  for (int o = 0; o < k; o++) cout << D[o] << "\n";
}
