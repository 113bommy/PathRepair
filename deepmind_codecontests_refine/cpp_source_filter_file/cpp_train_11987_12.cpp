#include <bits/stdc++.h>
using namespace std;
int n, k, F[200005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= k; i++) F[i] = i;
  if (n > k * (k - 1)) {
    cout << "NO";
    exit(0);
  }
  cout << "YES\n";
  while (n) {
    for (int i = 1; i <= k; i++) {
      F[i]++;
      if (F[i] == k + 1) F[i] = 1;
      cout << i << " " << F[i] << "\n";
      n--;
      if (n == 0) break;
    }
  }
}
