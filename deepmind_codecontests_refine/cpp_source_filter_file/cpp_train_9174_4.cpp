#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, n, k, a[100005];
  vector<int> V;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    V.push_back(a[i + 1] - a[i] - 1);
  }
  sort(V.begin(), V.end());
  k = n;
  for (int i = 0; i < n - k; i++) {
    k += V[i];
  }
  cout << k;
  return 0;
}
