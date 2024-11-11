#include <bits/stdc++.h>
using namespace std;
char M[10][10];
int V[10];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> M[i];
  for (int i = 0; i < k; i++) V[i] = i;
  long ans(1e10);
  do {
    long mx(0), mn(1e10);
    for (int i = 0; i < n; i++) {
      long num = 0;
      for (int j = 0; j < k; j++) {
        num = num * 10 + (M[i][V[j]] - '0');
      }
      mx = max(mx, num);
      mn = min(mn, num);
    }
    ans = min(ans, mx - mn);
  } while (next_permutation(V, V + k));
  cout << ans << endl;
}
