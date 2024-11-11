#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n, Q, t, x, y;
int A[N], T[N], P[N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> A[i];
  cin >> Q;
  for (int i = 1; i < Q; i++) {
    cin >> t;
    if (t == 1) {
      cin >> x >> y;
      x--;
      A[x] = y;
      T[x] = i;
    } else {
      cin >> x;
      P[i] = x;
    }
  }
  for (int i = Q + 1; i >= 0; i--) P[i] = max(P[i], P[i + 1]);
  for (int i = 0; i < n; i++) cout << max(A[i], P[T[i]]) << " ";
}
